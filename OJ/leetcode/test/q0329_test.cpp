/*
File Name : q0329_test.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2016-01-23 11:14:58
*/

#include "common.h"
#include "q0329/q0329.h"
#include "gtest/gtest.h"

TEST(Q0329, test) {
    Solution sol;
    vector<vector<int>> matrix = {
        {9,9,4},
        {6,6,8},
        {2,1,1}
    };

    ASSERT_EQ(4, sol.longestIncreasingPath(matrix));
}
