set(CMAKE_CXX_STANDARD 11)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 REQUIRED COMPONENTS
        Core
        Gui
        Widgets
        )

add_executable(Basic-example
        main.cpp
        mainwindow.hpp
        mainwindow.cpp
        mainwindow.ui
        )

target_link_libraries(Basic-example
        PRIVATE
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        QcSwitchWidget
        )