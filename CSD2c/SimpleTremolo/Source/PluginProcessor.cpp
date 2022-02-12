/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SimpleTremoloAudioProcessor::SimpleTremoloAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ), TrenParams(*this, nullptr, "Parameters",
                                     {
                           std::make_unique<juce::AudioParameterFloat>("uRate", "Rate", 0.01f, 20.0f, 0.5f),
                           std::make_unique<juce::AudioParameterFloat>("uAmplitude", "Amplitude", 0.0f, 1.0f, 1.0f)
                       })
#endif
{
    tren = new Tremolo;
    Rate = TrenParams.getRawParameterValue("uRate");
    Amplitude = TrenParams.getRawParameterValue("uAmplitude");
    
}

SimpleTremoloAudioProcessor::~SimpleTremoloAudioProcessor()
{
    delete tren;
    tren = nullptr;
}

//==============================================================================
const juce::String SimpleTremoloAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool SimpleTremoloAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SimpleTremoloAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool SimpleTremoloAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double SimpleTremoloAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SimpleTremoloAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int SimpleTremoloAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SimpleTremoloAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String SimpleTremoloAudioProcessor::getProgramName (int index)
{
    return {};
}

void SimpleTremoloAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void SimpleTremoloAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    tren->setSamplerate(sampleRate);
    ((Tremolo*)tren)->assignWave();
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void SimpleTremoloAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SimpleTremoloAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
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

void SimpleTremoloAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    ((Tremolo*)tren)->setRate(*Rate);
    ((Tremolo*)tren)->setAmplitude(*Amplitude);
    
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
        
        for(int sample = 0; sample < buffer.getNumSamples(); ++sample){
            channelData[sample] = tren->outputSample(readPointer[sample]);
        }
        // ..do something to the data...
    }
}

//==============================================================================
bool SimpleTremoloAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* SimpleTremoloAudioProcessor::createEditor()
{
    return new SimpleTremoloAudioProcessorEditor (*this, TrenParams);
}

//==============================================================================
void SimpleTremoloAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    std::unique_ptr<juce::XmlElement> xml (new juce::XmlElement ("TremParams"));
    xml->setAttribute("uRate", (double) *Rate);
    xml->setAttribute("uAmplitude", (double) *Amplitude);
    copyXmlToBinary (*xml, destData);
}

void SimpleTremoloAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    std::unique_ptr<juce::XmlElement> xmlState (getXmlFromBinary(data, sizeInBytes));
        if(xmlState.get() !=nullptr)
        {
            if(xmlState->hasTagName ("TremParams"))
            {
                *Rate = (float) xmlState->getDoubleAttribute ("uRate", 20.0f);
                *Amplitude = (float) xmlState->getDoubleAttribute("uAmplitude", 1.0f);
            }
        }
    }

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SimpleTremoloAudioProcessor();
}
