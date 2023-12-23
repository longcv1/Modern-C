# Cmake Tutorial
1. CMake Generator:
   - Windows: cmake -G "MinGW Makefiles" ..\src\
   - Ubuntu (if ninja installed): cmake -G "Ninja" ../src/ then run command ninja to build executable file

2. Unified build command:
   - run command: "cmake --build ."
   - this command run across build system (Windows / Linux ...)

3. Multiple files:
   - You can creat multiple CmakeLists.txt file in sub-directory of your project
   - Example: you have 2 folders (math, stats)
   - Create "CMakeLists.txt" file in folder math as below:
      "add_library(libmath STATIC math.cpp)
       target_include_directories(libmath PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)"
   - Next, create "CMakeLists.txt" file in folder stats as below:
      "add_library(libstats STATIC stats.cpp)
       target_include_directories(libstats PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
       target_link_libraries(libstats PUBLIC libmath)"
   - Then, in "CMakeLists.txt" parent as below:
      "cmake_minimum_required(VERSIOn 3.0)
       project(APP)
       add_subdirectory(src/math)
       add_subdirectory(src/stats)
       add_executable(APP main.cpp)
       target_link_libraries(APP PUBLIC libstats)

4. target_include_directories vs target_link_libraries:
   - "target_include_directories" tell CMake where to find the API header files A so you can include them from B
   - "target_link_libraries" tell cmake where to find the library's compiled code. If the library is header-only there is no need to link.

5. Command arguments:
   - message command: message("The cmake version is: ${CMAKE_VERSION}")