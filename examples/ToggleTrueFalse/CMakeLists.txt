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

add_executable(ToggleTrueFalse-example
        main.cpp
        switchbutton.ui
        )

target_link_libraries(ToggleTrueFalse-example
        PRIVATE
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        QcSwitchWidget
        )
