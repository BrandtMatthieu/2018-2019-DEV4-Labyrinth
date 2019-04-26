# ============= ADDING SOURCES ==========
set(CONSOLE_SOURCES
        ${CONSOLE_SOURCES}
        ${CMAKE_CURRENT_SOURCE_DIR}/source/controllerConsole.cpp
        PARENT_SCOPE
        )

set(CONSOLE_HEADERS
        ${CONSOLE_HEADERS}
        ${CMAKE_CURRENT_SOURCE_DIR}/include/controllerConsole.h
        PARENT_SCOPE
        )

set(GUI_SOURCES
        ${GUI_SOURCES}
        ${CMAKE_CURRENT_SOURCE_DIR}/source/controllerGUI.cpp
        PARENT_SCOPE
        )

set(GUI_HEADERS
        ${GUI_HEADERS}
        ${CMAKE_CURRENT_SOURCE_DIR}/include/controllerGUI.h
        PARENT_SCOPE
        )