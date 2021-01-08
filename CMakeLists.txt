cmake_minimum_required(VERSION 3.16.0)
project(hello_msix VERSION 1.0.0.0)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/pack)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/pack)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/pack)

add_executable(hello_msix main.cpp)

# generate resource  file
add_custom_target(
    generate_resource
    ALL
    COMMAND makepri createconfig /cf priconfig.xml /dq en-US /o
    COMMAND makepri new /pr . /cf priconfig.xml /o
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    DEPENDS hello_msix
    COMMENT "generate resource files..."
    VERBATIM
    USES_TERMINAL
)


# generate resource  file
add_custom_target(
    package
    ALL
    COMMAND makeappx pack -v -nv -nfv -d pack -p hello.msix -o
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    DEPENDS generate_resource
    COMMENT "packag..."
    VERBATIM
    USES_TERMINAL
)


# Install with develop mode in powershell
# Add-AppxPackage -Register AppxManifest.xml

# remove
# Remove-AppxPackage -Package "CarestremDental.Scanflow.hello_1.0.0.0_x64__kffgs02sz7ag2"

# package
# makeappx pack -v -d pack -p hello.msix -o