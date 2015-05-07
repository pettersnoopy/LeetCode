//
//  main.cpp
//  SearchA2DMatrix
//
//  Created by pettersnoopy on 15-1-4.
//  Copyright (c) 2015年 ZheJiang University Luop. All rights reserved.
//
//  Write an efficient algorithm that searches for a value in an m * n matrix. This matrix has the following properties:
//     Integers in each row are sorted from left to right.
//     The first integer of each row if greater than the last integer of the previous row.
//  For example, Consider the following matrix:
//     [
//        [1, 3, 5, 7],
//        [10, 11, 16, 20],
//        [23, 30, 34, 50]
//     ]
//  Given target = 3, return ture.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int left, right , mid;
        for (left = 0, right = (int)matrix.size(); left < right - 1; ) {
            mid = (left + right) >> 1;
            if (matrix[mid][0] > target) {
                right = mid;
            } else left = mid;
        }
        if (left == matrix.size() || right == 0) {
            return false;
        }
        vector<int> &a = matrix[left];
        for (left = 0, right = (int) a.size(); left <right - 1; ) {
            mid = (left + right) >> 1;
            if (a[mid] > target) {
                right = mid;
            } else left = mid;
        }
        if (left == a.size() || right == 0) {
            return false;
        }
        return a[left] == target;
    }
};

int main(int argc, const char * argv[])
{

    vector<vector<int> > a = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    Solution sol;
    cout<<sol.searchMatrix(a, 3)<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}

