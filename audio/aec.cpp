///aec.cpp
//

#include "aec.h"

#include <webrtc/modules/audio_processing/aec3/echo_canceller3.h>
#include <api/audio/echo_canceller3_config.h>



namespace rtcm
{

class EchoCancellerImpl : public EchoCanceller
{
public:
    EchoCancellerImpl(int sample_rate_hz,
        size_t num_far_channels,
        size_t num_near_channels);


    void analyzeFarEnd(int16_t* audio, size_t frame_size)override;

    void processNearEnd(const int16_t* audio, int16_t* out, size_t frame_size)override;

private:
    int _sample_rate_hz;
    size_t _num_far_channels;
    size_t _num_near_channels;
    std::unique_ptr<webrtc::EchoCanceller3> echo;
};

EchoCancellerImpl::EchoCancellerImpl(int sample_rate_hz, size_t num_far_channels, size_t num_near_channels)
    : _sample_rate_hz(sample_rate_hz)
    ,_num_far_channels(num_far_channels)
    ,_num_near_channels(num_near_channels)
{
    webrtc::EchoCanceller3Config config;
    auto multichannel_config = webrtc::EchoCanceller3::CreateDefaultMultichannelConfig();
    echo = std::make_unique<webrtc::EchoCanceller3>(config, 
        multichannel_config, 
        sample_rate_hz,
        num_far_channels, 
        num_near_channels);
}

void EchoCancellerImpl::analyzeFarEnd(int16_t *audio, size_t frame_size)
{

    webrtc::AudioBuffer buf(_sample_rate_hz,
                    _num_far_channels,
                    _sample_rate_hz,
                    _num_far_channels,
                    _sample_rate_hz,
                    _num_far_channels);
    webrtc::StreamConfig sconf(_sample_rate_hz, _num_far_channels);
    buf.CopyFrom(audio, sconf);
    echo->AnalyzeRender(&buf);
}

void EchoCancellerImpl::processNearEnd(const int16_t* audio, int16_t* out, size_t frame_size)
{
    webrtc::AudioBuffer buf(_sample_rate_hz,
                    _num_near_channels,
                    _sample_rate_hz,
                    _num_near_channels,
                    _sample_rate_hz,
                    _num_near_channels);
    webrtc::StreamConfig sconf(_sample_rate_hz, _num_near_channels);
    buf.CopyFrom(audio, sconf);
    echo->AnalyzeCapture(&buf);
    echo->ProcessCapture(&buf, false);
    buf.CopyTo(sconf, out);
}

EchoCanceller::aec_ptr EchoCanceller::create(
                    size_t sample_rate_hz,
                    size_t num_channels)
{
    return std::make_shared<EchoCancellerImpl>(sample_rate_hz, num_channels, num_channels);
}

}//rtcm
