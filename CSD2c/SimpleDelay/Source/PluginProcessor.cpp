/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SimpleDelayAudioProcessor::SimpleDelayAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ), DelayParams(*this, nullptr, "Parameters",
                                    {
                           std::make_unique<juce::AudioParameterFloat>("uDelayTime", "DelayTime", 1.0f, 5000.0f, 500.0f),
                           std::make_unique<juce::AudioParameterFloat>("uFeedback", "Feedback", 0.0f, 1.0f, 0.5f),
                           std::make_unique<juce::AudioParameterFloat>("uDryWet","DryWet", 0.0f, 1.0f, 0.5f)
                       })
#endif
{
    delayTime = DelayParams.getRawParameterValue("uDelayTime");
    feedBack = DelayParams.getRawParameterValue("uFeedback");
    dryWet = DelayParams.getRawParameterValue("uDryWet");

    for (int i = 0; i < getBusesLayout().getNumChannels(true, 0); ++i)
      delays.emplace_back (Delay());
}

SimpleDelayAudioProcessor::~SimpleDelayAudioProcessor()
{
}

//==============================================================================
const juce::String SimpleDelayAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool SimpleDelayAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SimpleDelayAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool SimpleDelayAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double SimpleDelayAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SimpleDelayAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int SimpleDelayAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SimpleDelayAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String SimpleDelayAudioProcessor::getProgramName (int index)
{
    return {};
}

void SimpleDelayAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void SimpleDelayAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    for (auto& del : delays)
        del.setSampleRate(sampleRate);
    for (auto& del : delays)
        del.instantiate();
   
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void SimpleDelayAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SimpleDelayAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void SimpleDelayAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    for (auto& del : delays)
        del.setDelayTime(*delayTime);
    for (auto& del : delays)
        del.setFeedback(*feedBack);
    for (auto& del : delays)
        del.setDryWet(*dryWet);
    
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
        auto* readPointer = buffer.getReadPointer (channel);
        
        for (int sample = 0; sample < buffer.getNumSamples(); ++sample){
            channelData[sample] = delays[channel].output(readPointer[sample]);
        }

        // ..do something to the data...
    }
}

//==============================================================================
bool SimpleDelayAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* SimpleDelayAudioProcessor::createEditor()
{
    return new SimpleDelayAudioProcessorEditor (*this);
}

//==============================================================================
void SimpleDelayAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    std::unique_ptr<juce::XmlElement> xml (new juce::XmlElement ("DelayParams"));
    xml->setAttribute("uDelayTime", (float) *delayTime);
    xml->setAttribute("uFeedback", (float) *feedBack);
    xml->setAttribute("uDryWet",  (float) *dryWet);
    copyXmlToBinary(*xml, destData);
}

void SimpleDelayAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    std::unique_ptr<juce::XmlElement> xmlState (getXmlFromBinary(data, sizeInBytes));
        if(xmlState.get() !=nullptr)
        {
            if(xmlState->hasTagName("DelayParams"))
            {
                *delayTime = (float) xmlState->getDoubleAttribute("uDelayTime", 5000.0f);
                *feedBack =  (float) xmlState->getDoubleAttribute("uFeedback", 1.0f);
                *dryWet = (float) xmlState->getDoubleAttribute("uDryWet" , 1.0f);
            }
        }
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SimpleDelayAudioProcessor();
}
