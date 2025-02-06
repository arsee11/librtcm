///ns.cpp
//

#include "ns.h"

#include <webrtc/modules/audio_processing/vad/voice_activity_detector.h>

namespace rtcm
{

class VadProcessorImpl : public VadProcessor
{
public:
    VadProcessorImpl(VadModel m)
    {
        _vad = std::make_unique<webrtc::VoiceActivityDetector>();
        setModel(m);
    }

    void setModel(VadModel m)override {};
    bool process(int16_t* audio, size_t nframes, size_t sample_rate_hz)override;

private:
    std::unique_ptr<webrtc::VoiceActivityDetector> _vad;
};

static const float kMeanSpeechProbability = 0.3f;
static const float kMaxNoiseProbability = 0.1f;
bool VadProcessorImpl::process(int16_t* audio, size_t nframes, size_t sample_rate_hz)
{
    float mean_probability = 0.f;
    size_t num_chunks = 0;
    size_t nframe10ms = sample_rate_hz / 100;
    size_t n = nframes / nframe10ms;
    for (size_t i = 0; i < n; i++) {
        _vad->ProcessChunk(audio + i * nframe10ms, nframe10ms, sample_rate_hz)
        mean_probability += vad.last_voice_probability();
        ++num_chunks;
    }

    mean_probability /= num_chunks;

    return (mean_probability > kMeanSpeechProbability ? true : false);
}

VadProcessor::vad_ptr VadProcessor::create(VadModel m)
{
    return std::make_shared<VadProcessorImpl>(m);
}

}//rtcm