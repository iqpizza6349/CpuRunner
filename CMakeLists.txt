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

set(SOURCES
    "src/main.cpp"
    "src/CpuRunner.cpp"
    "src/widget/RunnerWidget.cpp"
    "src/widget/UsageLabel.cpp"
    "src/options/OptionsManager.cpp"
    "thirdparty/ini/INILib/Loader.cpp"
)

if (WIN32)
    set(PLATFORM "windows")
    set(BASE_PLATFORM "windows")
elseif(APPLE)
    set(PLATFORM "macos")
    set(BASE_PLATFORM "linux")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    set(PLATFORM "macos")
    set(BASE_PLATFORM "linux")
else()
    # default for linux
    set(PLATFORM "linux")
    set(BASE_PLATFORM "linux")
endif()

set(SOURCES ${SOURCES} ${CMAKE_SOURCE_DIR}/thirdparty/cpusage/CpuUsageLib/${BASE_PLATFORM}/CpuUsage.cpp)

# Check the Qt5 is downloaded on client local
find_package(Qt5 QUIET)
if (NOT Qt5_FOUND)
    message("Cannot found Qt5 library. Use default path.. OS >> ${PLATFORM}")
    set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/thirdparty/qt/${PLATFORM})
    find_package(Qt5 REQUIRED COMPONENTS Widgets REQUIRED)
endif()

# Check the Boost is downloaded on client local
find_package(Boost QUIET)
if (NOT Boost_FOUND)
    message("Cannot found Boost library. Use default path")
    set(BOOST_ROOT ${CMAKE_SOURCE_DIR}/thirdparty/boost/${BASE_PLATFORM})
    set(CMAKE_PREFIX_PATH "${BOOST_ROOT}")
    set(Boost_INCLUDE_DIR ${BOOST_ROOT}/include)
    set(Boost_LIBRARY_DIR ${BOOST_ROOT}/lib)
    find_package(Boost REQUIRED COMPONENTS system filesystem)
endif()

include_directories("src/include")
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${Qt5Widgets_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/thirdparty/cpusage/include)
include_directories(${CMAKE_SOURCE_DIR}/thirdparty/ini/include)

add_executable(CpuRunner ${SOURCES})

target_link_libraries(CpuRunner Qt5::Widgets ${Boost_LIBRARIES})

include(CPack)
