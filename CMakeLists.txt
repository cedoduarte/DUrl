cmake_minimum_required(VERSION 3.14)

project(durl LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Network)

add_executable(durl
  main.cpp
  qflexiblejsonobject.cpp
  qflexiblejsonobject.h
  qnetaccessmanager.cpp
  qnetaccessmanager.h
  qnetrequest.cpp
  qnetrequest.h
  durl.h durl.cpp
)

target_link_libraries(durl Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(durl Qt${QT_VERSION_MAJOR}::Network)

install(TARGETS durl
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
