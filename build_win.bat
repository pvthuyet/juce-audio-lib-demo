cmake -B android-build -DCMAKE_BUILD_TYPE=Debug
cmake --build android-build --target AudioLibDemo
cmake --install android-build --config Debug --prefix bin