//
//  main.cpp
//  GasStation
//
//  Created by pettersnoopy on 14-12-3.
//  Copyright (c) 2014年 ZheJiang University Luop. All rights reserved.
//

//    There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
//
//    You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
//
//    Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
//
//    Note:
//    The solution is guaranteed to be unique

//    Tag--greedy

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        vector<int> remainder;
        int sum =0;
        for(int i = 0; i < gas.size(); i++)
        {
            remainder.push_back(gas[i]-cost[i]);
            sum += gas[i]-cost[i];
        }
        if(sum < 0)
        {
            return -1;
        }
        else
        {
            int start;
            int cur = 0;
            do
            {
                start = cur;
                int tmp = remainder[cur++];
                while(tmp >= 0 && cur<gas.size())
                {
                    tmp += remainder[cur++];
                    if(tmp < 0)
                    {
                        break;
                    }
                }
                if(tmp >= 0 && cur == gas.size())
                {
                    return start;
                }
            }while(cur<gas.size());
            return -1;
        }
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

