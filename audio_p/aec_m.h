///aec_m.h
//

#ifndef AEC_M_H
#define AEC_M_H

#include <memory>

namespace rtcm
{

//Receives 10 ms frames audio.
class EchoCancellerMobile
{
public:
  enum RoutingMode {
    QuietEarpieceOrHeadset,
    Earpiece,
    LoudEarpiece,
    Speakerphone,
    LoudSpeakerphone
  };

public:
    EchoCancellerMobile()=default;

    using aec_ptr = std::shared_ptr<EchoCancellerMobile>;
    static aec_ptr create(RoutingMode rtm,
                    size_t sample_rate_hz,
                    size_t num_channels);

    EchoCancellerMobile(const EchoCancellerMobile&) = delete;
    EchoCancellerMobile& operator=(const EchoCancellerMobile&) = delete;

    virtual ~EchoCancellerMobile()=default;

    virtual void processFarEnd(int16_t* audio) = 0;

    virtual void processNearEnd(const int16_t* audio, int16_t* out, int delay_ms)=0;
};
}
#endif //AEC_M_H
