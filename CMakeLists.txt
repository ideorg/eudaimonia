cmake_minimum_required(VERSION 3.14)

project(Eudaimonia VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

if(EXISTS ${CMAKE_SOURCE_DIR}/.git)
    find_package(Git)
    if(GIT_FOUND)
        execute_process(
                COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
                WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
                OUTPUT_VARIABLE "GIT_COMMIT_HASH"
                OUTPUT_STRIP_TRAILING_WHITESPACE)
        message(STATUS "Git commit hash: ${GIT_COMMIT_HASH}")
    endif()
endif()
configure_file(cmake/version.hpp.in ${CMAKE_BINARY_DIR}/generated/version.hpp)
include_directories(${CMAKE_BINARY_DIR})

set(QT_RESOURCES
        resources.qrc
)
qt5_add_resources(RESOURCES ${QT_RESOURCES})
file(GLOB_RECURSE SRC_FILES app/*.cpp)
add_executable(Eudaimonia ${SRC_FILES} ${RESOURCES})
target_link_libraries(Eudaimonia Qt5::Widgets)