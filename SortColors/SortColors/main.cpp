//
//  main.cpp
//  SortColors
//
//  Created by pettersnoopy on 14-12-26.
//  Copyright (c) 2014年 ZheJiang University Luop. All rights reserved.
//

//    Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
//
//    Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
//
//    Note:
//    You are not suppose to use the library's sort function for this problem.

#include <iostream>
using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
        int red[n], white[n], blue[n];
        int redcount = 0, whitecount = 0, bluecount = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] == 0) {
                red[redcount] = A[i];
                redcount++;
            } else if (A[i] == 1) {
                white[whitecount] = A[i];
                whitecount++;
            } else {
                blue[bluecount] = A[i];
                bluecount++;
            }
        }
        int i = 0;
        for (i = 0; i < redcount; i++) {
            A[i] = red[i];
        }
        for (int j = 0; j < whitecount ; j++) {
            A[i] = white[j];
            i++;
        }
        for (int j = 0; j < bluecount; j++) {
            A[i] = blue[j];
            i++;
        }
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

