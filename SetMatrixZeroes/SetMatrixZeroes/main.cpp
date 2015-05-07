//
//  main.cpp
//  SetMatrixZeroes
//
//  Created by pettersnoopy on 14-12-26.
//  Copyright (c) 2014年 ZheJiang University Luop. All rights reserved.
//

//    Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if(matrix.size() == 0) return;
        int x = -1, y = -1;
        for(int i = 0; i < matrix.size(); i ++)
        {
            for(int j = 0; j < matrix[0].size(); j ++)
            {
                if(matrix[i][j] == 0)
                {
                    if(x == -1)
                    {
                        x = i, y = j;
                    }
                    else
                    {
                        matrix[x][j] = 0;
                        matrix[i][y] = 0;
                    }
                }
            }
        }
        
        if(x == -1) return;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if ((matrix[x][j] == 0 || matrix[i][y] == 0) && (i != x && j != y)) {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int i = 0; i < matrix.size(); i ++) matrix[i][y] = 0;
        for(int j = 0; j < matrix[0].size(); j ++) matrix[x][j] = 0;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

