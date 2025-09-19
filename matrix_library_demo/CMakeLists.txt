cmake_minimum_required(VERSION 3.16)
project(matrix_library_demo)
# 全局 C++ 标准
set(CMAKE_CXX_STANDARD 17)


# ------------------------- 变量与路径 -------------------------
# 头⽂件⽬录（PUBLIC 供下游⽬标继承）
set(Matrix_INC_DIR ${CMAKE_SOURCE_DIR}/include)
# 源⽂件⽬录
set(Matrix_SRC_DIR ${CMAKE_SOURCE_DIR}/src)
# ------------------------- 收集源⽂件 -------------------------
# ⼿动列出或 file(GLOB ...) 均可；⼿动更稳健
set(Matrix_SOURCES
 ${Matrix_SRC_DIR}/main.cpp
 ${Matrix_SRC_DIR}/matrix.cpp
 # ${TWO_SRC_DIR}/other.cpp # 以后直接加
)
# ------------------------- 可执⾏⽬标 -------------------------
add_executable(Matrix ${Matrix_SOURCES})
# 头⽂件搜索路径
target_include_directories(Matrix
 PUBLIC
 $<BUILD_INTERFACE:${Matrix_INC_DIR}>
 $<INSTALL_INTERFACE:include>)