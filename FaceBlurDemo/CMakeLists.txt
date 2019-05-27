cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(FaceBlurDemo LANGUAGES CXX)

add_executable(FaceBlurDemo
        faceblurdemo.cpp)

target_include_directories(FaceBlurDemo PUBLIC
        ../FaceProcessingLib/
        )

target_link_libraries(FaceBlurDemo
        FaceProcessingLib
        boost_system
        boost_filesystem)