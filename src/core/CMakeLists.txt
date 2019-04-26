# ============= ADDING MOC SUPPORT ==========
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC_ON)
set(CMAKE_AUTOUIC_ON)
set(CMAKE_AUTORCC_ON)


set(CMAKE_PREFIX_PATH D:/Programs/Qt/5.12.1/mingw73_64)
set(Qt5Widgets_DIR D:/Programs/Qt/5.12.1/mingw73_64/lib/cmake/Qt5Widgets)
set(Qt5Core_DIR D:/Programs/Qt/5.12.1/mingw73_64/lib/cmake/Qt5Core)
set(Qt5Gui_DIR D:/Programs/Qt/5.12.1/mingw73_64/lib/cmake/Qt5Gui)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
        D:/Programs/Qt/5.12.0/mingw73_64/lib/cmake/Qt5
        D:/Programs/Qt/5.12.1/mingw73_64/lib/cmake
        D:/Programs/Qt/5.12.0/mingw73_64/lib
        D:/Programs/Qt/5.12.0/mingw73_64/include
        PARENT_SCOPE)


link_directories(
        D:/Programs/Qt/5.12.0/mingw73_64/lib/cmake/Qt5
        D:/Programs/Qt/5.12.1/mingw73_64/lib/cmake
        D:/Programs/Qt/5.12.0/mingw73_64/lib
        D:/Programs/Qt/5.12.0/mingw73_64/include)


# Find Qt GUI libraries
# find_package(Qt5Core    REQUIRED)
# find_package(Qt5Widgets REQUIRED)
# find_package(Qt5Gui     REQUIRED)

find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED)
# find_package(Qt<QTVERSION> COMPONENTS Core)
# find_package(Qt<QTVERSION> COMPONENTS Widgets)
# find_package(Qt<QTVERSION> COMPONENTS Gui)


# ============= ADDING SOURCES ==========
set(CONSOLE_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/mainConsole.cpp
        )

set(GUI_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/mainGUI.cpp
        )

SET(CORE_HEADERS)

add_subdirectory(controller controller)
add_subdirectory(model model)
add_subdirectory(../console ../console)


add_executable(Labyrinth_console ${CORE_SOURCES} ${CONSOLE_SOURCES} ${CORE_HEADERS} ${CONSOLE_HEADERS})
add_executable(Labyrinth_gui ${CORE_SOURCES} ${GUI_SOURCES} ${CORE_HEADERS} ${GUI_HEADERS})


# Link Qt libraries
target_link_libraries(Labyrinth_gui Qt5::Core)
target_link_libraries(Labyrinth_gui Qt5::Widgets)
target_link_libraries(Labyrinth_gui Qt5::Gui)
target_link_libraries(Labyrinth_gui Qt5Core)
target_link_libraries(Labyrinth_gui Qt5Widgets)
target_link_libraries(Labyrinth_gui Qt5Gui)

set_target_properties(Qt5::Core PROPERTIES MAP_IMPORTED_CONFIG_COVERAGE "RELEASE")

foreach (plugin ${Qt5Network_PLUGINS})
    get_target_property(_loc ${plugin} LOCATION)
    message("Plugin ${plugin} is at location ${_loc}")
endforeach ()

# D:/Programs/Qt/5.12.1/mingw73_64/include/