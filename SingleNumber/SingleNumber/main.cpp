//
//  main.cpp
//  SingleNumber
//
//  Created by pettersnoopy on 14-12-3.
//  Copyright (c) 2014年 ZheJiang University Luop. All rights reserved.
//

//    Given an array of integers, every element appears twice except for one. Find that single one.
//
//    Note:
//    Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int temp = 0;
        for (int i = 0; i<n; ++i) {
            temp = temp ^ A[i];
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

