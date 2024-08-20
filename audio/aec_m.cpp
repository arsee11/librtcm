///aec_m.cpp
//

#include "aec_m.h"

#include <webrtc/modules/audio_processing/echo_control_mobile_impl.h>
#include <webrtc/modules/audio_processing/audio_buffer.h>
#include <webrtc/api/audio/echo_canceller3_config.h>
#include <webrtc/api/audio/audio_processing.h>


namespace rtcm
{

class EchoCancellerMobileImpl : public EchoCancellerMobile
{
public:
    EchoCancellerMobileImpl(RoutingMode rtm,
        int sample_rate_hz,
        size_t num_far_channels,
        size_t num_near_channels);


    void processFarEnd(int16_t* audio, size_t frame_size)override;

    void processNearEnd(const int16_t* audio, int16_t* out, size_t frame_size, int delay_ms)override;

private:
    int _sample_rate_hz;
    size_t _num_far_channels;
    size_t _num_near_channels;
    std::unique_ptr<webrtc::EchoControlMobileImpl> echo;
};

EchoCancellerMobileImpl::EchoCancellerMobileImpl(RoutingMode rtm, int sample_rate_hz, 
    size_t num_far_channels, size_t num_near_channels)
    : _sample_rate_hz(sample_rate_hz)
    ,_num_far_channels(num_far_channels)
    ,_num_near_channels(num_near_channels)
{
    echo = std::make_unique<webrtc::EchoControlMobileImpl>();
    echo->Initialize(sample_rate_hz,
        num_far_channels, 
        num_near_channels);
    echo->set_routing_mode(static_cast<webrtc::EchoControlMobileImpl::RoutingMode>(rtm));
}

void EchoCancellerMobileImpl::processFarEnd(int16_t *audio, size_t frame_size)
{

    webrtc::AudioBuffer buf(_sample_rate_hz,
                    _num_far_channels,
                    _sample_rate_hz,
                    _num_far_channels,
                    _sample_rate_hz,
                    _num_far_channels);
    webrtc::StreamConfig sconf(_sample_rate_hz, _num_far_channels);
    buf.CopyFrom(audio, sconf);
    std::vector<int16_t> packed_buf;
    webrtc::EchoControlMobileImpl::PackRenderAudioBuffer(&buf, _num_far_channels, _num_near_channels, &packed_buf);
    echo->ProcessRenderAudio(packed_buf);
}

void EchoCancellerMobileImpl::processNearEnd(const int16_t* audio, int16_t* out, size_t frame_size, int delay_ms)
{
    webrtc::AudioBuffer buf(_sample_rate_hz,
                    _num_near_channels,
                    _sample_rate_hz,
                    _num_near_channels,
                    _sample_rate_hz,
                    _num_near_channels);
    webrtc::StreamConfig sconf(_sample_rate_hz, _num_near_channels);
    buf.CopyFrom(audio, sconf);
    echo->ProcessCaptureAudio(&buf, delay_ms);
    buf.CopyTo(sconf, out);
}

EchoCancellerMobile::aec_ptr EchoCancellerMobile::create(RoutingMode rtm,
                    size_t sample_rate_hz,
                    size_t num_channels)
{
    return std::make_shared<EchoCancellerMobileImpl>(rtm, sample_rate_hz, num_channels, num_channels);
}

}//rtcm
