#ifndef G711_D_H
#define G711_D_H

#include "audio_c/audio_d.h"
#include "webrtc/api/audio_codecs/audio_decoder.h"

namespace rtcm
{
class G711Decoder : public AudioDecoder
{
public:
    G711Decoder(webrtc::AudioDecoder* internal_d)
        :_internal_d(internal_d)
    {}

    // Decodes `encode_len` bytes from `encoded` and writes the result in
    // `decoded`. The maximum bytes allowed to be written into `decoded` is
    // `max_decoded_bytes`. Returns the total number of samples across all
    // channels. If the decoder produced comfort noise, `speech_type`
    // is set to kComfortNoise, otherwise it is kSpeech. The desired output
    // sample rate is provided in `sample_rate_hz`, which must be valid for the
    // codec at hand.
    virtual int decode(const uint8_t* encoded,
                size_t encoded_len,
                int sample_rate_hz,
                size_t max_decoded_bytes,
                int16_t* decoded,
                SpeechType* speech_type)override;

    // Resets the decoder state (empty buffers etc.).
    virtual void reset()override;

    // Returns the actual sample rate of the decoder's output. This value may not
    // change during the lifetime of the decoder.
    virtual int sampleRateHz() const override;

    // The number of channels in the decoder's output. This value may not change
    // during the lifetime of the decoder.
    virtual int channels() const override;

private:
    std::unique_ptr<webrtc::AudioDecoder> _internal_d;
};

}//rtcm

#endif //G711_D_H