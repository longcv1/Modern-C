cmake_minimum_required(VERSION 3.5)
project(MyApp VERSION 0.1.0 LANGUAGES CXX)

# Not recommended
#file(GLOBAL_RECURSE SOURCE_FILE src/*.cpp)
#add_executable(APP main.cpp ${SOURCE_FILES})

# List your source files
# add_executable(MODERNC main.cpp
#                      sources/dog.cpp
#                      #folder/operations.cpp
#                )

add_library(SharedLib SHARED sources/dog.cpp)
add_executable(MyApp main.cpp)

target_compile_features(MyApp PRIVATE cxx_std_20)
target_link_libraries(MyApp SharedLib)
#target_include_directories(MODERNC PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/headers)
#target_link_libraries(MODERNC PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/headers)

