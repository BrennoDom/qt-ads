cmake_minimum_required(VERSION 3.16)
project(ads_qt_monitor LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
add_subdirectory(ADS)

add_executable(ads_qt_monitor
  main.cpp
  plc_client.cpp
  plc_monitor_window.cpp
  tc2_mc2_types.cpp
  tc2_mc2_monitor.cpp
  standard_types.cpp
)

target_include_directories(ads_qt_monitor PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/ADS/AdsLib
  /usr/local/include
)

target_link_libraries(ads_qt_monitor PRIVATE
  Qt6::Widgets
  ads
  pthread
)

target_compile_definitions(ads_qt_monitor PRIVATE USE_TWINCAT_ROUTER)
