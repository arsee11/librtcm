
project(webrtc_absl_deps)
set(SRCS
${WEBRTC_INCLUDE_DIRS}/absl_inl/absl/absl/strings/ascii.cc
${WEBRTC_INCLUDE_DIRS}/absl_inl/absl/absl/strings/numbers.cc
${WEBRTC_INCLUDE_DIRS}/absl_inl/absl/absl/strings/charconv.cc
${WEBRTC_INCLUDE_DIRS}/absl_inl/absl/absl/strings/internal/charconv_bigint.cc
${WEBRTC_INCLUDE_DIRS}/absl_inl/absl/absl/strings/internal/charconv_parse.cc
${WEBRTC_INCLUDE_DIRS}/absl_inl/absl/absl/strings/internal/memutil.cc
${WEBRTC_INCLUDE_DIRS}/absl_inl/absl/absl/strings/match.cc
${WEBRTC_INCLUDE_DIRS}/absl_inl/absl/absl/base/internal/raw_logging.cc
)
add_library(${PROJECT_NAME} STATIC ${SRCS})


project(webrtc_apm_aecm)
set(SRCS
${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aecm/aecm_core.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aecm/aecm_core_c.cc
#${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aecm/aecm_core_mips.cc
#${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aecm/aecm_core_neon.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aecm/echo_control_mobile.cc
)
add_library(${PROJECT_NAME} STATIC ${SRCS})


project(webrtc_apm_ns)
set(SRCS
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/ns/fast_math.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/ns/histograms.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/ns/noise_estimator.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/ns/noise_suppressor.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/ns/ns_fft.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/ns/prior_signal_model.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/ns/prior_signal_model_estimator.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/ns/quantile_noise_estimator.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/ns/signal_model.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/ns/signal_model_estimator.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/ns/speech_probability_estimator.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/ns/suppression_params.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/ns/wiener_filter.cc
)
add_library(${PROJECT_NAME} STATIC ${SRCS})


project(webrtc_audio_processing)
set(SRCS
${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/audio_buffer.cc
#${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/audio_processing_builder_impl.cc
#${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/audio_processing_impl.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/echo_control_mobile_impl.cc
#${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/gain_control_impl.cc
#${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/gain_controller2.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/high_pass_filter.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/logging/apm_data_dumper.cc
#${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/residual_echo_detector.cc
#${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/rms_level.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/splitting_filter.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/three_band_filter_bank.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/utility/cascaded_biquad_filter.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/utility/delay_estimator_wrapper.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/utility/delay_estimator.cc
)
add_library(${PROJECT_NAME} STATIC ${SRCS})


if(${RTCM_AVX2_ENABLE})   
    project(webrtc_apm_aec3)
    set(SRCS 
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/adaptive_fir_filter_avx2.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/adaptive_fir_filter.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/adaptive_fir_filter_erl_avx2.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/adaptive_fir_filter_erl.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/aec3_common.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/aec3_fft.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/aec_state.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/alignment_mixer.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/api_call_jitter_metrics.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/block_buffer.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/block_delay_buffer.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/block_framer.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/block_processor.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/block_processor_metrics.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/clockdrift_detector.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/coarse_filter_update_gain.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/comfort_noise_generator.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/config_selector.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/decimator.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/dominant_nearend_detector.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/downsampled_render_buffer.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/echo_audibility.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/echo_canceller3.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/echo_path_delay_estimator.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/echo_path_variability.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/echo_remover.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/echo_remover_metrics.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/erle_estimator.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/erl_estimator.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/fft_buffer.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/fft_data_avx2.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/filter_analyzer.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/frame_blocker.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/fullband_erle_estimator.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/matched_filter_avx2.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/matched_filter.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/matched_filter_lag_aggregator.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/moving_average.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/multi_channel_content_detector.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/refined_filter_update_gain.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/render_buffer.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/render_delay_buffer.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/render_delay_controller.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/render_delay_controller_metrics.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/render_signal_analyzer.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/residual_echo_estimator.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/reverb_decay_estimator.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/reverb_frequency_response.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/reverb_model.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/reverb_model_estimator.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/signal_dependent_erle_estimator.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/spectrum_buffer.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/stationarity_estimator.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/subband_erle_estimator.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/subband_nearend_detector.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/subtractor.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/subtractor_output_analyzer.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/subtractor_output.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/suppression_filter.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/suppression_gain.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/transparent_mode.cc
    ${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_processing/aec3/vector_math_avx2.cc
)
    add_library(${PROJECT_NAME} STATIC ${SRCS})
endif()

project(webrtc_common_audio)
set(SRCS
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/audio_util.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/ring_buffer.c
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/get_hanning_window.c
#${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/complex_bit_reverse_mips.c
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/get_scaling_square.c
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/cross_correlation.c
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/copy_set_operations.c
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/auto_correlation.c
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/downsample_fast.c
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/levinson_durbin.c
#${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/resample_by_2_mips.c
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/spl_sqrt.c
#${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/min_max_operations_mips.c
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/refl_coef_to_lpc.c
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/division_operations.c
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/resample_by_2.c
#${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/downsample_fast_mips.c
#${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/cross_correlation_mips.c
#${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/cross_correlation_neon.c
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/resample_48khz.c
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/spl_inl.c
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/vector_scaling_operations.c
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/lpc_to_refl_coef.c
#${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/min_max_operations_neon.c
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/spl_init.c
#${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/filter_ar_fast_q12_mips.c
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/filter_ma_fast_q12.c
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/min_max_operations.c
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/energy.c
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/resample_by_2_internal.c
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/filter_ar.c
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/complex_bit_reverse.c
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/randomization_functions.c
#${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/complex_fft_mips.c
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/complex_fft.c
#${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/vector_scaling_operations_mips.c
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/resample_fractional.c
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/auto_corr_to_refl_coef.c
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/resample.c
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/real_fft.c
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/filter_ar_fast_q12.c
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/sqrt_of_one_minus_x_squared.c
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/dot_product_with_scale.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/splitting_filter.c
#${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/signal_processing/downsample_fast_neon.c
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/channel_buffer.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/third_party/ooura/fft_size_256/fft4g.cc
#${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/third_party/ooura/fft_size_128/ooura_fft_neon.cc
#${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/third_party/ooura/fft_size_128/ooura_fft_mips.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/third_party/ooura/fft_size_128/ooura_fft.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/third_party/ooura/fft_size_128/ooura_fft_sse2.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/third_party/spl_sqrt_floor/spl_sqrt_floor.c
#${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/third_party/spl_sqrt_floor/spl_sqrt_floor_mips.c
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/resampler/sinusoidal_linear_chirp_source.cc
#${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/resampler/sinc_resampler_neon.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/resampler/resampler.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/resampler/sinc_resampler.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/resampler/push_sinc_resampler.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/resampler/push_resampler.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/resampler/sinc_resampler_avx2.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/common_audio/resampler/sinc_resampler_sse.cc
)
add_library(${PROJECT_NAME} STATIC ${SRCS})


project(webrtc_api)
set(SRCS
${WEBRTC_INCLUDE_DIRS}/webrtc/api/audio/audio_frame.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/api/audio/channel_layout.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/api/audio/echo_canceller3_config.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/api/audio_codecs/audio_format.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/api/audio_codecs/audio_decoder.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/api/environment/environment_factory.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/api/audio_codecs/g711/audio_decoder_g711.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/api/audio_codecs/L16/audio_decoder_L16.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/api/field_trials_registry.cc
#${WEBRTC_INCLUDE_DIRS}/webrtc/api/task_queue/default_task_queue_factory_gcd.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/api/task_queue/default_task_queue_factory_stdlib.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/api/task_queue/task_queue_base.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/api/transport/field_trial_based_config.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/api/rtc_event_log/rtc_event_log.cc
)
add_library(${PROJECT_NAME} STATIC ${SRCS})


project(webrtc_system_wrappers)
set(SRCS
${WEBRTC_INCLUDE_DIRS}/webrtc/system_wrappers/source/cpu_features.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/system_wrappers/source/field_trial.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/system_wrappers/source/metrics.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/system_wrappers/source/clock.cc
)
add_library(${PROJECT_NAME} STATIC ${SRCS})


project(webrtc_base)
set(SRCS
${WEBRTC_INCLUDE_DIRS}/webrtc/rtc_base/experiments/field_trial_parser.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/rtc_base/memory/aligned_malloc.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/rtc_base/checks.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/rtc_base/event.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/rtc_base/event_tracer.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/rtc_base/logging.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/rtc_base/platform_thread.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/rtc_base/platform_thread_types.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/rtc_base/time_utils.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/rtc_base/string_encode.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/rtc_base/string_utils.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/rtc_base/strings/string_builder.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/rtc_base/synchronization/sequence_checker_internal.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/rtc_base/synchronization/yield_policy.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/rtc_base/race_checker.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/rtc_base/system_time.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/rtc_base/task_queue_stdlib.cc
)
add_library(${PROJECT_NAME} STATIC ${SRCS})

project(webrtc_audio_codecs)
set(SRCS
${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_coding/codecs/legacy_encoded_audio_frame.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_coding/codecs/g711/audio_decoder_pcm.cc
#${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_coding/codecs/g711/audio_encoder_pcm.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_coding/codecs/g711/g711_interface.c
${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_coding/codecs/pcm16b/audio_decoder_pcm16b.cc
#${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_coding/codecs/pcm16b/audio_encoder_pcm16b.cc
${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_coding/codecs/pcm16b/pcm16b.c
${WEBRTC_INCLUDE_DIRS}/webrtc/modules/audio_coding/codecs/pcm16b/pcm16b_common.cc

)
add_library(${PROJECT_NAME} STATIC ${SRCS})
