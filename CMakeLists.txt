cmake_minimum_required(VERSION 3.16.0)
project(hello_msix VERSION 1.0.0.0)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/pack)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/pack)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/pack)

set(CXX_STANDARD 17)

# don't know why set(CXX_STANDARD 20) don't work on my machine:msvc-2019 build tools
if(MSVC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
endif(MSVC)

add_executable(hello_msix src/main.cpp)

# generate resource  file
# test only, not required to package
add_custom_target(
    generate_resource
    COMMAND makepri createconfig /cf priconfig.xml /dq en-US /o
    COMMAND makepri new /pr . /cf priconfig.xml /o
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    DEPENDS hello_msix
    COMMENT "generate resource files..."
    VERBATIM
    USES_TERMINAL
)

# pack and sign app
add_custom_target(
    package_and_sign
    ALL
    COMMAND makeappx pack -v -d pack -p hello.msix -o
    COMMAND SignTool sign /fd SHA256 hello.msix
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    DEPENDS hello_msix
    COMMENT "package and sign app..."
    VERBATIM
    USES_TERMINAL
)