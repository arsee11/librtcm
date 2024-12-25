#ifndef AUDIO_D_H
#define AUDIO_D_H

#include <cstdint>
#include <stddef.h>
#include <memory>

namespace rtcm
{
class AudioDecoder
{
public:
    enum SpeechType {
        kSpeech = 1,
        kComfortNoise = 2,
    };

    AudioDecoder() = default;
    virtual ~AudioDecoder() = default;

    AudioDecoder(const AudioDecoder&) = delete;
    AudioDecoder& operator=(const AudioDecoder&) = delete;

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
                SpeechType* speech_type)=0;

    // Resets the decoder state (empty buffers etc.).
    virtual void reset() = 0;

    // Returns the actual sample rate of the decoder's output. This value may not
    // change during the lifetime of the decoder.
    virtual int sampleRateHz() const = 0;

    // The number of channels in the decoder's output. This value may not change
    // during the lifetime of the decoder.
    virtual int channels() const = 0;

    // The maximum number of audio channels supported by WebRTC decoders.
    static constexpr int kMaxNumberOfChannels = 24;

};

using audio_decoder_ptr = std::shared_ptr<AudioDecoder>;

 // A factory that creates AudioDecoders.
 class AudioDecoderFactory{
public:
    //static std::vector<AudioCodecSpec> GetSupportedDecoders();
    
    static bool isSupportedDecoder(
        const std::string& codec_format //format: codec_name/samplerate/channels
    );
    
    // Create a new decoder instance. The `codec_pair_id` argument is used to link
    // encoders and decoders that talk to the same remote entity: if a
    // AudioEncoderFactory::Create() and a AudioDecoderFactory::Create() call
    // receive non-null IDs that compare equal, the factory implementations may
    // assume that the encoder and decoder form a pair. (The intended use case for
    // this is to set up communication between the AudioEncoder and AudioDecoder
    // instances, which is needed for some codecs with built-in bandwidth
    // adaptation.)
    //
    // Returns null if the format isn't supported.
    //
    // Note: Implementations need to be robust against combinations other than
    // one encoder, one decoder getting the same ID; such decoders must still
    // work.
    static audio_decoder_ptr create(
        const std::string& codec_format //format: codec_name/samplerate/channels
    );
};


}//rtcm

#endif //AUDIO_D_H