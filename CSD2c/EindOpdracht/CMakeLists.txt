add_executable(baseline_test main.cpp energyDetect.cpp generator.cpp waveshaper.cpp filter.cpp allpass.cpp audioeffect.cpp biquad.cpp comb.cpp datorro.cpp dualbiquad.cpp modallpass.cpp onepole.cpp fixeddelay.cpp)
target_link_libraries(baseline_test PRIVATE juce_audio_backend panners oscillators circbuffer)
target_compile_features(baseline_test PRIVATE cxx_std_20)
