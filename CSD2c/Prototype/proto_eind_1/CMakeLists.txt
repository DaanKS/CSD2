add_executable(proto_1 main.cpp )
target_link_libraries(proto_1 PRIVATE juce_audio_backend panners oscillators circbuffer)
target_compile_features(proto_1 PRIVATE cxx_std_20)
