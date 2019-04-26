#define BOOST_TEST_MODULE Position Test

#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(constructor_test) {
        int i =1;
        BOOST_TEST(i); // non-zero test
        BOOST_TEST(i == 2);
}