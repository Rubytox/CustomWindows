cmake_minimum_required(VERSION 3.16)
project(HandmadeHero)

set(CMAKE_CXX_STANDARD 20)

add_executable(CustomWindows WIN32 main.cpp Logger.cpp Logger.h OffscreenBuffer.cpp OffscreenBuffer.h)