//
//  main.cpp
//  removeDuplicates
//
//  Created by pettersnoopy on 14-12-10.
//  Copyright (c) 2014年 ZheJiang University Luop. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i, j;
        for(i = j = 1; i < n; i ++)
            if(A[i] != A[i - 1]) A[j ++] = A[i];
        return n ? j : 0;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

