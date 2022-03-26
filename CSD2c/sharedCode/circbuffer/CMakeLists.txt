add_library(circbuffer STATIC circbuffer.cpp)
target_compile_features(circbuffer PRIVATE cxx_std_20)
target_include_directories(circbuffer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
