#pragma once
#include "JuceHeader.h"


class MidiProcessor
{
public:
	void process(juce::MidiBuffer& midiMessages)
	{
		processedBuffer.clear();

		for (const auto meta: midiMessages)
		{
			auto currentMessage = meta.getMessage(); // Copy of curent midiMessage.
			auto samplePos = meta.samplePosition;
			if (currentMessage.isNoteOnOrOff()) // Midi sends in a lot of junk so make sure
			{
				DBG("MIDI NOTE MESSAGE RECEIVED " << "OLD NOTE: " << currentMessage.getMidiNoteName(currentMessage.getNoteNumber(), true, true, 3));
				currentMessage.setNoteNumber(50); // you're only targeting note on/off messages.
				DBG("NEW NOTE: " << currentMessage.getMidiNoteName(currentMessage.getNoteNumber(), true, true, 3));
				processedBuffer.addEvent(currentMessage, samplePos);
			}
		}
		midiMessages.swapWith(processedBuffer);
	}
	juce::MidiBuffer processedBuffer;
};