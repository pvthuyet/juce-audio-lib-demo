cmake -B build-android -G Ninja -DCMAKE_TOOLCHAIN_FILE="D:/Program Files/Android/android-ndk-r27c/build/cmake/android.toolchain.cmake" -DANDROID_ABI=arm64-v8a -DANDROID_PLATFORM=android-32 -DCMAKE_BUILD_TYPE=Debug -DCMAKE_POLICY_VERSION_MINIMUM=3.5
cmake --build build-android --config Debug --target AudioLibDemo
cmake --install build-android --config Debug --prefix bin