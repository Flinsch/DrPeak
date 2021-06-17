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
class DrPeakAudioProcessorEditor
    : public juce::AudioProcessorEditor
    , public juce::Timer
{
public:
    DrPeakAudioProcessorEditor(DrPeakAudioProcessor&);
    ~DrPeakAudioProcessorEditor() override;

    void paint(juce::Graphics&) override;
    void resized() override;

    void timerCallback() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    DrPeakAudioProcessor& audioProcessor;

private:
    juce::Label _peak_label;
    juce::TextButton _reset_button;

    juce::ComponentBoundsConstrainer constrainer;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DrPeakAudioProcessorEditor)
};
