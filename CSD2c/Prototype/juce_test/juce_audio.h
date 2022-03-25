
#pragma once

#include <memory>

struct AudioCallback
{
    virtual void prepareToPlay (double sampleRate, int blockSize) {}
    virtual void process (const float** input, float** output, int numInputChannels, int numOutputChannels, int numSamples) = 0;
    virtual void releaseResources() {}
};

struct AudioBackend
{
    AudioBackend();

    void openDefaultIODevice (int numInputChannels, int numOutputChannels);
    void registerCallback (AudioCallback* callback);
    void closeDevice();

private:
    struct Pimpl;
    struct PimplDeleter
    {
        void operator()(Pimpl*);
    };

    std::unique_ptr<Pimpl, PimplDeleter> pimpl;
};