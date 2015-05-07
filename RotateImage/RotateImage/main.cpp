//
//  main.cpp
//  RotateImage
//
//  Created by pettersnoopy on 15-1-4.
//  Copyright (c) 2015年 ZheJiang University Luop. All rights reserved.
//

//  You are given an n * n 2D matrix representing an image.
//  Rotate the image by 90 degrees (clockwise).
//  Follow up :
//  Could you do this in-place?

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void rotate(vector<vector<int> > &matrix) {
        if (matrix.size() == 0) {
            return;
        }
        int len = (int)matrix.size();
        int lenlimi = (len + 1) >> 1;
        for (int i = 0; i <lenlimi; i++) {
            for (int j = 0; j < (len & 1 ? lenlimi - 1 : lenlimi); j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[len - j - 1][i];
                matrix[len - j - 1][i] = matrix[len - i - 1][len - j -1];
                matrix[len - i - 1][len - j -1] = matrix[j][len - i - 1];
                matrix[j][len - i - 1] = tmp;
            }
        }
    }
};

int main(int argc, const char * argv[])
{
    vector<vector<int>> test = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    Solution sol;
    sol.rotate(test);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout<<test[i][j]<<" ";
        }
        cout<<endl;
    }
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

