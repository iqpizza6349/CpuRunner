cmake_minimum_required(VERSION 3.21.0)
project(CpuRunner VERSION 0.1.0 LANGUAGES C CXX)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zc:__cplusplus /permissive- -D_WIN32_WINNT=0x0601")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
endif()

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
else()
    # default for linux
    set(PLATFORM "linux")
endif()

if (MSVC)
    if (CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64")
        set(PROCESSOR "msvc2019_arm64")
    else()
        set(PROCESSOR "msvc2019_64")
    endif()
elseif(MINGW)
    set(PROCESSOR "mingw_64")
else()
    set(PROCESSOR "gcc_64")
endif()

message("Compile with ${PROCESSOR}")

set(SOURCES ${SOURCES} ${CMAKE_SOURCE_DIR}/thirdparty/cpusage/CpuUsageLib/${PLATFORM}/CpuUsage.cpp)

set(Qt6_ROOT ${CMAKE_SOURCE_DIR}/thirdparty/qt/${PROCESSOR})
set(CMAKE_PREFIX_PATH "${Qt6_ROOT}" "${Qt6_ROOT}/lib/cmake/Qt6")

set(Qt6_INCLUDE_DIR ${Qt6_ROOT}/include)
set(Qt6_LIBRARY_DIR ${Qt6_ROOT}/lib)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets REQUIRED)

set(BOOST_ROOT ${CMAKE_SOURCE_DIR}/thirdparty/boost/${PLATFORM})
set(Boost_DIR "${BOOST_ROOT}")
set(Boost_INCLUDE_DIR ${BOOST_ROOT}/include)
set(Boost_LIBRARY_DIR ${BOOST_ROOT}/lib)
find_package(Boost REQUIRED COMPONENTS system filesystem)

include_directories("src/include")
include_directories(${Boost_INCLUDE_DIR})
include_directories(${Qt6Widgets_INCLUDE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/thirdparty/cpusage/include)
include_directories(${CMAKE_SOURCE_DIR}/thirdparty/ini/include)

add_executable(CpuRunner ${SOURCES})

target_link_libraries(CpuRunner PRIVATE Qt6::Core Qt6::Widgets ${Boost_LIBRARIES})

include(CPack)
