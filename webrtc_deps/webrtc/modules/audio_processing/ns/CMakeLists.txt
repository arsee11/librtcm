
project(webrtc_apm_ns)

set(BASE_SRCS
    fast_math.cc
    histograms.cc
    noise_estimator.cc
    noise_suppressor.cc
    ns_fft.cc
    prior_signal_model.cc
    prior_signal_model_estimator.cc
    quantile_noise_estimator.cc
    signal_model.cc
    signal_model_estimator.cc
    speech_probability_estimator.cc
    suppression_params.cc
    wiener_filter.cc
)

add_library(${PROJECT_NAME} STATIC ${BASE_SRCS})
