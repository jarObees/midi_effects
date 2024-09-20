/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/*
* Public inherits all the shits from AudioProcessorEditor, keeping the public shit public, private shit private.
* Private means that everything inherited from juce::Slider::Listener will be treated as private in this class.
*/
class Midi_effectsAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                          private juce::Slider::Listener
{
public:
    Midi_effectsAudioProcessorEditor (Midi_effectsAudioProcessor&);
    ~Midi_effectsAudioProcessorEditor() override;

    // These two functions are inherited from the AudioProcessorEditor =========== 
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    void sliderValueChanged(juce::Slider* slider) override; // Method triggered whenever the value of the slider changes.
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Midi_effectsAudioProcessor& audioProcessor;
    
    juce::Slider harmIntervalSlider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Midi_effectsAudioProcessorEditor)
};
