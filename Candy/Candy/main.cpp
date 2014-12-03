//
//  main.cpp
//  Candy
//
//  Created by pettersnoopy on 14-12-3.
//  Copyright (c) 2014年 ZheJiang University Luop. All rights reserved.
//

//    There are N children standing in a line. Each child is assigned a rating value.
//
//    You are giving candies to these children subjected to the following requirements:
//
//    Each child must have at least one candy.
//    Children with a higher rating get more candies than their neighbors.
//    What is the minimum candies you must give?



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        int *candies;
        candies = new int[ratings.size()];
        for (int i = 0; i<ratings.size(); ++i) {
            candies[i] = 1;
        }
        for (int i = (int) ratings.size() - 1; i > 0; --i) {
            if (ratings[i] < ratings[i-1]) {
                candies[i-1] = candies[i] + 1;
            }
        }
        for (int i = 0; i<ratings.size() - 1; ++i) {
            if (ratings[i] < ratings[i + 1]) {
                int tmp = candies[i] + 1;
                if(candies[i + 1] < tmp){
                    candies[i + 1] = tmp;
                }
            }

        }
        int sum = 0;
        for (int i = 0; i<ratings.size(); ++i) {
            sum = sum + candies[i];
        }
        return sum;
        
    }
};

int main(int argc, const char * argv[])
{
    vector<int> s;
    s.push_back(2);
    s.push_back(2);
    Solution sol;
    cout<<sol.candy(s);

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

