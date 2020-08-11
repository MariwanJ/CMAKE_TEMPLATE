# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.1)

# Project name
project(MyProject)

set(CMAKE_CXX_STANDARD 11)  # enable C++11 standard
# set the icon resource for the exe file
set(WIN_RESOURCE_FILE "${PROJECT_SOURCE_DIR}/src/MyProject.rc")



#Uncomment if you wish to require any library for ex OpenGL
#find_package(OpenGL REQUIRED)

# Include directories .. 
include_directories(
        ${PROJECT_SOURCE_DIR}/include
         ${PROJECT_SOURCE_DIR}/src
)
# All source codes.
file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/*.cxx"
        "${PROJECT_SOURCE_DIR}/src/*.c"
        "${PROJECT_SOURCE_DIR}/src/*.cc"
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/include/*.hpp"
       )
       
#pack name.
set(CPACK_PACKAGE_NAME "CPackMyProjectInstaller")
set(CPACK_PACKAGE_VENDOR "Mariwan Jalal")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Example showing CPack in action")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_PACKAGE_VERSION "${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH}")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "CPackMyProject")

add_executable(MyProject ${all_SRCS} ${WIN_RESOURCE_FILE})

#add_executable( MyProject ${MyProject_SRCS} ${WIN_RESOURCE_FILE})

#
# Install the executable (belongs in the "applications" component)
#
install(TARGETS MyProject
        RUNTIME
        DESTINATION programs
        COMPONENT applications)

include(CPack)