cmake_minimum_required(VERSION 2.8)
project(untitled)

#set(CMAKE_CXX_STANDARD 14)

# 配置ncnn的链接库和头文件
set(NCNN_LIBS /home/cmf/dev/ncnn/build/install/lib/libncnn.a)
set(NCNN_INCLUDE_DIRS /home/cmf/dev/ncnn/build/install/include/ncnn)
#add_subdirectory(arcface)
file(GLOB SRC_LIST "jni.cpp" "arcface/*.cpp")
# 配置opencv
find_package(OpenCV REQUIRED)
message(${OpenCV_INCLUDE_DIRS})
message(${OpenCV_LIBS})

#添加openmp
FIND_PACKAGE( OpenMP REQUIRED)
if(OPENMP_FOUND)
    message("OPENMP FOUND")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${NCNN_INCLUDE_DIRS})
include_directories(arcface)

# 建立链接依赖
add_executable(main ${SRC_LIST} "main.cpp")
target_link_libraries(main ${OpenCV_LIBS})
target_link_libraries(main ${NCNN_LIBS})

add_executable(compare ${SRC_LIST} "compare.cpp")
target_link_libraries(compare ${OpenCV_LIBS})
target_link_libraries(compare ${NCNN_LIBS})

add_executable(scale_test scale_test.cpp)