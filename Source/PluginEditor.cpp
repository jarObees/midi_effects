/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Midi_effectsAudioProcessorEditor::Midi_effectsAudioProcessorEditor (Midi_effectsAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 400);

    // Interval box
    harmIntervalSlider.setSliderStyle(juce::Slider::LinearBarVertical);
    harmIntervalSlider.setRange(0.0, 127.0, 1.0);
    harmIntervalSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    harmIntervalSlider.setPopupDisplayEnabled(true, false, this);
    harmIntervalSlider.setTextValueSuffix(" Intervals");
    harmIntervalSlider.setValue(1.0);

    // Add slider to editor
    addAndMakeVisible(&harmIntervalSlider);

    harmIntervalSlider.addListener(this); // LISTENER. 
}

Midi_effectsAudioProcessorEditor::~Midi_effectsAudioProcessorEditor()
{
}

//==============================================================================
void Midi_effectsAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours:: white);
    g.setColour (juce::Colours::black);
    g.setFont (juce::FontOptions (15.0f));
    g.drawFittedText ("MIDI Harmonizer", 0, 0, getWidth(), 30, juce::Justification::centred, 1);
}

void Midi_effectsAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    harmIntervalSlider.setBounds(40, 30, 20, getHeight() - 60);
}

void Midi_effectsAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    audioProcessor.harmInterval = harmIntervalSlider.getValue();
}