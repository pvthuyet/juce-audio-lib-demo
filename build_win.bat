cmake -B build-win -DCMAKE_BUILD_TYPE=Debug
cmake --build build-win --target AudioLibDemo
cmake --install build-win --config Debug --prefix bin