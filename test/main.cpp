#include "AudioAPI.h"
#include <thread>
#include <iostream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cout << "Usage:\n";
        std::cout << "TestAudioLib file_example_WAV_1MG.wav" << std::endl;
        return 0;
    }
    std::string f = argv[1];
    if (!fs::exists(f)) {
        std::cout << f << " - not exist\n";
        return 0;
    }

    std::cout << "Start playing wav by JUCE library\n";
    initEnv();
    AudioPlayerHandle player = createAudioPlayer();
    loadAudioFile(player, f.c_str());
    playAudio(player);
    
    std::cout << "Press Enter to exit..." << std::endl;
    std::cin.get();  // Waits until Enter is pressed

    destroyAudioPlayer(player);

    std::cout << "Hello \n";
    return 0;
}