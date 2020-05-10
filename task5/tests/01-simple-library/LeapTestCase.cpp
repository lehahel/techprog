//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"

#include <Functions.h>

TEST_F(LeapTestCase, test1) {
    ASSERT_THROW(IsLeap(-1), std::invalid_argument);
    ASSERT_TRUE(IsLeap(400));
    ASSERT_FALSE(IsLeap(500));
    ASSERT_TRUE(IsLeap(4));
    ASSERT_FALSE(IsLeap(1));
}
