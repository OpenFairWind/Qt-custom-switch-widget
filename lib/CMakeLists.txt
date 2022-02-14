set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 REQUIRED COMPONENTS
        Core
        Gui
        Widgets
        )

set(QCSWITCHWIDGET_RESOURCE qcswitchwidget.qrc)
qt5_add_resources(QCSWITCHWIDGET_RESOURCE_ADDED ${QCSWITCHWIDGET_RESOURCE})

add_library(qcswitchwidget SHARED
        include/qcswitchwidget.hpp
        src/qcswitchwidget.cpp
        ${QCSWITCHWIDGET_RESOURCE_ADDED}
        )

target_include_directories(qcswitchwidget
        PUBLIC
        include
        PRIVATE
        include/qcswitchwidget
        )

target_compile_definitions(qcswitchwidget
        PRIVATE
        QCSWUTCH_COMPILE_LIBRARY
        )

target_link_libraries(qcswitchwidget
        PRIVATE
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

add_library(QcSwitchWidget ALIAS qcswitchwidget)

install(TARGETS qcswitchwidget LIBRARY
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static
        )

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
        DESTINATION include
        FILES_MATCHING PATTERN "*.h*"
        )