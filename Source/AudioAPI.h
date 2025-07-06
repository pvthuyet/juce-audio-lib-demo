/*
  ==============================================================================

    AudioAPI.h
    Created: 6 Jul 2025 7:29:13am
    Author:  thuyet

  ==============================================================================
*/

#pragma once

// Expose C interface for easy usage from other languages, e.g. Python, C#, etc.
#if defined(_WIN32)
#define AUDIOPLAYBACKLIBRARY_API __declspec(dllexport)
#else
#define AUDIOPLAYBACKLIBRARY_API __attribute__((visibility("default")))
#endif

extern "C" {

// Opaque handle to the player instance
typedef void* AudioPlayerHandle;

// Setup environment
AUDIOPLAYBACKLIBRARY_API void initEnv();

// Create a new audio player instance
AUDIOPLAYBACKLIBRARY_API AudioPlayerHandle createAudioPlayer();

// Load an audio file (wav/mp3, etc.)
AUDIOPLAYBACKLIBRARY_API bool loadAudioFile(AudioPlayerHandle player, const char* path);

// Start playback
AUDIOPLAYBACKLIBRARY_API void playAudio(AudioPlayerHandle player);

// Pause playback
AUDIOPLAYBACKLIBRARY_API void pauseAudio(AudioPlayerHandle player);

// Stop playback
AUDIOPLAYBACKLIBRARY_API void stopAudio(AudioPlayerHandle player);

// Set playback position in seconds
AUDIOPLAYBACKLIBRARY_API void setPosition(AudioPlayerHandle player, double seconds);

// Get playback position in seconds
AUDIOPLAYBACKLIBRARY_API double getPosition(AudioPlayerHandle player);

// Release and destroy the player instance
AUDIOPLAYBACKLIBRARY_API void destroyAudioPlayer(AudioPlayerHandle player);

}