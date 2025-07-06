cmake_minimum_required(VERSION 3.10)
project(TestAudioDLL)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(TestAudioDLL main.cpp)
set(INC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../Source")
set(BIN_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../Builds/VisualStudio2022/x64/Debug/Dynamic Library")

target_include_directories(TestAudioDLL PUBLIC
    ${INC_DIR}
    )

target_link_libraries(TestAudioDLL PUBLIC
    ${BIN_DIR}/AudioLibDemo.lib
    )

# Optional: Copy DLL to output directory after build
add_custom_command(TARGET TestAudioDLL POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${BIN_DIR}/AudioLibDemo.dll"
    $<TARGET_FILE_DIR:TestAudioDLL>
)