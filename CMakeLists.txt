cmake_minimum_required(VERSION 3.16)

project(ProjektCPP VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui Widgets Sql)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    adminwindow.cpp
    adminwindow.h
    adminwindow.ui
    subjectswindow.h
    subjectswindow.cpp
    subjectswindow.ui
    employeeswindow.h
    employeeswindow.cpp
    employeeswindow.ui
    studentswindow.h
    studentswindow.cpp
    studentswindow.ui
    assignstudentswindow.h
    assignstudentswindow.cpp
    assignstudentswindow.ui
    studentwindow.h
    studentwindow.cpp
    studentwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ProjektCPP
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        employeewindow.h employeewindow.cpp employeewindow.ui
    )
else()
    if(ANDROID)
        add_library(ProjektCPP SHARED ${PROJECT_SOURCES})
    else()
        add_executable(ProjektCPP ${PROJECT_SOURCES})
    endif()
endif()

target_link_libraries(ProjektCPP PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql)

set_target_properties(ProjektCPP PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS ProjektCPP
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ProjektCPP)
endif()
