//
//  main.cpp
//  FindtheMaxProductSubarrayWithArray
//
//  Created by pettersnoopy on 14-11-20.
//  Copyright (c) 2014年 ZheJiang University Luop. All rights reserved.
//

/*  Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 
     For example, given the array [2,3,-2,4],
     the contiguous subarray [2,3] has the largest product = 6.
 
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int maxProduct(int A[], int n) {
    int tmpp = A[0], tmpn = A[0], tmp, ans = A[0];
    for(int i = 1; i < n; i ++) {
        tmp = tmpp;
        tmpp = max(max(A[i], A[i] * tmpp), A[i] * tmpn);
        tmpn = min(min(A[i], A[i] * tmp), A[i] * tmpn);
        ans = max(ans, tmpp);
     }
   return ans;
   }
};

int main(int argc, const char * argv[])
{
    Solution sol;
    int A[2] = {0, 2};
    cout<<sol.maxProduct(A, 2)<<endl;;

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

