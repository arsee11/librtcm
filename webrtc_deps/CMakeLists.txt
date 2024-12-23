
project(webrtc_absl_deps)
set(SRCS
absl_inl/absl/absl/strings/ascii.cc
absl_inl/absl/absl/strings/numbers.cc
absl_inl/absl/absl/strings/charconv.cc
absl_inl/absl/absl/strings/internal/charconv_bigint.cc
absl_inl/absl/absl/strings/internal/charconv_parse.cc
absl_inl/absl/absl/strings/internal/memutil.cc
absl_inl/absl/absl/strings/match.cc
absl_inl/absl/absl/base/internal/raw_logging.cc
)
add_library(${PROJECT_NAME} STATIC ${SRCS})


project(webrtc_apm_aecm)
set(SRCS
webrtc/modules/audio_processing/aecm/aecm_core.cc
webrtc/modules/audio_processing/aecm/aecm_core_c.cc
#webrtc/modules/audio_processing/aecm/aecm_core_mips.cc
#webrtc/modules/audio_processing/aecm/aecm_core_neon.cc
webrtc/modules/audio_processing/aecm/echo_control_mobile.cc
)
add_library(${PROJECT_NAME} STATIC ${SRCS})


project(webrtc_apm_ns)
set(SRCS
    webrtc/modules/audio_processing/ns/fast_math.cc
    webrtc/modules/audio_processing/ns/histograms.cc
    webrtc/modules/audio_processing/ns/noise_estimator.cc
    webrtc/modules/audio_processing/ns/noise_suppressor.cc
    webrtc/modules/audio_processing/ns/ns_fft.cc
    webrtc/modules/audio_processing/ns/prior_signal_model.cc
    webrtc/modules/audio_processing/ns/prior_signal_model_estimator.cc
    webrtc/modules/audio_processing/ns/quantile_noise_estimator.cc
    webrtc/modules/audio_processing/ns/signal_model.cc
    webrtc/modules/audio_processing/ns/signal_model_estimator.cc
    webrtc/modules/audio_processing/ns/speech_probability_estimator.cc
    webrtc/modules/audio_processing/ns/suppression_params.cc
    webrtc/modules/audio_processing/ns/wiener_filter.cc
)
add_library(${PROJECT_NAME} STATIC ${SRCS})


project(webrtc_audio_processing)
set(SRCS
webrtc/modules/audio_processing/audio_buffer.cc
#webrtc/modules/audio_processing/audio_processing_builder_impl.cc
#webrtc/modules/audio_processing/audio_processing_impl.cc
webrtc/modules/audio_processing/echo_control_mobile_impl.cc
#webrtc/modules/audio_processing/gain_control_impl.cc
#webrtc/modules/audio_processing/gain_controller2.cc
webrtc/modules/audio_processing/high_pass_filter.cc
webrtc/modules/audio_processing/logging/apm_data_dumper.cc
#webrtc/modules/audio_processing/residual_echo_detector.cc
#webrtc/modules/audio_processing/rms_level.cc
webrtc/modules/audio_processing/splitting_filter.cc
webrtc/modules/audio_processing/three_band_filter_bank.cc
webrtc/modules/audio_processing/utility/cascaded_biquad_filter.cc
webrtc/modules/audio_processing/utility/delay_estimator_wrapper.cc
webrtc/modules/audio_processing/utility/delay_estimator.cc
)
add_library(${PROJECT_NAME} STATIC ${SRCS})


