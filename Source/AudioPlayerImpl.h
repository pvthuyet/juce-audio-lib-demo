/*
  ==============================================================================

    AudioPlayerImpl.h
    Created: 6 Jul 2025 8:39:38am
    Author:  thuyet

  ==============================================================================
*/

#pragma once

#include <juce_audio_utils/juce_audio_utils.h>

class AudioPlayerImpl : public juce::AudioAppComponent
{
public:
    AudioPlayerImpl();
    ~AudioPlayerImpl() override;

    bool loadFile(const char* path);
    void play();
    void pause();
    void stop();
    void setPosition(double seconds);
    double getPosition() const;

    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;
    void releaseResources() override;
    void getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill) override;

private:
    juce::AudioFormatManager formatManager;
    juce::AudioTransportSource transportSource;
    std::unique_ptr<juce::AudioFormatReaderSource> readerSource;
};
