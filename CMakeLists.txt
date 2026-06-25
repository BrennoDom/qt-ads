cmake_minimum_required(VERSION 3.16)
project(ads_qt_monitor LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

option(USE_TWINCAT_ROUTER "Use TwinCAT Router backend" ON)

set(TWINCAT_ADS_INCLUDE
  ${CMAKE_CURRENT_SOURCE_DIR}/include/twincat_ads
)

if(WIN32)
  set(TWINCAT_ADS_LIB
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/twincat_ads/win/TcAdsDll.lib
  )
  set(TWINCAT_ADS_DLL
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/twincat_ads/win/TcAdsDll.dll
  )
else()
  set(TWINCAT_ADS_LIB
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/twincat_ads/linux/libTcAdsDll.so
  )
endif()

add_subdirectory(ADS EXCLUDE_FROM_ALL)

if(USE_TWINCAT_ROUTER)
  message(STATUS "ADS backend: TwinCAT Router")

  target_compile_definitions(ads PRIVATE USE_TWINCAT_ROUTER)

  target_include_directories(ads SYSTEM PRIVATE
    ${TWINCAT_ADS_INCLUDE}
  )

  target_link_libraries(ads PRIVATE
    ${TWINCAT_ADS_LIB}
  )

  get_target_property(ADS_SOURCES ads SOURCES)

  if(NOT ADS_SOURCES)
    message(FATAL_ERROR "Could not read sources from target ads")
  endif()

  set(ADS_SOURCES_PATCHED ${ADS_SOURCES})

  # Remove qualquer source standalone do target vendor
  list(FILTER ADS_SOURCES_PATCHED EXCLUDE REGEX "(^|.*/)standalone/.*\\.cpp$")

  # Evita duplicar caso já exista
  list(FILTER ADS_SOURCES_PATCHED EXCLUDE REGEX "(^|.*/)TwinCAT/AdsLib\\.cpp$")

  # Adiciona backend TwinCAT Router
  list(APPEND ADS_SOURCES_PATCHED
    ${CMAKE_CURRENT_SOURCE_DIR}/ADS/AdsLib/TwinCAT/AdsLib.cpp
  )

  set_property(TARGET ads PROPERTY SOURCES ${ADS_SOURCES_PATCHED})
endif()

add_executable(ads_qt_monitor
  main.cpp
  plc_client.cpp
  plc_monitor_window.cpp
  bhf_registry.cpp
  bhf_struct_tree.cpp
  standard_types.cpp
)

target_include_directories(ads_qt_monitor PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/ADS/AdsLib
  ${TWINCAT_ADS_INCLUDE}
)

if(USE_TWINCAT_ROUTER)
  target_compile_definitions(ads_qt_monitor PRIVATE USE_TWINCAT_ROUTER)
endif()

target_link_libraries(ads_qt_monitor PRIVATE
  Qt6::Widgets
  ads
  ${TWINCAT_ADS_LIB}
)

if(UNIX AND NOT APPLE)
  target_link_libraries(ads_qt_monitor PRIVATE pthread)

  set_target_properties(ads_qt_monitor PROPERTIES
    BUILD_RPATH "${CMAKE_CURRENT_SOURCE_DIR}/lib/twincat_ads/linux"
  )
endif()

if(WIN32 AND USE_TWINCAT_ROUTER)
  add_custom_command(TARGET ads_qt_monitor POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      ${TWINCAT_ADS_DLL}
      $<TARGET_FILE_DIR:ads_qt_monitor>
  )
endif()
