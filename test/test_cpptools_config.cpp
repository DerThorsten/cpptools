#include <doctest.h>

#include "cpptools/cpptools.hpp"
#include "cpptools/cpptools_config.hpp"



TEST_SUITE_BEGIN("core");

TEST_CASE("check version"){

    #ifndef CPPTOOLS_VERSION_MAJOR
        #error "CPPTOOLS_VERSION_MAJOR is undefined"
    #endif
    

    #ifndef CPPTOOLS_VERSION_MINOR
        #error "CPPTOOLS_VERSION_MINOR is undefined"
    #endif


    #ifndef CPPTOOLS_VERSION_PATCH
        #error "CPPTOOLS_VERSION_PATCH is undefined"
    #endif

    CHECK_EQ(CPPTOOLS_VERSION_MAJOR , 0);
    CHECK_EQ(CPPTOOLS_VERSION_MINOR , 1);
    CHECK_EQ(CPPTOOLS_VERSION_PATCH , 0);
}



TEST_SUITE_END(); // end of testsuite core
