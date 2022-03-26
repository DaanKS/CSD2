add_executable(UI main.cpp userInput.cpp)
target_link_libraries(UI PRIVATE juce_audio_backend)
target_compile_features(UI PRIVATE cxx_std_20)