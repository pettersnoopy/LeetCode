//
//  main.cpp
//  Pascal`sTriangleII
//
//  Created by pettersnoopy on 14-12-12.
//  Copyright (c) 2014年 ZheJiang University Luop. All rights reserved.
//

//    Given an index k, return the kth row of the Pascal's triangle.
//
//    For example, given k = 3,
//    Return [1,3,3,1].
//
//    Note:
//    Could you optimize your algorithm to use only O(k) extra space?

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> result;
        vector<int> temp;
        if (rowIndex == 0) {
            temp.push_back(1);
        } else {
            for (int i = 0; i <= rowIndex; i++) {
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
        }
        return temp;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

