cmake_minimum_required(VERSION 3.10.0)


# ============= ADD PROJECT ==========
project(Labyrinth VERSION 0.1.03.27 LANGUAGES CXX)


# ============= ADD TESTING ==========
add_custom_target(check COMMAND GTEST_COLOR=1 ${CMAKE_CTEST_COMMAND} --verbose)


# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# add_subdirectory(${googletest_SOURCE_DIR}
#         ${googletest_BINARY_DIR}
#         EXCLUDE_FROM_ALL)


# Enable tests
enable_testing()
add_subdirectory(src)
add_subdirectory(test)


# ============= SET COMPILERS FALG ==========
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall")
set(CMAKE_CXX_STANDARD 11)

add_compile_options(-Wall)
add_compile_options(-Wextra)
add_compile_options(-Wpedantic)
add_compile_options(-ffunction-sections)
add_compile_options(-fdata-sections)
add_compile_options(-Wl,--gc-sections)
add_compile_options(-I"D:\\Programs\\Qt\\5.12.1\\mingw73_64\\include" -L"D:\\Programs\\Qt\\5.12.1\\mingw73_64\\lib" -lQtGui -lQtCore -lQtWidgets)
add_compile_options(-DENABLE_PRECOMPILED_HEADERS=OFF)
set(CMAKE_EXE_LINKER_FLAGS -I"D:\\Programs\\Qt\\5.12.1\\mingw73_64\\include" -L"D:\\Programs\\Qt\\5.12.1\\mingw73_64\\lib" -lQtGui -lQtCore -lQtWidgets)

# ============= FIND EXTERNAL LIBRARIES ==========
# SET(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})