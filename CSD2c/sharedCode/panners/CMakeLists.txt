add_library(panners STATIC squarelaw.cpp)
target_compile_features(panners PRIVATE cxx_std_20)
target_include_directories(panners PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
