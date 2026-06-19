cmake_minimum_required(VERSION 3.19)
project(TrigonometryViewerQT LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Charts)

qt_standard_project_setup()

qt_add_executable(TrigonometryViewerQT
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    qcustomplot.h
    qcustomplot.cpp
)

target_link_libraries(TrigonometryViewerQT
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Charts
        Qt::PrintSupport
)

install(TARGETS TrigonometryViewerQT
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET TrigonometryViewerQT
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
