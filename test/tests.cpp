//
// Created by likai on 2021/10/13.
//
#define BOOST_TEST_MAIN
#define BOOST_TEST_BYN_LINK
#define BOOST_TEST_MODULE nothing

#include <boost/test/included/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(nothing)

    BOOST_AUTO_TEST_CASE(nothing1) {
        BOOST_TEST(true);
    }

BOOST_AUTO_TEST_SUITE_END()