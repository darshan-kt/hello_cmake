# Project name and version
project(hello_cmake)

# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directory
include_directories(include)

# Find OpenCV
find_package(OpenCV REQUIRED)

# Add the executable target
add_executable(main_exec src/main.cpp
                        src/utils.cpp 
                        src/helper.cpp)


# Gather only the OpenCV-related source file
set(OPENCV_SOURCE "src/image_view.cpp")

# Add OpenCV executable
add_executable(ImageViewer ${OPENCV_SOURCE})
target_link_libraries(ImageViewer ${OpenCV_LIBS})