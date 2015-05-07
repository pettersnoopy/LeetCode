//
//  main.cpp
//  SearchInsertPosition
//
//  Created by pettersnoopy on 14-12-26.
//  Copyright (c) 2014年 ZheJiang University Luop. All rights reserved.
//

//    Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
//
//    You may assume no duplicates in the array.
//
//    Here are few examples.
//    [1,3,5,6], 5 → 2
//    [1,3,5,6], 2 → 1
//    [1,3,5,6], 7 → 4
//    [1,3,5,6], 0 → 0

#include <iostream>
using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        for (int i = 0; i < n; i++) {
            if (A[i] == target) {
                return i;
            } else if (i == n-1 && A[i] < target) {
                return n;
            } else if (A[i] > target && A[i-1] < target) {
                return i;
            }
        }
        return 0;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

