# Boost Test tests

# Add Boost to path
# set(BOOST_ROOT ":/Programs/boost_1_69_0")
#
# set(BOOST_INCLUDE_DIRS "${BOOST_ROOT}/boost")
# set(BOOST_INCLUDEDIR "${BOOST_ROOT}/boost")
#
# set(BOOST_LIBRARY_DIRS "${BOOST_ROOT}/libs")
# set(BOOST_LIBRARYDIR "${BOOST_ROOT}/libs")
#
# set(Boost_USE_STATIC_LIBS ON)
# set(Boost_USE_MULTITHREADED ON)

include("${PROJECT_SOURCE_DIR}/cmake/HunterGate.cmake")
HunterGate(
        URL "https://github.com/ruslo/hunter/archive/v0.10.9.tar.gz"
        SHA1 "53b198e364dc7bc8360fc545f798563229bd7e20"
)

hunter_add_package(Boost COMPONENTS unit_test_framework)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)


add_executable(BTP test.cpp)
target_link_libraries(BTP PUBLIC Boost::regex Boost::system Boost::filesystem)


# Add Boost test libraries
# hunter_add_package(Boost COMPONENTS regex system filesystem)
# hunter_add_package(Boost COMPONENTS test)
# find_package(Boost COMPONENTSCONFIG REQUIRED test)
#find_package(Boost COMPONENTS test REQUIRED)

# include_directories(${BOOST_LIBRARYDIR})


# Add tests
# add_test(MyTest test)


# include_directories (${TEST_SOURCE_DIR}/src)
#
# ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)
#


add_executable(test test.cpp)

target_link_libraries(
        test
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
