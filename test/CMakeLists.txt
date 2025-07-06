# Add the executable
add_executable(TestAudioLib main.cpp)
set(INC_DIR "${CMAKE_SOURCE_DIR}/Source")
set(BIN_DIR "${CMAKE_SOURCE_DIR}/bin")

target_include_directories(TestAudioLib PUBLIC
    ${INC_DIR}
    )

target_link_libraries(TestAudioLib PUBLIC
    sg::audiolibdemo
    )

# Optional: Copy DLL to output directory after build
add_custom_command(TARGET TestAudioLib POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${BIN_DIR}/"
    $<TARGET_FILE_DIR:AudioLibDemo>
)