//
//  main.cpp
//  MajorityElement
//
//  Created by pettersnoopy on 15-1-7.
//  Copyright (c) 2015年 ZheJiang University Luop. All rights reserved.
//

//    Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
//
//    You may assume that the array is non-empty and the majority element always exist in the array.
//
//    Credits:
//    Special thanks to @ts for adding this problem and creating all test cases.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        int count = 0;
        for (; ; ) {
            if (num.size() == 1) {
                return num[0];
            } else {
                int i = rand() % (num.size() - 1);
                for (int j = 0; j < num.size(); j++) {
                    if (num[j] == num[i]) {
                        count++;
                    }
                }
                if (count > num.size() / 2) {
                    return num[i];
                } else {
                    count = 0;
                    continue;
                }
            }
        }
    }
    
    int majorityElement2(vector<int> &num) {
        
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

