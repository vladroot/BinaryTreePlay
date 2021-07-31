cmake_minimum_required(VERSION 3.0.0)
project(BinaryTreePlay VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(
    TreeNode STATIC
    src/TreeNode.h
    src/TreeNode.c)

add_executable(${PROJECT_NAME} main.c)

target_link_libraries(${PROJECT_NAME} TreeNode)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
