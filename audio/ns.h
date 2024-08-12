///ns.h
//

#ifndef NS_H
#define NS_H

#include <memory>

namespace rtcm
{
enum class SuppressionLevel { k6dB, k12dB, k18dB, k21dB };

class NoiseSuppressor
{
public:
    NoiseSuppressor()=default;

    using ns_ptr = std::shared_ptr<NoiseSuppressor>;
    static ns_ptr create(SuppressionLevel l,
                    size_t sample_rate_hz,
                    size_t num_channels);

    NoiseSuppressor(const NoiseSuppressor&) = delete;
    NoiseSuppressor& operator=(const NoiseSuppressor&) = delete;

    virtual ~NoiseSuppressor()=default;

    // Applies noise suppression.
    virtual void process(int16_t* src, int16_t* dst, size_t frame_size)=0;
};
}
#endif //NS_H
