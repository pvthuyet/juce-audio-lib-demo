/*
  ==============================================================================

    AudioPlayerImpl.cpp
    Created: 6 Jul 2025 8:39:53am
    Author:  thuyet

  ==============================================================================
*/

#include "AudioPlayerImpl.h"

AudioPlayerImpl::AudioPlayerImpl()
{
    formatManager.registerBasicFormats();
    setAudioChannels(0, 2);
}

AudioPlayerImpl::~AudioPlayerImpl()
{
    shutdownAudio();
}

bool AudioPlayerImpl::loadFile(const char* path)
{
    std::unique_ptr<juce::AudioFormatReader> reader(
        formatManager.createReaderFor(juce::File(path)));
    if (!reader)
        return false;

    std::unique_ptr<juce::AudioFormatReaderSource> newSource(new juce::AudioFormatReaderSource(reader.release(), true));
    transportSource.setSource(newSource.get(), 0, nullptr, newSource->getAudioFormatReader()->sampleRate);
    readerSource = std::move(newSource);
    return true;
}

void AudioPlayerImpl::play() { transportSource.start(); }
void AudioPlayerImpl::pause() { transportSource.stop(); }
void AudioPlayerImpl::stop() { transportSource.stop(); transportSource.setPosition(0.0); }
void AudioPlayerImpl::setPosition(double seconds) { transportSource.setPosition(seconds); }
double AudioPlayerImpl::getPosition() const { return transportSource.getCurrentPosition(); }

void AudioPlayerImpl::prepareToPlay(int samplesPerBlockExpected, double sampleRate)
{
    transportSource.prepareToPlay(samplesPerBlockExpected, sampleRate);
}

void AudioPlayerImpl::releaseResources()
{
    transportSource.releaseResources();
}

void AudioPlayerImpl::getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill)
{
    transportSource.getNextAudioBlock(bufferToFill);
}
