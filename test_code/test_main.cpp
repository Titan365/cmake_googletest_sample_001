#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <stdio.h>


extern "C" {
    #include "sub_func_a.h"
    #include "sub_func_b.h"
}


using ::testing::Mock;
using ::testing::_;
using ::testing::ReturnRef;
using ::testing::StrictMock;
using ::testing::Invoke;
using ::testing::Return;


TEST(test_temp, temp) {
    EXPECT_EQ(100, sub_func_a());
    EXPECT_EQ(200, sub_func_b());
}
