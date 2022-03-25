add_executable(datorroReverb main.cpp analysis.cpp highpass.cpp allpass.cpp circbuffer.cpp modallpass.cpp onepole.cpp predelay.cpp comb.cpp datorro.cpp)
target_link_libraries(tanhTest PRIVATE juce_audio_backend)
target_compile_features(datorroReverb PRIVATE cxx_std_20)
