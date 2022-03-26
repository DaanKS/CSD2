add_executable(tremolo main.cpp tremolo.cpp)
target_link_libraries(tremolo PRIVATE juce_audio_backend panners oscillators)
target_compile_features(tremolo PRIVATE cxx_std_20)