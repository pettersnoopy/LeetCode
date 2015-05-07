//
//  main.cpp
//  Pascal`sTriangle
//
//  Created by pettersnoopy on 14-12-12.
//  Copyright (c) 2014年 ZheJiang University Luop. All rights reserved.
//

//    Given numRows, generate the first numRows of Pascal's triangle.
//
//    For example, given numRows = 5,
//    Return
//
//    [
//     [1],
//     [1,1],
//     [1,2,1],
//     [1,3,3,1],
//     [1,4,6,4,1]
//    ]

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> result;
        vector<int> temp;
        for (int i = 0; i < numRows; i++) {
            temp.clear();
            if (result.empty()) {
                temp.push_back(1);
            } else {
                vector<int> vv = result[i - 1];
                int length = (int) vv.size();
                temp.push_back(1);
                for (int j = 0; j < length-1; j++) {
                    temp.push_back(vv[j] + vv[j+1]);
                }
                temp.push_back(1);
            }
            result.push_back(temp);
            
        }
        return result;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    Solution sol;
    sol.generate(3);
    std::cout << "Hello, World!\n";
    return 0;
}

