cmake_minimum_required(VERSION 2.8)

project(demo)
# 发现一个目录下所有的源代码文件并将列表存储在一个变量中
aux_source_directory(. DIR_SRCS)  # 搜索当前目录下的所有.cpp文件
# 添加math子目录
add_subdirectory(math)
# 指定生成目标
add_executable(demo ${DIR_SRCS})
# 添加链接库
target_link_libraries(demo MathFunctions)
