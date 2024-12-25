#include <iostream>
#include <fstream>
#include <memory>

#include "audio_c/audio_d.h"

using namespace std;


int main(int argc, char** argv)
{
    if( argc <3 ){
        cout<<"usage: cmd [input pcmu file] [output pcm file]\n";
        return 1;
    }

    const char* inf = argv[1];
    const char* outf = argv[2];

    auto decoder = rtcm::AudioDecoderFactory::create("PCMU/8000/1");
    if(decoder == nullptr){
        cout<<"PCMU decoder create failed!\n";
        return 1;
    }


    fstream fin(inf, std::ios::binary|std::ios::in);
    if( !fin.good()){
        cout<<"input file open failed!\n";
        return 1;
    }

    fstream fo(outf, std::ios::binary|std::ios::out);
    if( !fo.good()){
        cout<<"output file open failed!\n";
        return 1;
    }

    while(true){
        uint8_t buf[80];
        if( !fin.read((char*)buf, 80) ){
            cout <<"finished\n";
            break;
        }

        int16_t out[80];
        rtcm::AudioDecoder::SpeechType st;
        int n = decoder->decode(buf, 80, 8000, 160, out, &st);
        cout<<"decoder return: n="<<n<<" speech_type="<<st<<endl;
        fo.write((char*)out, 160);
    }
    

    fin.close();
    fo.close();
    return 0;
}

