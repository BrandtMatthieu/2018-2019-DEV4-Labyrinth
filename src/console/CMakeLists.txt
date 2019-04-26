# ============= ADDING SOURCES ==========
set(CONSOLE_SOURCES
        ${CONSOLE_SOURCES}
        ${CMAKE_CURRENT_SOURCE_DIR}/source/consoleView.cpp
        PARENT_SCOPE
        )

set(CONSOLE_HEADERS
        ${CONSOLE_HEADERS}
        ${CMAKE_CURRENT_SOURCE_DIR}/include/consoleView.h
        PARENT_SCOPE
        )
