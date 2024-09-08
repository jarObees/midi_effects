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
class Midi_effectsAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    Midi_effectsAudioProcessorEditor (Midi_effectsAudioProcessor&);
    ~Midi_effectsAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Midi_effectsAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Midi_effectsAudioProcessorEditor)
};
