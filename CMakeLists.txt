cmake_minimum_required(VERSION 3.0.0)
project(MODERNC VERSION 0.1.0 LANGUAGES C CXX)

# Not recommended
#file(GLOBAL_RECURSE SOURCE_FILE src/*.cpp)
#add_executable(APP main.cpp ${SOURCE_FILES})

# List your source files
add_executable(MODERNC main.cpp
                     src/source/dog.cpp
                     #folder/operations.cpp
               )
target_compile_features(MODERNC PRIVATE cxx_std_20)
target_include_directories(MODERNC PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/include)