if(${RTCM_AVX2_ENABLE})   
    project(webrtc_apm_aec3)
    set(SRCS 
    webrtc/modules/audio_processing/aec3/adaptive_fir_filter_avx2.cc
    webrtc/modules/audio_processing/aec3/adaptive_fir_filter.cc
    webrtc/modules/audio_processing/aec3/adaptive_fir_filter_erl_avx2.cc
    webrtc/modules/audio_processing/aec3/adaptive_fir_filter_erl.cc
    webrtc/modules/audio_processing/aec3/aec3_common.cc
    webrtc/modules/audio_processing/aec3/aec3_fft.cc
    webrtc/modules/audio_processing/aec3/aec_state.cc
    webrtc/modules/audio_processing/aec3/alignment_mixer.cc
    webrtc/modules/audio_processing/aec3/api_call_jitter_metrics.cc
    webrtc/modules/audio_processing/aec3/block_buffer.cc
    webrtc/modules/audio_processing/aec3/block_delay_buffer.cc
    webrtc/modules/audio_processing/aec3/block_framer.cc
    webrtc/modules/audio_processing/aec3/block_processor.cc
    webrtc/modules/audio_processing/aec3/block_processor_metrics.cc
    webrtc/modules/audio_processing/aec3/clockdrift_detector.cc
    webrtc/modules/audio_processing/aec3/coarse_filter_update_gain.cc
    webrtc/modules/audio_processing/aec3/comfort_noise_generator.cc
    webrtc/modules/audio_processing/aec3/config_selector.cc
    webrtc/modules/audio_processing/aec3/decimator.cc
    webrtc/modules/audio_processing/aec3/dominant_nearend_detector.cc
    webrtc/modules/audio_processing/aec3/downsampled_render_buffer.cc
    webrtc/modules/audio_processing/aec3/echo_audibility.cc
    webrtc/modules/audio_processing/aec3/echo_canceller3.cc
    webrtc/modules/audio_processing/aec3/echo_path_delay_estimator.cc
    webrtc/modules/audio_processing/aec3/echo_path_variability.cc
    webrtc/modules/audio_processing/aec3/echo_remover.cc
    webrtc/modules/audio_processing/aec3/echo_remover_metrics.cc
    webrtc/modules/audio_processing/aec3/erle_estimator.cc
    webrtc/modules/audio_processing/aec3/erl_estimator.cc
    webrtc/modules/audio_processing/aec3/fft_buffer.cc
    webrtc/modules/audio_processing/aec3/fft_data_avx2.cc
    webrtc/modules/audio_processing/aec3/filter_analyzer.cc
    webrtc/modules/audio_processing/aec3/frame_blocker.cc
    webrtc/modules/audio_processing/aec3/fullband_erle_estimator.cc
    webrtc/modules/audio_processing/aec3/matched_filter_avx2.cc
    webrtc/modules/audio_processing/aec3/matched_filter.cc
    webrtc/modules/audio_processing/aec3/matched_filter_lag_aggregator.cc
    webrtc/modules/audio_processing/aec3/moving_average.cc
    webrtc/modules/audio_processing/aec3/multi_channel_content_detector.cc
    webrtc/modules/audio_processing/aec3/refined_filter_update_gain.cc
    webrtc/modules/audio_processing/aec3/render_buffer.cc
    webrtc/modules/audio_processing/aec3/render_delay_buffer.cc
    webrtc/modules/audio_processing/aec3/render_delay_controller.cc
    webrtc/modules/audio_processing/aec3/render_delay_controller_metrics.cc
    webrtc/modules/audio_processing/aec3/render_signal_analyzer.cc
    webrtc/modules/audio_processing/aec3/residual_echo_estimator.cc
    webrtc/modules/audio_processing/aec3/reverb_decay_estimator.cc
    webrtc/modules/audio_processing/aec3/reverb_frequency_response.cc
    webrtc/modules/audio_processing/aec3/reverb_model.cc
    webrtc/modules/audio_processing/aec3/reverb_model_estimator.cc
    webrtc/modules/audio_processing/aec3/signal_dependent_erle_estimator.cc
    webrtc/modules/audio_processing/aec3/spectrum_buffer.cc
    webrtc/modules/audio_processing/aec3/stationarity_estimator.cc
    webrtc/modules/audio_processing/aec3/subband_erle_estimator.cc
    webrtc/modules/audio_processing/aec3/subband_nearend_detector.cc
    webrtc/modules/audio_processing/aec3/subtractor.cc
    webrtc/modules/audio_processing/aec3/subtractor_output_analyzer.cc
    webrtc/modules/audio_processing/aec3/subtractor_output.cc
    webrtc/modules/audio_processing/aec3/suppression_filter.cc
    webrtc/modules/audio_processing/aec3/suppression_gain.cc
    webrtc/modules/audio_processing/aec3/transparent_mode.cc
    webrtc/modules/audio_processing/aec3/vector_math_avx2.cc
)
    add_library(${PROJECT_NAME} STATIC ${SRCS})
endif()

