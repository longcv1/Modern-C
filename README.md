# Cmake Tutorial
1. CMake Generator:
   - Windows: cmake -G "MinGW Makefiles" ..\src\
   - Ubuntu (if ninja installed): cmake -G "Ninja" ../src/ then run command ninja to build executable file

2. Unified build command:
   - run command: "cmake --build ."
   - this command run across build system (Windows / Linux ...)

3. Multiple files:
   - 