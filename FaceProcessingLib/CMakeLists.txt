cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(FaceProcessingLib)

set(OpenCV_INCLUDES
        ../ThirdParty/opencv/include
        )

if(WIN32)
        set(OpenCV_LIBS
                opencv_core410
                opencv_imgcodecs410
                opencv_imgproc410
                opencv_objdetect410
        )

        set(CMAKE_SHARED_LINKER_FLAGS /LIBPATH:${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/opencv/lib/win)
        set(OpenCV_LIB_DIR
        ${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/opencv/lib/win)
else()
        set(OpenCV_LIBS
        opencv_core
        opencv_imgcodecs
        opencv_imgproc
        opencv_objdetect
        )

        #link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/opencv/lib/linux)
        set(OpenCV_LIB_DIR
        ${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/opencv/lib/linux)
endif()


add_library(FaceProcessingLib SHARED
        facedetector.hpp
        facedetector.cpp
        faceblur.hpp
        faceblur.cpp
        libdefines.hpp
        )

set_target_properties(FaceProcessingLib PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(FaceProcessingLib PUBLIC
        ../ThirdParty/opencv/include
        )

target_link_libraries(FaceProcessingLib
        ${OpenCV_LIB_DIR}
        ${OpenCV_LIBS}
        )


add_custom_command(TARGET FaceProcessingLib POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/resources ${CMAKE_BINARY_DIR}/bin/resources
        )

add_custom_command(TARGET FaceProcessingLib POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${OpenCV_LIB_DIR} ${CMAKE_BINARY_DIR}/bin/
        )