//file audio_d_factory.cpp

#include "audio_c/audio_d.h"
#include "g711_d.h"
#include <memory>
#include <optional>
#include <vector>
#include <regex>

#include "webrtc/api/audio_codecs/L16/audio_decoder_L16.h"
#include "webrtc/api/audio_codecs/audio_codec_pair_id.h"
#include "webrtc/api/audio_codecs/audio_decoder.h"
#include "webrtc/api/audio_codecs/audio_decoder_factory.h"
#include "webrtc/api/audio_codecs/audio_decoder_factory_template.h"
#include "webrtc/api/audio_codecs/audio_format.h"
#include "webrtc/api/audio_codecs/g711/audio_decoder_g711.h"
#include "webrtc/api/audio_codecs/g722/audio_decoder_g722.h"
#include "webrtc/api/scoped_refptr.h"
#if WEBRTC_USE_BUILTIN_OPUS
#include "webrtc/api/audio_codecs/opus/audio_decoder_multi_channel_opus.h"
#include "webrtc/api/audio_codecs/opus/audio_decoder_opus.h"  // nogncheck
#endif

#include "webrtc/api/environment/environment_factory.h"


namespace rtcm
{

namespace {

// Modify an audio decoder to not advertise support for anything.
template <typename T>
struct NotAdvertised {
  using Config = typename T::Config;
  static std::optional<Config> SdpToConfig(const webrtc::SdpAudioFormat& audio_format) {
    return T::SdpToConfig(audio_format);
  }
  static void AppendSupportedDecoders(
      std::vector<webrtc::AudioCodecSpec>* /* specs */) {
    // Don't advertise support for anything.
  }
  static std::unique_ptr<webrtc::AudioDecoder> MakeAudioDecoder(
      const Config& config,
      std::optional<webrtc::AudioCodecPairId> codec_pair_id = std::nullopt) {
    return T::MakeAudioDecoder(config, codec_pair_id);
  }
};

}  // namespace

rtc::scoped_refptr<webrtc::AudioDecoderFactory> CreateWebrtcAudioDecoderFactory() {
  return webrtc::CreateAudioDecoderFactory<

#if WEBRTC_USE_BUILTIN_OPUS
      webrtc::AudioDecoderOpus, NotAdvertised<webrtc::AudioDecoderMultiChannelOpus>,
#endif

      //webrtc::AudioDecoderG722,
      webrtc::AudioDecoderG711, 
      NotAdvertised<webrtc::AudioDecoderL16>
      >();
}


static auto factory_i = CreateWebrtcAudioDecoderFactory();
static webrtc::EnvironmentFactory env_factory;

static webrtc::SdpAudioFormat parse_codec_format(const std::string& codec_format)
{
    std::regex pattern( "/" );
    std::vector<std::string> vec;
    const std::sregex_token_iterator end;
    for (std::sregex_token_iterator i( codec_format.begin(), codec_format.end(), pattern, -1); i != end ; ++i) {
        vec.push_back( *i );
    }

    if(vec.size() == 3){
        return webrtc::SdpAudioFormat(vec[0],
            std::stoi(vec[1]),
            std::stoi(vec[2])
        );
    }  

    return webrtc::SdpAudioFormat("", 0, 0);
}

bool AudioDecoderFactory::isSupportedDecoder(
        const std::string& codec_format //format: codec_name/samplerate/channels
    )
{
    return factory_i->IsSupportedDecoder(parse_codec_format(codec_format));
}

static audio_decoder_ptr make_decoder(const webrtc::SdpAudioFormat& f, webrtc::AudioDecoder* d)
{
    if(f.name == "PCMA" || f.name == "PCMU"){
        return std::make_shared<G711Decoder>(d);
    }

    return nullptr;
}

audio_decoder_ptr AudioDecoderFactory::create(
        const std::string& codec_format //format: codec_name/samplerate/channels
    )
{
    webrtc::SdpAudioFormat format = parse_codec_format(codec_format);
    webrtc::Environment env = env_factory.Create();
    auto d = factory_i->Create(env, format, std::nullopt);

    if(d == nullptr){
        return nullptr;
    }
    audio_decoder_ptr decoder = make_decoder(format, d.release());
    return decoder;
}

}//rtcm