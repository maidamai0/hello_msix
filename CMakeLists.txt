cmake_minimum_required(VERSION 3.16.0)
project(hello_msix VERSION 1.0.0.0)

add_executable(hello_msix main.cpp)

# generate resource  file
add_custom_target(
    generate_resource
    ALL
    COMMAND makepri createconfig /cf priconfig.xml /dq en-US /o
    COMMAND makepri new /pr . /cf priconfig.xml /o
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    DEPENDS hello_msix
    COMMENT "generate resource files"
    VERBATIM
    USES_TERMINAL
)

# Install with develop mode in powershell
# Add-AppxPackage -Register AppxManifest.xml

# remove
# Remove-AppxPackage -Package "CarestremDental.Scanflow.hello_1.0.0.0_x64__kffgs02sz7ag2"
