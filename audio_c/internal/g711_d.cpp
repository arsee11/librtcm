//file: g711.d.cpp

#include "g711_d.h"

namespace rtcm
{

// Decodes `encode_len` bytes from `encoded` and writes the result in
// `decoded`. The maximum bytes allowed to be written into `decoded` is
// `max_decoded_bytes`. Returns the total number of samples across all
// channels. If the decoder produced comfort noise, `speech_type`
// is set to kComfortNoise, otherwise it is kSpeech. The desired output
// sample rate is provided in `sample_rate_hz`, which must be valid for the
// codec at hand.
int G711Decoder::decode(const uint8_t* encoded,
            size_t encoded_len,
            int sample_rate_hz,
            size_t max_decoded_bytes,
            int16_t* decoded,
            SpeechType* speech_type)
{
    if(_internal_d != nullptr){
        return _internal_d->Decode(encoded, encoded_len, sample_rate_hz,
            max_decoded_bytes, decoded,
             reinterpret_cast<webrtc::AudioDecoder::SpeechType*>(speech_type));
    }
    return 0;
}

// Resets the decoder state (empty buffers etc.).
void G711Decoder::reset()
{
    if(_internal_d != nullptr){
        _internal_d->Reset();
    }
}

// Returns the actual sample rate of the decoder's output. This value may not
// change during the lifetime of the decoder.
int G711Decoder::sampleRateHz() const
{
    if(_internal_d != nullptr){
        return _internal_d->SampleRateHz();
    }

    return 0;
}

// The number of channels in the decoder's output. This value may not change
// during the lifetime of the decoder.
int G711Decoder::channels() const
{
    if(_internal_d != nullptr){
        return _internal_d->Channels();
    }

    return 0;
}

}//rtcm

