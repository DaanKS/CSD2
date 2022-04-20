#include <iostream>
#include "biquad.h"
#include <vector>

class Oversampler{
public:
    Oversampler(double samplerate);
    ~Oversampler();

    inline void initializeBuffers(){
        //sooooo thussss here we are he long time no see :- ()
        //the oversampledBuffer is twice the size of the inputBuffer because :- (=)
        //every generation a zero gets added in between the samples
        m_inputBuffer = (float*)malloc(2 * sizeof(float));
        memset(m_inputBuffer, 0, 2 * sizeof(float));
        m_oversampledBuffer = (float*)malloc(( 2 * 2) * sizeof(float));
        memset(m_oversampledBuffer, 0, (2 * 2) * sizeof(float));
        m_tempOverSampledBuffer = (float*)malloc(( 2 * 2) * sizeof(float));
        memset(m_tempOverSampledBuffer, 0, (2 * 2) * sizeof(float));
        m_tempDownSampledBuffer = (float*)malloc(( 2 * 2) * sizeof(float));
        memset(m_tempDownSampledBuffer, 0, (2 * 2) * sizeof(float));
        m_outputBuffer = (float*)malloc(2 * sizeof(float));
        memset(m_outputBuffer, 0, 2 * sizeof(float));
    }
    void initilizeFilters();

    void input(float inputSample);
    void output();
    void setOverSampledBuffer(float inputSample, int index);
    float getOverSampledBuffer(int index);
    float getOutputBuffer();

    void upSample(float* &inputBuffer, float* &oversampledBuffer ,int numInputSamples);
    void downSample(float* &outputBuffer ,float* &overSampledBuffer, int numOutputSamples);
    void filter(float* &overSampledBuffer, float* &tempOverSampledBuffer, int numInputSamples, int numFilter);

private:
    double m_samplerate;
    //int m_timesOversampled;
    float* m_inputBuffer;
    float* m_outputBuffer;
    float* m_oversampledBuffer;
    //temporary buffer beacause oversapld buffer can not be overwritten
    float* m_tempOverSampledBuffer;
    float* m_tempDownSampledBuffer;

    std::vector<Biquad> biquads;
};