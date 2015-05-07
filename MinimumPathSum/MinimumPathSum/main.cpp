//
//  main.cpp
//  MinimumPathSum
//
//  Created by pettersnoopy on 15-1-6.
//  Copyright (c) 2015年 ZheJiang University Luop. All rights reserved.
//

//    Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//
//    Note: You can only move either down or right at any point in time.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        vector<vector<int>> temp1;
        vector<vector<int>> temp2;
        if (grid.size() == 0) {
            return 0;
        } else {
            temp1 = grid;
            temp1.pop_back();
            temp2 = grid;
            vector<vector<int>>::iterator it;
            for (it = temp2.begin(); it != temp2.end(); it++) {
                (*it).pop_back();
            }
            int i = (int)grid.size();
            int j = (int)grid[0].size();
            int sum1 = minPathSum(temp1) + grid[i-1][j-1];
            int sum2 = minPathSum(temp2) + grid[j-1][i-1];
            if (sum1 < sum2) {
                sum1 = sum2;
            }
            return sum1;
        }
    }
};

int main(int argc, const char * argv[])
{
    vector<vector<int>> grid = {
        {1, 2, 3},
        {2, 1, 4},
        {4, 2, 1}
    };
    Solution sol;
    cout<<sol.minPathSum(grid)<<endl;;

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

