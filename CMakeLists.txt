cmake_minimum_required(VERSION 3.14)

project(Eudaimonia VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(QT_RESOURCES
        resources.qrc
)
qt5_add_resources(RESOURCES ${QT_RESOURCES})
file(GLOB_RECURSE SRC_FILES app/*.cpp)
add_executable(Eudaimonia ${SRC_FILES} ${RESOURCES})
target_link_libraries(Eudaimonia Qt5::Widgets)