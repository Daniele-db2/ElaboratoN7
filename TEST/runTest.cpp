#include "googletest/googletest/include/gtest/gtest.h"

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS(); //returns 0 if all the tests are successful, or 1 otherwise
}