project(webrtc_common_audio)
set(SRCS
webrtc/common_audio/audio_util.cc
webrtc/common_audio/ring_buffer.c
webrtc/common_audio/signal_processing/get_hanning_window.c
#webrtc/common_audio/signal_processing/complex_bit_reverse_mips.c
webrtc/common_audio/signal_processing/get_scaling_square.c
webrtc/common_audio/signal_processing/cross_correlation.c
webrtc/common_audio/signal_processing/copy_set_operations.c
webrtc/common_audio/signal_processing/auto_correlation.c
webrtc/common_audio/signal_processing/downsample_fast.c
webrtc/common_audio/signal_processing/levinson_durbin.c
#webrtc/common_audio/signal_processing/resample_by_2_mips.c
webrtc/common_audio/signal_processing/spl_sqrt.c
#webrtc/common_audio/signal_processing/min_max_operations_mips.c
webrtc/common_audio/signal_processing/refl_coef_to_lpc.c
webrtc/common_audio/signal_processing/division_operations.c
webrtc/common_audio/signal_processing/resample_by_2.c
#webrtc/common_audio/signal_processing/downsample_fast_mips.c
#webrtc/common_audio/signal_processing/cross_correlation_mips.c
#webrtc/common_audio/signal_processing/cross_correlation_neon.c
webrtc/common_audio/signal_processing/resample_48khz.c
webrtc/common_audio/signal_processing/spl_inl.c
webrtc/common_audio/signal_processing/vector_scaling_operations.c
webrtc/common_audio/signal_processing/lpc_to_refl_coef.c
#webrtc/common_audio/signal_processing/min_max_operations_neon.c
webrtc/common_audio/signal_processing/spl_init.c
#webrtc/common_audio/signal_processing/filter_ar_fast_q12_mips.c
webrtc/common_audio/signal_processing/filter_ma_fast_q12.c
webrtc/common_audio/signal_processing/min_max_operations.c
webrtc/common_audio/signal_processing/energy.c
webrtc/common_audio/signal_processing/resample_by_2_internal.c
webrtc/common_audio/signal_processing/filter_ar.c
webrtc/common_audio/signal_processing/complex_bit_reverse.c
webrtc/common_audio/signal_processing/randomization_functions.c
#webrtc/common_audio/signal_processing/complex_fft_mips.c
webrtc/common_audio/signal_processing/complex_fft.c
#webrtc/common_audio/signal_processing/vector_scaling_operations_mips.c
webrtc/common_audio/signal_processing/resample_fractional.c
webrtc/common_audio/signal_processing/auto_corr_to_refl_coef.c
webrtc/common_audio/signal_processing/resample.c
webrtc/common_audio/signal_processing/real_fft.c
webrtc/common_audio/signal_processing/filter_ar_fast_q12.c
webrtc/common_audio/signal_processing/sqrt_of_one_minus_x_squared.c
webrtc/common_audio/signal_processing/dot_product_with_scale.cc
webrtc/common_audio/signal_processing/splitting_filter.c
#webrtc/common_audio/signal_processing/downsample_fast_neon.c
webrtc/common_audio/channel_buffer.cc
webrtc/common_audio/third_party/ooura/fft_size_256/fft4g.cc
#webrtc/common_audio/third_party/ooura/fft_size_128/ooura_fft_neon.cc
#webrtc/common_audio/third_party/ooura/fft_size_128/ooura_fft_mips.cc
webrtc/common_audio/third_party/ooura/fft_size_128/ooura_fft.cc
webrtc/common_audio/third_party/ooura/fft_size_128/ooura_fft_sse2.cc
webrtc/common_audio/third_party/spl_sqrt_floor/spl_sqrt_floor.c
#webrtc/common_audio/third_party/spl_sqrt_floor/spl_sqrt_floor_mips.c
webrtc/common_audio/resampler/sinusoidal_linear_chirp_source.cc
#webrtc/common_audio/resampler/sinc_resampler_neon.cc
webrtc/common_audio/resampler/resampler.cc
webrtc/common_audio/resampler/sinc_resampler.cc
webrtc/common_audio/resampler/push_sinc_resampler.cc
webrtc/common_audio/resampler/push_resampler.cc
webrtc/common_audio/resampler/sinc_resampler_avx2.cc
webrtc/common_audio/resampler/sinc_resampler_sse.cc
)
add_library(${PROJECT_NAME} STATIC ${SRCS})


project(webrtc_api)
set(SRCS
webrtc/api/audio/audio_frame.cc
webrtc/api/audio/channel_layout.cc
webrtc/api/audio/echo_canceller3_config.cc
#webrtc/api/field_trials_registry.cc
#webrtc/api/rtp_parameters.cc
)
add_library(${PROJECT_NAME} STATIC ${SRCS})


project(webrtc_system_wrappers)
set(SRCS
webrtc/system_wrappers/source/cpu_features.cc
webrtc/system_wrappers/source/field_trial.cc
webrtc/system_wrappers/source/metrics.cc
)
add_library(${PROJECT_NAME} STATIC ${SRCS})


project(webrtc_base)
set(SRCS
webrtc/rtc_base/experiments/field_trial_parser.cc
webrtc/rtc_base/memory/aligned_malloc.cc
webrtc/rtc_base/checks.cc
webrtc/rtc_base/logging.cc
webrtc/rtc_base/platform_thread_types.cc
webrtc/rtc_base/time_utils.cc
webrtc/rtc_base/string_encode.cc
webrtc/rtc_base/string_utils.cc
webrtc/rtc_base/strings/string_builder.cc
webrtc/rtc_base/race_checker.cc
webrtc/rtc_base/system_time.cc
)
add_library(${PROJECT_NAME} STATIC ${SRCS})


