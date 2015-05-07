//
//  main.cpp
//  Triangle
//
//  Created by pettersnoopy on 15-1-8.
//  Copyright (c) 2015年 ZheJiang University Luop. All rights reserved.
//

//    Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
//
//    For example, given the following triangle
//    [
//     [2],
//     [3,4],
//     [6,5,7],
//     [4,1,8,3]
//     ]
//    The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
//
//    Note:
//    Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
//    vector<int> position;
//    int minimumTotal(vector<vector<int> > &triangle) {
//        int min;
////        int position[triangle.size()];
//        if (triangle.size() == 1) {
//            position[0] = 0;
//            min = triangle[0][0];
//            return min;
//        } else {
//            vector<vector<int>> triangle1;
//            vector<vector<int>> temp;
//            temp = triangle;
//            temp.pop_back();
//            triangle1 = temp;
//            int x = (int) triangle1.size() - 1;
//            int pos1 = position[x];
//            int pos2 = pos1 + 1;
//            int minsum1 = minimumTotal(triangle1) + triangle[x + 1][pos1];
//            int minsum2 = minimumTotal(triangle1) + triangle[x + 1][pos2];
//            if (minsum1 <= minsum2) {
//                position[x + 1] = pos1;
//                min = minsum1;
//            } else {
//                position[x + 1] = pos2;
//                min = minsum2;
//            }
//            return min;
//        }
//    }
    int minimumTotal(vector<vector<int> > &triangle) {
        for(int i = triangle.size() - 2; i >= 0; i --)
        {
            for(int j = 0; j < triangle[i].size(); j ++)
                triangle[i][j] = min(triangle[i][j] + triangle[i + 1][j], triangle[i][j] + triangle[i + 1][j + 1]);
        }
        return triangle.size() == 0 ? 0 : triangle[0][0];
    }
};

int main(int argc, const char * argv[])
{
    vector<vector<int>> triangle = {
        {1},
        {2, 3},
//        {6, 5, 7},
//        {4, 1, 8, 3}
    };
    Solution sol;
    cout<<sol.minimumTotal(triangle)<<endl;

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

