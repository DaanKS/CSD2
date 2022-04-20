add_executable(SubSynth main.cpp midi_io.cpp midicontrol.cpp subsynth.cpp onepole.cpp oversampler.cpp biquad.cpp)
target_link_libraries(SubSynth PRIVATE juce_audio_backend panners oscillators circbuffer)
target_compile_features(SubSynth PRIVATE cxx_std_20)
