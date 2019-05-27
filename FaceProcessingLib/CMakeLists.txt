cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(FaceProcessingLib)

set(OpenCV_INCLUDES
        /usr/local/include/opencv4/
        /usr/include/opencv
        )

set(OpenCV_LIBS
        opencv_core
        opencv_imgcodecs
        opencv_features2d
        opencv_flann
        opencv_highgui
        opencv_imgproc
        opencv_ml
        opencv_objdetect
        opencv_photo
        opencv_stitching
        opencv_superres
        opencv_video
        opencv_videostab
        )

set(OpenCV_LIB_DIR
        /usr/local/lib
        )

add_library(FaceProcessingLib SHARED
        facedetector.hpp
        facedetector.cpp
        faceblur.hpp
        faceblur.cpp)

set_target_properties(FaceProcessingLib PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(FaceProcessingLib PUBLIC
        /usr/local/include/opencv4/
        )

target_link_libraries(FaceProcessingLib
        -L${OpenCV_LIB_DIR}
        ${OpenCV_LIBS}
        )


add_custom_command(TARGET FaceProcessingLib POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/resources ${CMAKE_BINARY_DIR}/bin/resources
        )