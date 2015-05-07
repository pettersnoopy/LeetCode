//
//  main.cpp
//  TwoSum
//
//  Created by pettersnoopy on 15-1-8.
//  Copyright (c) 2015年 ZheJiang University Luop. All rights reserved.
//

//    Given an array of integers, find two numbers such that they add up to a specific target number.
//
//    The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
//
//    You may assume that each input would have exactly one solution.
//
//    Input: numbers={2, 7, 11, 15}, target=9
//    Output: index1=1, index2=2

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> a;
        int length = (int) numbers.size();
        for (int i = 0; i < length - 1; i++) {
            for (int j = i + 1; j < length; j++) {
                if (numbers[i] + numbers[j] == target) {
                    a.push_back(i);
                    a.push_back(j);
                    break;
                }
            }
        }
        return a;
    }
    vector<int> twoSum1(vector<int> &numbers, int target) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i = 0; i < numbers.size(); i ++)
        {
            if(mp.count(target - numbers[i]))
            {
                ans.push_back(mp[target - numbers[i]] + 1);
                ans.push_back(i + 1);
                break;
            }
            if(!mp.count(numbers[i])) mp[numbers[i]] = i;
        }
        return ans;
    }
};

int main(int argc, const char * argv[])
{
    vector<int> a;
    vector<int> number = { 2, 7, 11, 15};
    Solution sol;
    a = sol.twoSum(number, 9);
    cout<<a[0]<<" "<<a[1];

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

