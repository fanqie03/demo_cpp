cmake_minimum_required(VERSION 2.8)
project(untitled)

#set(CMAKE_CXX_STANDARD 14)

# 配置ncnn的链接库和头文件
set(NCNN_LIBS /home/cmf/dev/ncnn/build/install/lib/libncnn.a)
set(NCNN_INCLUDE_DIRS /home/cmf/dev/ncnn/build/install/include/ncnn)
#add_subdirectory(arcface)
file(GLOB SRC_LIST "*.cpp" "arcface/*.cpp")
# 配置opencv
find_package( OpenCV REQUIRED )
message(${OpenCV_INCLUDE_DIRS})
message(${OpenCV_LIBS})

include_directories( ${OpenCV_INCLUDE_DIRS} )
include_directories( ${NCNN_INCLUDE_DIRS} )
include_directories( arcface)

# 建立链接依赖
add_executable(untitled ${SRC_LIST})
target_link_libraries( untitled ${OpenCV_LIBS} )
target_link_libraries(untitled ${NCNN_LIBS})