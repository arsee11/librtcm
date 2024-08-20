#include <iostream>
#include <memory>

#include "audio/aec.h"
#include "wave.h"

using namespace std;


int main(int argc, char** argv)
{
    if( argc <4 ){
        cout<<"usage: cmd [near-end wav file] [far-end wav file] [output wav file]\n";
        return 1;
    }

    const char* nearf = argv[1];
    const char* farf = argv[2];
    const char* outf = argv[3];

    size_t sr = 16000;
    size_t nchn = 1;
    auto aec = rtcm::EchoCanceller::create(sr, nchn);
    

    WaveFile* fpn = wave_open(nearf, WAVE_OPEN_READ);
    if(fpn == nullptr){
        cout<<"wave file for reading open failed!\n";
        return 1;
    }

    WaveFile* fpf = wave_open(farf, WAVE_OPEN_READ);
    if(fpf == nullptr){
        cout<<"wave file for reading open failed!\n";
        return 1;
    }

    WaveFile* fpo = wave_open(outf, WAVE_OPEN_WRITE);
    if(fpo == nullptr){
        cout<<"wave file for writing open failed!\n";
        return 1;
    }
    wave_set_format(fpo, WAVE_FORMAT_PCM);
    wave_set_num_channels(fpo, 1);
    wave_set_sample_rate(fpo, 16000);
    wave_set_sample_size(fpo, 2);

    // where,
    //   - t_analyze is the time a frame is passed to processFarEnd() and
    //     t_render is the time the first sample of the same frame is rendered by
    //     the audio hardware.
    //   - t_capture is the time the first sample of a frame is captured by the
    //     audio hardware and t_process is the time the same frame is passed to
    //     processNearEnd().
    int t_render = 10;
    int t_analyze = 0;
    int t_process = 0;
    int t_capture = 0;
    int delay = (t_render - t_analyze) + (t_process - t_capture);
    aec->setAudioBufferDelay(delay);
    while(true){
        int16_t buff[160];
        size_t frame_size = wave_read(fpf, buff, 160);
        if(frame_size != 160 ){
                break;
        }
        aec->analyzeFarEnd(buff);

        int16_t bufn[160];
        frame_size = wave_read(fpn, bufn, 160);
        if(frame_size != 160 ){
                break;
        }

 
        int16_t dst[160];
        aec->processNearEnd(bufn, dst);
        wave_write(fpo, dst, frame_size);
    }

    cout<<"finished.\n";
    wave_close(fpn);
    wave_close(fpf);
    wave_close(fpo);

    return 0;
}

