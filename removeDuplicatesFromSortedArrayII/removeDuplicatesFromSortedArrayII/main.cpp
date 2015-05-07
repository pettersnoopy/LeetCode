//
//  main.cpp
//  removeDuplicatesFromSortedArrayII
//
//  Created by pettersnoopy on 14-12-10.
//  Copyright (c) 2014年 ZheJiang University Luop. All rights reserved.
//

//    Follow up for "Remove Duplicates":
//    What if duplicates are allowed at most twice?
//
//    For example,
//    Given sorted array A = [1,1,1,2,2,3],
//
//    Your function should return length = 5, and A is now [1,1,2,2,3].
//

#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i, j, cnt = 0;
        for (i = j = 0; i < n; i++) {
            if (j != 0 && A[i] == A[j-1]) {
                cnt++;
            } else
                cnt = 0;
            if (cnt < 2) {
                A[j++] = A[i];
            }
        
        }
        return j;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

