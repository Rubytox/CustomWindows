cmake_minimum_required(VERSION 3.16)
project(HandmadeHero)

set(CMAKE_CXX_STANDARD 20)

add_executable(CustomWindows WIN32 src/main.cpp src/util/Logger.cpp src/util/Logger.h src/buffer/OffscreenBuffer.cpp src/buffer/OffscreenBuffer.h src/util/ModularInt.cpp src/util/ModularInt.h)