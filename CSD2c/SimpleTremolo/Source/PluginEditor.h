/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class SimpleTremoloAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SimpleTremoloAudioProcessorEditor (SimpleTremoloAudioProcessor&, juce::AudioProcessorValueTreeState& Reference);
    ~SimpleTremoloAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SimpleTremoloAudioProcessor& audioProcessor;
    juce::AudioProcessorValueTreeState& Reference;
    
    juce::Slider rateSlider;
    juce::Slider ampSlider;
    
    using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;
    std::unique_ptr<SliderAttachment> rateAttachment;
    std::unique_ptr<SliderAttachment> ampAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimpleTremoloAudioProcessorEditor)
};
