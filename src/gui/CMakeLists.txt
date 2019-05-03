# ============= ADDING SOURCES ==========
set(SOURCE
        ${SOURCE}
        ${CMAKE_CURRENT_SOURCE_DIR}/source/guiView.cpp
        PARENT_SCOPE
        )

set(HEADERS
        ${HEADERS}
        ${CMAKE_CURRENT_SOURCE_DIR}/include/guiView.h
        PARENT_SCOPE
        )

# ============= ADDING MOC SUPPORT ==========
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC_ON)
set(CMAKE_AUTOUIC_ON)
set(CMAKE_AUTORCC_ON)


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


# ============= FIND QT GUI LIBRARIES ==========
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)


# ============= LINK QT GUI LIBRARIES ==========
target_link_libraries(Labyrinth_gui Qt5::Core)
target_link_libraries(Labyrinth_gui QtCore)
target_link_libraries(Labyrinth_gui Qt5::Widgets)
target_link_libraries(Labyrinth_gui QtWidgets)
target_link_libraries(Labyrinth_gui Qt5::Gui)
target_link_libraries(Labyrinth_gui QtGui)

target_compile_options(Labyrinth_gui -Lsearchdir D:\\Programs\\Qt\\5.12.1\\mingw73_64\\include)
target_compile_options(Labyrinth_gui -Lsearchdir D:\\Programs\\Qt\\5.12.1\\mingw73_64\\include\\QtCore)
target_compile_options(Labyrinth_gui -Lsearchdir D:\\Programs\\Qt\\5.12.1\\mingw73_64\\include\\QtWidgets)
target_compile_options(Labyrinth_gui -Lsearchdir D:\\Programs\\Qt\\5.12.1\\mingw73_64\\include\\QtGui)

target_link_directories(Labyrinth_gui D:\\Programs\\Qt\\5.12.1\\mingw73_64\\include D:\\Programs\\Qt\\5.12.1\\mingw73_64\\include\\QtCore D:\\Programs\\Qt\\5.12.1\\mingw73_64\\include\\QtGui D:\\Programs\\Qt\\5.12.1\\mingw73_64\\include\\QtWidgets)
# target_link_libraries(Labyrinth_gui QtCore QtWidgets QtGui)