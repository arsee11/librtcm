#include <iostream>
#include <memory>

#include "audio_p/vad.h"
#include "wave.h"

using namespace std;


int main(int argc, char** argv)
{
    if( argc <2 ){
        cout<<"usage: cmd [input wav file]\n";
        return 1;
    }

    const char* inf = argv[1];

    size_t sr = 16000;
    auto vad = rtcm::VadProcessor::create(rtcm::VadModel::Three);
    

    WaveFile* fp1 = wave_open(inf, WAVE_OPEN_READ);
    if(fp1 == nullptr){
        cout<<"wave file for reading open failed!\n";
        return 1;
    }

    const int n_read=1600*2;
    while(true){
        int16_t buf[n_read];
        size_t frame_size = wave_read(fp1, buf, n_read);
        if(frame_size != n_read){
                break;
        }
        bool is_activity = vad->process(buf, frame_size, sr);
        cout << "vad:" << is_activity << endl;
    }

    cout<<"finished.\n";
    wave_close(fp1);
    
    return 0;
}

