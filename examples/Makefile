#g++ ns_demo.cpp -g\
#        -I ../ -I libwave/include/ \
#        -L libwave/lib/ -lwave \
#        -L ../lib/ -lrtcm \
#        -Wl,-rpath ../lib/ -Wl,-rpath libwave/lib/

#g++ aec_demo.cpp -g -fsanitize=address \
#        -I ../ -I libwave/include/ \
#        -L libwave/lib/ -lwave \
#        -L ../lib/ -lrtcm \
#        -Wl,-rpath ../lib/ -Wl,-rpath libwave/lib/


CC=gcc
CXX=g++
INC=-I ../ -I libwave/include/ 
LIB=-lasan -L libwave/lib/ -lwave -L ../lib/ -lrtcm
#LIB=-lasan ${LIB}
CCFLAGS=-g -fsanitize=address
#CCFLAGS= ${CCFLAGS} -fsanitize=address
LDFLAGS=-Wl,-rpath ../lib/ -Wl,-rpath libwave/lib/

TARGETS=ns_demo aec_demo aecm_demo

all: $(TARGETS)

ns_demo:ns_demo.o
	$(CXX) -o ns_demo ns_demo.o $(LIB) $(LDFLAGS)

ns_demo.o:ns_demo.cpp
	$(CC) -c $(CCFLAGS) ns_demo.cpp $(INC)

aec_demo:aec_demo.o
	$(CXX) -o aec_demo aec_demo.o $(LIB) $(LDFLAGS)

aec_demo.o:aec_demo.cpp
	$(CC) -c $(CCFLAGS) aec_demo.cpp $(INC)

aecm_demo:aecm_demo.o
	$(CXX) -o aecm_demo aecm_demo.o $(LIB) $(LDFLAGS)

aecm_demo.o:aecm_demo.cpp
	$(CC) -c $(CCFLAGS) aecm_demo.cpp $(INC)

clean:
	rm *.o $(TARGETS)
