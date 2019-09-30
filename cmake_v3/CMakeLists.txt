# CMake 最低版本号要求
cmake_minimum_required(VERSION 2.8)
# 项目信息
# 它会引入两个变量 demo_BINARY_DIR 和 demo_SOURCE_DIR
# cmake 自动定义了两个等价的变量 PROJECT_BINARY_DIR 和 PROJECT_SOURCE_DIR。
project(demo)
# 加入一个配置头文件，用于处理CMake对源码的设置
# 加入配置头文件config.h,这个文件由cmake从config.h.in生成
# 通过该机制，可以通过预定义一些参数和变量来控制代码的生成
configure_file(
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
)
# 是否使用自己的MathFunctions库
option(USE_MYMATH
        "Use provided math implemetation" ON)
# 是否加入MathFucntions库
if(USE_MYMATH)
    include_directories("${PROJECT_SOURCE_DIR}/math")
    add_subdirectory(math)
    set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif(USE_MYMATH)
# 发现一个目录下所有的源代码文件并将列表存储在一个变量中
aux_source_directory(. DIR_SRCS)  # 搜索当前目录下的所有.cpp文件
# 指定生成目标
add_executable(demo ${DIR_SRCS})
# 添加链接库
target_link_libraries(demo MathFunctions)
