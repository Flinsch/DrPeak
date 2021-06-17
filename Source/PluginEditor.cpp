/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DrPeakAudioProcessorEditor::DrPeakAudioProcessorEditor(DrPeakAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p)
{
    const int W = 120;
    const int H = 60;

    _peak_label.setJustificationType(juce::Justification::centred);
    this->addAndMakeVisible(_peak_label);

    _reset_button.setButtonText("Reset");
    _reset_button.onClick = [this] { audioProcessor.reset_volume_stats(); this->repaint(); };
    this->addAndMakeVisible(_reset_button);

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize(W, H);

    constrainer.setSizeLimits(W, H, W, H);
    this->setConstrainer(&constrainer);

    this->startTimerHz(10);
}

DrPeakAudioProcessorEditor::~DrPeakAudioProcessorEditor()
{
}

//==============================================================================
void DrPeakAudioProcessorEditor::paint(juce::Graphics& g)
{
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
}

void DrPeakAudioProcessorEditor::resized()
{
    const int W = getWidth();
    const int H = getHeight();

    _peak_label.setBounds(juce::Rectangle<int>(100, 20).withCentre({ W / 2, H / 2 - 10 }));
    _reset_button.setBounds(juce::Rectangle<int>(100, 20).withCentre({ W / 2, H / 2 + 10 }));
}

void DrPeakAudioProcessorEditor::timerCallback()
{
    const VolumeStats& volume_stats = audioProcessor.get_volume_stats();

    float peak = volume_stats.peak;
    if (peak < 0.00001f) peak = 0.0f;

    _peak_label.setText(juce::StringRef("Peak: ") + juce::String(peak), juce::NotificationType::sendNotificationAsync);
}
