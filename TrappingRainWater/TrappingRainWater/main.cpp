//
//  main.cpp
//  TrappingRainWater
//
//  Created by pettersnoopy on 14-11-21.
//  Copyright (c) 2014年 ZheJiang University Luop. All rights reserved.
//

/*  Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 
    For example,
    Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 
 */

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int trap(int A[], int n) {
        int sum = 0;
//        int position[n];
//        int k = 0;
//        for (int i =0; i<n; ++i) {
//            if (i == 0) {
//                if (A[i] >= A[i+1]) {
//                    position[k] = i;
//                    ++k;
//                }
//            } else if (i == n-1) {
//                if (A[i] >= A[i-1]) {
//                    position[k] = i;
//                    ++k;
//                }
//            } else {
//                if (A[i] >= A[i-1] && A[i] >= A[i+1]) {
//                    position[k] = i;
//                    ++k;
//                }
//            }
//        }
        
//        --k;
//        cout<<position[k]<<endl;
//        if (position[k]!= n-1) {
//            for (int i = n-1; i>position[k]; --i) {
//                A[i] = A[position[k]];
//            }
//        }
        vector<int> pre;
        
        int maxOf = 0;
        
        for (int i = 0; i<n; ++i) {
            maxOf = max(maxOf, A[i]);
            pre.push_back(maxOf);
        }
        maxOf = 0;
        for (int i = n-1; i>0; i--) {
            maxOf = max(A[i], maxOf);
            sum = sum + min(pre[i] - A[i], maxOf - A[i]);
        }
        return sum;
    }
};

int main(int argc, const char * argv[])
{
    Solution sol;

    int a[] = { 4,2,3};
    cout<<sol.trap(a, 3);
    return 0;
}

