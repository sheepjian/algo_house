/*
File Name : q0315_test.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2016-01-17 15:37:50
*/

#include "common.h"
#include "q0315/q0315.h"
#include <gtest/gtest.h>

TEST(Q0315, test1) {
    Solution sol;
    vector<int> nums = {5, 2, 6, 1};
    vector<int> expect_result = {2, 1, 1, 0};
    vector<int> test_result = sol.countSmaller(nums);

    ASSERT_EQ(expect_result.size(), test_result.size());
    int len = nums.size();
    for(int i=0; i<len; i++) {
        ASSERT_EQ(expect_result[i], test_result[i])<<"difference at index "<<i;
    }
}

TEST(Q0315, test2) {
    Solution sol;
    vector<int> nums = {10, 20, 25, 5, 2, 6, 1};
    vector<int> expect_result = {4, 4, 4, 2, 1, 1, 0};
    vector<int> test_result = sol.countSmaller2(nums);

    ASSERT_EQ(expect_result.size(), test_result.size());
    int len = nums.size();
    for(int i=0; i<len; i++) {
        ASSERT_EQ(expect_result[i], test_result[i])<<"difference at index "<<i;
    }
}

TEST(Q0315, test3) {
    Solution sol;
    vector<int> nums = {10, 20, 25, 5, 2, 6, 1};
    vector<int> expect_result = {4, 4, 4, 2, 1, 1, 0};
    vector<int> test_result = sol.countSmaller3(nums);

    ASSERT_EQ(expect_result.size(), test_result.size());
    int len = nums.size();
    for(int i=0; i<len; i++) {
        ASSERT_EQ(expect_result[i], test_result[i])<<"difference at index "<<i;
    }
}