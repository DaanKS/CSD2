add_library(oscillators STATIC oscillator.cpp saw.cpp sine.cpp square.cpp)
target_compile_features(oscillators PRIVATE cxx_std_20)
target_include_directories(oscillators PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
