/*
  ==============================================================================

    AudioAPI.cpp
    Created: 6 Jul 2025 7:27:50am
    Author:  thuyet

  ==============================================================================
*/

#include "AudioAPI.h"
#include "AudioPlayerImpl.h"
#include <memory>

// C API implementation
extern "C" {

void initEnv()
{
    juce::ScopedJuceInitialiser_GUI{};
}

AudioPlayerHandle createAudioPlayer()
{
    return new AudioPlayerImpl();
}

bool loadAudioFile(AudioPlayerHandle handle, const char* path)
{
    if (!handle) return false;
    return static_cast<AudioPlayerImpl*>(handle)->loadFile(path);
}

void playAudio(AudioPlayerHandle handle)
{
    if (!handle) return;
    static_cast<AudioPlayerImpl*>(handle)->play();
}

void pauseAudio(AudioPlayerHandle handle)
{
    if (!handle) return;
    static_cast<AudioPlayerImpl*>(handle)->pause();
}

void stopAudio(AudioPlayerHandle handle)
{
    if (!handle) return;
    static_cast<AudioPlayerImpl*>(handle)->stop();
}

void setPosition(AudioPlayerHandle handle, double seconds)
{
    if (!handle) return;
    static_cast<AudioPlayerImpl*>(handle)->setPosition(seconds);
}

double getPosition(AudioPlayerHandle handle)
{
    if (!handle) return 0.0;
    return static_cast<AudioPlayerImpl*>(handle)->getPosition();
}

void destroyAudioPlayer(AudioPlayerHandle handle)
{
    if (!handle) return;
    delete static_cast<AudioPlayerImpl*>(handle);
}

}