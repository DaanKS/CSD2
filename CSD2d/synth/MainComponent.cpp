#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{

    addAndMakeVisible(cutoffSlider);
    cutoffSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    cutoffSlider.setTextBoxStyle(juce::Slider::TextBoxLeft, true, 100, 20);

    setSize (600, 400);
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setFont (juce::Font (32.0f));
    g.setColour (juce::Colours::black);
    g.drawText ("Mr. Self Destruct!", getLocalBounds(), juce::Justification::centred, true);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    cutoffSlider.setBounds(getWidth() / 2.0f, getHeight() / 2.0f, 200, 200);
}
