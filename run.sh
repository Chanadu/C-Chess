mkdir build
cd build

cmake --no-warn-unused-cli \
      -DCMAKE_BUILD_TYPE:STRING=Debug \
      -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE \
      -DCMAKE_C_COMPILER:FILEPATH=/usr/bin/gcc \
      ..

make && ./C-Chess

