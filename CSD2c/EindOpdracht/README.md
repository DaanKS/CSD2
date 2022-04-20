# HOW TO BUILD:

Install JUCE Backend at https://github.com/w-ensink/juce_audio_backend

Go to CSD2/CSD2c and type:
>git clone --recursive https://github.com/w-ensink/juce_audio_backend.git 

Go to CSD2/CSD2c folder and type:
>cmake -S . -B build

>cmake --build build

Go to CSD2/CSD2c/build/EindOpdracht and type: 
>make

If you run into issues with CURL on Ubuntu add the following to /juce_audio_backend/CMakeLists.txt: 
>target_compile_definitions(${PROJECT_NAME} PRIVATE -DJUCE_USE_CURL=0)
