cmake_minimum_required(VERSION 3.25)
project(sfml_template)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)

FetchContent_Declare(sfml
    URL https://github.com/SFML/SFML/archive/refs/tags/3.0.0.tar.gz
    URL_HASH MD5=631426f02fb46ccefc896975f9c44c7f
    EXCLUDE_FROM_ALL SYSTEM)

FetchContent_MakeAvailable(
    sfml
)

add_executable(sfml_template
    src/Main.cpp
)

target_compile_features(sfml_template PUBLIC
    cxx_std_20
)

target_link_libraries(sfml_template
    PRIVATE SFML::Graphics
)
