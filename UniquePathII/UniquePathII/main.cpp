//
//  main.cpp
//  UniquePathII
//
//  Created by pettersnoopy on 14-12-22.
//  Copyright (c) 2014年 ZheJiang University Luop. All rights reserved.
//


//    ollow up for "Unique Paths":
//
//    Now consider if some obstacles are added to the grids. How many unique paths would there be?
//
//    An obstacle and empty space is marked as 1 and 0 respectively in the grid.
//
//    For example,
//    There is one obstacle in the middle of a 3x3 grid as illustrated below.
//
//    [
//     [0,0,0],
//     [0,1,0],
//     [0,0,0]
//     ]
//    The total number of unique paths is 2.
//
//    Note: m and n will be at most 100.


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.size() == 0) return 0;
        obstacleGrid[0][0] = obstacleGrid[0][0] != 1;
        for(int i = 0; i < obstacleGrid.size(); i ++)
            for(int j = 0; j < obstacleGrid[0].size(); j ++)
            {
                if(i == 0 && j == 0) continue;
                if(obstacleGrid[i][j] == 1)
                {
                    obstacleGrid[i][j] = 0;
                    continue;
                }
                if(i > 0) obstacleGrid[i][j] += obstacleGrid[i - 1][j];
                if(j > 0) obstacleGrid[i][j] += obstacleGrid[i][j - 1];
            }
        return obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

