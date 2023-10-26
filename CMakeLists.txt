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
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

if (CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)

if (!Boost_FOUND)
    message(FATAL_ERROR "Boost libraries not found. Please install them.")
endif()

set(SOURCES
    "src/main.cpp"
    "src/widget/RunnerWidget.cpp"
    "src/widget/UsageLabel.cpp"
    "thirdparty/cpusage/CpuUsageLib/CpuUsage.cpp"
    "thirdparty/ini/INILib/Loader.cpp"
)

include_directories("src/include")
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${Qt5Widgets_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/thirdparty/cpusage/include)
include_directories(${CMAKE_SOURCE_DIR}/thirdparty/ini/include)

add_library(CpuRunnerLibrary STATIC ${SOURCES})

add_executable(CpuRunner 
    "src/main.cpp"
)

target_link_libraries(CpuRunner CpuRunnerLibrary Qt5::Widgets ${Boost_LIBRARIES})

include(CPack)
