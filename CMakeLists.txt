cmake_minimum_required(VERSION 3.5.0)
project(CpuRunner VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOMCC ON)
set(CMAKE_AUTOMIC ON)

if (CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(CpuRunner 
    "src/main.cpp"
)

add_library(CpuLibrary 
    "src/cpusage.h" 
    "src/cpusage.cpp"
    "src/widget/CharacterWidget.h"
    "src/widget/CharacterWidget.cpp"
)

include_directories(${Qt5Widgets_INCLUDE_DIRS})
target_link_libraries(CpuRunner CpuLibrary Qt5::Widgets)

include(CPack)
