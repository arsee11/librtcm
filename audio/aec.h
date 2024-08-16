///aec.h
//

#ifndef AEC_H
#define AEC_H

#include <memory>

namespace rtcm
{
class EchoCanceller
{
public:
    EchoCanceller()=default;

    using aec_ptr = std::shared_ptr<EchoCanceller>;
    static aec_ptr create(
                    size_t sample_rate_hz,
                    size_t num_channels);

    EchoCanceller(const EchoCanceller&) = delete;
    EchoCanceller& operator=(const EchoCanceller&) = delete;

    virtual ~EchoCanceller()=default;

    virtual void analyzeFarEnd(int16_t* audio, size_t frame_size) = 0;

    virtual void processNearEnd(const int16_t* audio, int16_t* out, size_t frame_size)=0;
};
}
#endif //AEC_H
