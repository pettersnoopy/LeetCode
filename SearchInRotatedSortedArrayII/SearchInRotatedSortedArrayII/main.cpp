//
//  main.cpp
//  SearchInRotatedSortedArrayII
//
//  Created by pettersnoopy on 14-12-26.
//  Copyright (c) 2014年 ZheJiang University Luop. All rights reserved.
//

//    Follow up for "Search in Rotated Sorted Array":
//    What if duplicates are allowed?
//
//    Would this affect the run-time complexity? How and why?
//
//    Write a function to determine if a given target is in the array.

#include <iostream>
using namespace std;

class Solution {
public:
    bool search(int A[], int n, int target) {
        int left = 0, right = n - 1, mid;
        while(left < right)
        {
            mid = (left + right) >> 1;
            if(target < A[mid] && A[left] < target) right = mid;
            else if(target < A[right] && A[mid] < target) left = mid + 1;
            else
            {
                if(A[left] == target || A[right] == target) return true;
                else if(A[left] < target) left ++;
                else if(target < A[right]) right --;
                else return false;
            }
        }
        return A[left] == target ? true : false;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

