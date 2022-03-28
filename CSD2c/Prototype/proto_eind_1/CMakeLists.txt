add_executable(proto_1 main.cpp analysis.cpp energyDetect.cpp generator.cpp waveshaper.cpp filter.cpp allpass.cpp audioeffect.cpp biquad.cpp comb.cpp datorro.cpp dualbiquad.cpp highpass.cpp modallpass.cpp onepole.cpp fixeddelay.cpp)
target_link_libraries(proto_1 PRIVATE juce_audio_backend panners oscillators circbuffer)
target_compile_features(proto_1 PRIVATE cxx_std_20)
