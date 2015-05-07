//
//  main.cpp
//  SearchForARange
//
//  Created by pettersnoopy on 14-12-26.
//  Copyright (c) 2014年 ZheJiang University Luop. All rights reserved.
//

//    Given a sorted array of integers, find the starting and ending position of a given target value.
//
//    Your algorithm's runtime complexity must be in the order of O(log n).
//
//    If the target is not found in the array, return [-1, -1].
//
//    For example,
//    Given [5, 7, 7, 8, 8, 10] and target value 8,
//    return [3, 4].

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int left, right, mid, l, r;
        for(left = 0, right = n; left < right; )
        {
            mid = (left + right) >> 1;
            if(A[mid] >= target) right = mid;
            else left = mid + 1;
        }
        l = left;
        for(left = 0, right = n; left < right; )
        {
            mid = (left + right) >> 1;
            if(A[mid] > target) right = mid;
            else left = mid + 1;
        }
        r = left - 1;
        if(l >= n || A[l] != target) return vector<int>(2, -1);
        vector<int> ans = {l, r};
        return ans;
    }
};

int main(int argc, const char * argv[])
{
    vector<int> needPrint;
    int A[2] = {2, 2};
    Solution sol;
    needPrint = sol.searchRange(A, 2, 2);
    vector<int>::iterator it;
    for (it = needPrint.begin(); it != needPrint.end(); it++) {
        cout<<*it<<endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}

