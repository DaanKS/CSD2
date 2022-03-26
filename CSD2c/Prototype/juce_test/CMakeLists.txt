add_executable(tanhTest main.cpp hypertan.cpp)
target_link_libraries(tanhTest PRIVATE juce_audio_backend)
target_compile_features(tanhTest PRIVATE cxx_std_20)