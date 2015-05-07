//
//  main.cpp
//  PlusOne
//
//  Created by pettersnoopy on 14-12-10.
//  Copyright (c) 2014年 ZheJiang University Luop. All rights reserved.
//


//    Given a non-negative number represented as an array of digits, plus one to the number.
//
//    The digits are stored such that the most significant digit is at the head of the list.


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int cur, i;
        if (digits.size() == 0) {
            return digits;
        }
        for (i = (int) digits.size() - 1, cur = 1; i >= 0; i--) {
            int tmp = digits[i] + cur;
            cur = tmp / 10;
            digits[i] = tmp % 10;
        }
        if (cur) {
            digits.insert(digits.begin(), cur);
        }
        return digits;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

