g++ ns_demo.cpp -g\
        -I ../ -I libwave/include/ \
        -L libwave/lib/ -lwave \
        -L ../lib/ -lrtcm \
        -Wl,-rpath ../lib/ -Wl,-rpath libwave/lib/

