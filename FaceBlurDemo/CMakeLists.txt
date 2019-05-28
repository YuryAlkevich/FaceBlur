cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(FaceBlurDemo LANGUAGES CXX)

set(CMAKE_VERBOSE_MAKEFILE ON)

add_executable(FaceBlurDemo
        faceblurdemo.cpp
        faceserializer.hpp
        faceserializer.cpp
        )

target_include_directories(FaceBlurDemo PUBLIC
        ../ThirdParty/boost/include
        ../FaceProcessingLib/
        )

target_link_libraries(FaceBlurDemo
        FaceProcessingLib
        -L${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/boost/lib/linux
        boost_system
        boost_filesystem)

add_custom_command(TARGET FaceBlurDemo POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/boost/lib/linux ${CMAKE_BINARY_DIR}/bin/
        )