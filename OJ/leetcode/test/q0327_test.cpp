/*
File Name : q0327_test.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2016-01-15 21:57:13
*/

#include "common.h"
#include "q0327/q0327.h"
#include <gtest/gtest.h>

TEST(Q0327, test) {
    Solution sol;
    vector<int> nums = {-2, 5, -1};
    int lower = -2;
    int upper = 2;

    vector<int> nums2 = {2147483647,-2147483648,-1,0};
    int lower2 = -1;
    int upper2 = 0;

    ASSERT_EQ(3, sol.countRangeSum(nums, lower, upper));
    ASSERT_EQ(4, sol.countRangeSum(nums2, lower2, upper2));

}