cmake_minimum_required(VERSION 3.0)
if (POLICY CMP0058)
	# Ninja requires custom command byproducts to be explicit
	cmake_policy(SET CMP0058 NEW)
endif()

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include(QtCommon)
include(cotire)

project(example VERSION 1.0)

fix_project_version()

# Set additional project information
set(COMPANY "Piotr Wera")
set(COPYRIGHT "Copyright (c) 2017 Piotr Wera. All rights reserved.")
#set(IDENTIFIER "com.example.Example")

set(SOURCE_FILES
    src/main.cpp
    src/mainwindow.cpp
)

add_project_meta(META_FILES_TO_INCLUDE)

set(RESOURCE_FILES example.qrc)

find_package(Qt5Widgets REQUIRED)
find_package(OpenCV REQUIRED)

add_executable(${PROJECT_NAME} ${OS_BUNDLE}
    ${SOURCE_FILES} ${META_FILES_TO_INCLUDE} ${RESOURCE_FILES}
)
cotire(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} opencv_video opencv_core opencv_objdetect opencv_imgproc  opencv_highgui opencv_calib3d )


qt5_use_modules(${PROJECT_NAME} Widgets)
