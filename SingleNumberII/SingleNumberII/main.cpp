//
//  main.cpp
//  SingleNumberII
//
//  Created by pettersnoopy on 14-12-3.
//  Copyright (c) 2014年 ZheJiang University Luop. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int one = 0, two = 0;
        for(int i = 0; i < n; i ++)
        {
            two |= one & A[i];
            one ^= A[i];
            int tmp = one & two;
            two ^= tmp;
            one ^= tmp;
        }
        return one;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

