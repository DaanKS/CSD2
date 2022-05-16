add_executable(CC main.cpp GarbageClass.cpp)
target_link_libraries(CC PRIVATE panners)
target_compile_features(CC PRIVATE cxx_std_20)