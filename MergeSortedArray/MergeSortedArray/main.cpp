//
//  main.cpp
//  MergeSortedArray
//
//  Created by pettersnoopy on 15-1-6.
//  Copyright (c) 2015年 ZheJiang University Luop. All rights reserved.
//

//    Given two sorted integer arrays A and B, merge B into A as one sorted array.
//
//    Note:
//    You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.

#include <iostream>

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int p = m + n - 1, i = m - 1, j = n - 1;
        for (; i >= 0 && j >= 0; ) {
            if (A[i] < B[j]) {
                A[p--] = A[i--];
            } else {
                A[p--] = B[j--];
            }
        }
        while (i >= 0) {
            A[p--] = A[i--];
        }
        while (j >= 0) {
            A[p--] = B[j--];
        }
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

