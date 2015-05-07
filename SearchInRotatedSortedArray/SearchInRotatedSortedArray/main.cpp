//
//  main.cpp
//  SearchInRotatedSortedArray
//
//  Created by pettersnoopy on 14-12-26.
//  Copyright (c) 2014年 ZheJiang University Luop. All rights reserved.
//

//    Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//
//    (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//    You are given a target value to search. If found in the array return its index, otherwise return -1.
//
//    You may assume no duplicate exists in the array.

#include <iostream>
using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
        int left = 0, right = n - 1, mid;
        while(left < right)
        {
            mid = (left + right) >> 1;
            if(A[mid] == target) return mid;
            if(A[mid] >= A[left])
            {
                if(target < A[mid] && A[left] <= target) right = mid;
                else left = mid + 1;
            }
            else
            {
                if(target <= A[right] && A[mid] < target) left = mid + 1;
                else right = mid;
            }
        }
        return A[left] == target ? left : -1;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

