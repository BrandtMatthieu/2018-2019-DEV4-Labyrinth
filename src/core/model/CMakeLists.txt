# ============= ADDING SOURCES ==========
set(CORE_SOURCES
        ${CORE_SOURCES}
        ${CMAKE_CURRENT_SOURCE_DIR}/source/board.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/game.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/objectiveCard.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/player.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/position.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/tile.cpp
        PARENT_SCOPE
        )

set(CORE_HEADERS
        ${CORE_HEADERS}
        ${CMAKE_CURRENT_SOURCE_DIR}/include/board.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/game.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/insertSide.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/objectiveCard.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/player.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/position.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/tile.h
        PARENT_SCOPE
        )
