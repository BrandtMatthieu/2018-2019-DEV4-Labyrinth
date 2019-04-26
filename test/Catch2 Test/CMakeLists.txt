set(CATCH2_SOURCES
        playerTest.cpp
        boardTest.cpp)

set(CATCH2_HEADERS
        catch.hpp)

add_subdirectory(./../../src/core/model/ model)

add_executable(Catch2 ${CATCH2_SOURCES} ${CORE_SOURCES} ${CORE_HEADERS})