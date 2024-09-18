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
				auto harmMessage = currentMessage;
				
				auto oldNoteNum = harmMessage.getNoteNumber();
				harmMessage.setNoteNumber(oldNoteNum + interval);

				processedBuffer.addEvent(harmMessage, samplePos);
			}
			processedBuffer.addEvent(currentMessage, samplePos);
		}
		midiMessages.swapWith(processedBuffer);
	}
	juce::MidiBuffer processedBuffer;
	int interval = 4; 

};