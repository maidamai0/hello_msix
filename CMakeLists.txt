cmake_minimum_required(VERSION 3.16.0)
project(hello_msix VERSION 1.0.0.0)

include(CTest)
enable_testing()

add_executable(hello_msix main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
