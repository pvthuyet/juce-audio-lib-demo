#include <iostream>
#include "AudioDLL.h"
#include <thread>

int main()
{
    std::cout << "Start playing wav by JUCE library\n";
    initEnv();
    AudioPlayerHandle player = createAudioPlayer();
    loadAudioFile(player, "D:/projects/jasdeep/audiolib/test/file_example_WAV_1MG.wav");
    playAudio(player);
    
    std::cout << "Press Enter to exit..." << std::endl;
    std::cin.get();  // Waits until Enter is pressed

    destroyAudioPlayer(player);

    std::cout << "Hello \n";
    return 0;
}