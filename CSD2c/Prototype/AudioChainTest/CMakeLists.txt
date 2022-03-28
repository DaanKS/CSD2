add_executable(audiotest main.cpp waveshaper.cpp filter.cpp allpass.cpp audioeffect.cpp biquad.cpp comb.cpp datorro.cpp dualbiquad.cpp modallpass.cpp onepole.cpp fixeddelay.cpp)
target_link_libraries(audiotest PRIVATE juce_audio_backend panners oscillators circbuffer)
target_compile_features(audiotest PRIVATE cxx_std_20)
