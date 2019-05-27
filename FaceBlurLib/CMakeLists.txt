cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(FaceBlurLib)

set(CMAKE_VERBOSE_MAKEFILE ON)

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

add_library(FaceBlurLib SHARED
        faceblur.hpp
        faceblur.cpp)

set_target_properties(FaceBlurLib PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(FaceBlurLib PUBLIC
        /usr/local/include/opencv4/
        )

target_link_libraries(FaceBlurLib
        -L${OpenCV_LIB_DIR}
        ${OpenCV_LIBS}
        )