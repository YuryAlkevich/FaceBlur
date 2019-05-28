cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(Tests)

add_executable(runTests
        testfacedetector.cpp
        )

target_include_directories(runTests PUBLIC
        ../FaceProcessingLib/
        ../ThirdParty/googletest-release-1.8.1/googletest/include
        )

target_link_libraries(runTests
        FaceProcessingLib
        gtest
        gtest_main
        )

add_custom_command(TARGET runTests POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/testdata ${CMAKE_BINARY_DIR}/bin/testdata
        )