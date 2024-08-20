#include <iostream>
#include <memory>

#include "audio/ns.h"
#include "wave.h"

using namespace std;


int main(int argc, char** argv)
{
    if( argc <3 ){
        cout<<"usage: cmd [input wav file] [output wav file]\n";
        return 1;
    }

    const char* inf = argv[1];
    const char* outf = argv[2];

    size_t sr = 16000;
    size_t nchn = 1;
    auto ns = rtcm::NoiseSuppressor::create(rtcm::SuppressionLevel::k12dB, sr, nchn);
    

    WaveFile* fp1 = wave_open(inf, WAVE_OPEN_READ);
    if(fp1 == nullptr){
        cout<<"wave file for reading open failed!\n";
        return 1;
    }

    WaveFile* fp2 = wave_open(outf, WAVE_OPEN_WRITE);
    wave_set_format(fp2, WAVE_FORMAT_PCM);
    wave_set_num_channels(fp2, 1);
    wave_set_sample_rate(fp2, 16000);
    wave_set_sample_size(fp2, 2);
    if(fp2 == nullptr){
        cout<<"wave file for writing open failed!\n";
        return 1;
    }

    while(true){
        int16_t buf[160];
        size_t frame_size = wave_read(fp1, buf, 160);
        if(frame_size != 160 ){
                break;
        }
        int16_t dst[160];
        ns->process(buf, dst);
        wave_write(fp2, dst, frame_size);
    }

    cout<<"finished.\n";
    wave_close(fp1);
    wave_close(fp2);
    
    return 0;
}

