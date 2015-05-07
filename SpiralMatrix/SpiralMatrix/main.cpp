//
//  main.cpp
//  SpiralMatrix
//
//  Created by pettersnoopy on 14-12-24.
//  Copyright (c) 2014年 ZheJiang University Luop. All rights reserved.
//

//    Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
//
//    For example,
//    Given the following matrix:
//
//    [
//     [ 1, 2, 3 ],
//     [ 4, 5, 6 ],
//     [ 7, 8, 9 ]
//     ]
//    You should return [1,2,3,6,9,8,7,4,5].

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    vector<int> res;
    
    bool JudgeValid(int x, int y, vector<vector<bool> > &vis, vector<vector<int> > &matrix){
        return x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() && vis[x][y] == false;
    }
    
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        int dir, x, y, nx, ny;
        if(matrix.size() == 0) return res;
        vector<vector<bool> > vis(matrix.size(), vector<bool>(matrix[0].size(), false));
        for(dir = x = y = 0; JudgeValid(x, y, vis, matrix); x = nx, y = ny)
        {
            res.push_back(matrix[x][y]);
            vis[x][y] = true;
            nx = x + dx[dir];
            ny = y + dy[dir];
            if(!JudgeValid(nx, ny, vis, matrix))
            {
                dir = (dir + 1) % 4;
                nx = x + dx[dir];
                ny = y + dy[dir];
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

