///ns.cpp
//

#include "ns.h"

#include <webrtc/modules/audio_processing/ns/noise_suppressor.h>

namespace rtcm
{

class NoiseSuppressorImpl : public NoiseSuppressor
{
public:
    NoiseSuppressorImpl(SuppressionLevel l,
                    size_t sample_rate_hz,
                    size_t num_channels)
        :_sample_rate_hz(sample_rate_hz)
        ,_num_channels(num_channels)
    {
        webrtc::NsConfig cfg;
        cfg.target_level = static_cast<webrtc::NsConfig::SuppressionLevel>(l);
        _ns = std::make_unique<webrtc::NoiseSuppressor>(
            cfg, sample_rate_hz, num_channels);
    }

    // Applies noise suppression.
    void process(int16_t* src, int16_t* dst)override;

private:
    std::unique_ptr<webrtc::NoiseSuppressor> _ns;
    size_t _sample_rate_hz;
    size_t _num_channels;
};

void NoiseSuppressorImpl::process(int16_t* src, int16_t* dst)
{
    webrtc::AudioBuffer buf(_sample_rate_hz,
                    _num_channels,
                    _sample_rate_hz,
                    _num_channels,
                    _sample_rate_hz,
                    _num_channels);

    webrtc::StreamConfig sconf(_sample_rate_hz, _num_channels);
    buf.CopyFrom(src, sconf);
    _ns->Analyze(buf);
    _ns->Process(&buf);
    buf.CopyTo(sconf, dst);    
}


NoiseSuppressor::ns_ptr NoiseSuppressor::create(SuppressionLevel l, size_t sample_rate_hz, size_t num_channels)
{
    return std::make_shared<NoiseSuppressorImpl>(l, sample_rate_hz, num_channels);
}

}//rtcm