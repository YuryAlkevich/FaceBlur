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

if(WIN32)
        add_compile_definitions(BOOST_ALL_DYN_LINK)

        set(BOOST_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/boost/lib/win)

        set(CMAKE_EXE_LINKER_FLAGS
                "/LIBPATH:${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/opencv/lib/win /LIBPATH:${BOOST_LIB_DIR}"
                )

        set(BOOST_LIBS
                boost_system-vc141-mt-x32-1_70
                boost_filesystem-vc141-mt-x32-1_70
                )

else()
        set(BOOST_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/boost/lib/linux)

        set(BOOST_LIBS
                -L${BOOST_LIB_DIR}
                boost_system
                boost_filesystem
                )
endif()

target_link_libraries(FaceBlurDemo
        FaceProcessingLib
        ${BOOST_LIBS}
        )

add_custom_command(TARGET FaceBlurDemo POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${BOOST_LIB_DIR} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
        )