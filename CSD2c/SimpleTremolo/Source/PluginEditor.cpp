/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SimpleTremoloAudioProcessorEditor::SimpleTremoloAudioProcessorEditor (SimpleTremoloAudioProcessor& p, juce::AudioProcessorValueTreeState& Reference)
    : AudioProcessorEditor (&p), audioProcessor (p), Reference(Reference)
{
    addAndMakeVisible(rateSlider);
    rateSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    rateSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 20);
    rateAttachment = std::make_unique<SliderAttachment>(Reference,"uRate", rateSlider);
    
    addAndMakeVisible(ampSlider);
    ampSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    ampSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 20);
    ampAttachment = std::make_unique<SliderAttachment>(Reference,"uAmplitude", ampSlider);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
}

SimpleTremoloAudioProcessorEditor::~SimpleTremoloAudioProcessorEditor()
{
}

//==============================================================================
void SimpleTremoloAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (30.0f);
    g.drawFittedText ("Trem Ace", getLocalBounds(), juce::Justification::centred, 1);
}

void SimpleTremoloAudioProcessorEditor::resized()
{
    rateSlider.setBounds(10, 150, 120, 120);
    ampSlider.setBounds(300, 150, 120, 120);
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
