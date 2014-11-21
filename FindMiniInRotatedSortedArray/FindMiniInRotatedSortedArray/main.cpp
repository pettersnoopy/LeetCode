//
//  main.cpp
//  FindMiniInRotatedSortedArray
//
//  Created by pettersnoopy on 14-11-20.
//  Copyright (c) 2014年 ZheJiang University Luop. All rights reserved.
//

/*  Suppose a sorted array is rotated at some pivot unknown to you beforehand.

    (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

    Find the minimum element.

    You may assume no duplicate exists in the array.
 
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
        if (num.size() > 1) {
            for (int i = 0; i<num.size()-1; ++i) {
                if (num[i]>num[i+1]) {
                    return num[i+1];
                }
                if (i == num.size() - 1) {
                    break;
                }
            }
            return num[0];
        
        }
        return num[0];
    }
};

class SolutionDuplicated {
public:
    int findMin(vector<int> &num) {
        if (num.size() > 1) {
            for (int i = 0; i<num.size()-1; ++i) {
                if (num[i]>num[i+1]) {
                    return num[i+1];
                }
                if (i == num.size() - 1) {
                    break;
                }
            }
            return num[0];
            
        }
        return num[0];
    }
};

int main(int argc, const char * argv[])
{
    vector<int> num;
    num = { 1,2,3,4,5};
    Solution sol;
    cout<<sol.findMin(num);

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

