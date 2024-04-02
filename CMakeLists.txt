cmake_minimum_required(VERSION 3.24)
project(game)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)

FetchContent_Declare(
    sfml
    URL https://github.com/SFML/SFML/archive/refs/tags/2.6.1.tar.gz
    URL_MD5 dbcd89cd92fa17050a9a1205207bd025
)

set(SFML_BUILD_AUDIO OFF)
set(SFML_BUILD_NETWORK OFF)

FetchContent_MakeAvailable(
    sfml
)
