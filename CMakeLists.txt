cmake_minimum_required(VERSION 3.30)
project(sfml_template)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)

FetchContent_Declare(sfml
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON EXCLUDE_FROM_ALL SYSTEM)

FetchContent_MakeAvailable(sfml)

add_executable(sfml_template
    src/Main.cpp
)

target_link_libraries(sfml_template
    PRIVATE SFML::Graphics
)