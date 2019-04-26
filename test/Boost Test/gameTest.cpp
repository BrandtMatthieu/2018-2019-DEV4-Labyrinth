#define BOOST_TEST_MODULE test module name
#include "./unit_test.hpp"
OOST_AUTO_TEST_CASE(first_test) {
        int i = 1;
        BOOST_TEST(i);
        BOOST_TEST(i == 2);
}
