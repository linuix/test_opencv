cmake_minimum_required(VERSION 3.4.1)
project(test_opencv)
set(CMAKE_CXX_STANDARD 11)

# include_directories(./include)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
message("OpenCV_INCLUDE_DIRS = "${OpenCV_INCLUDE_DIRS})

message("OpenCV_LIBS = "${OpenCV_LIBS})
add_executable(
    ${PROJECT_NAME}
    src/test_opencv.cpp
)

target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} )

include_directories(include)
add_executable(
        image_zoom_test
        src/image_zoom_test.cpp
)
target_link_libraries(
        image_zoom_test
        ${OpenCV_LIBS} )

add_executable(
        bit_image_test
        src/bit_image_test.cpp
)
target_link_libraries(
        bit_image_test
        ${OpenCV_LIBS} 
        )
