//
//  main.cpp
//  WordBreak
//
//  Created by pettersnoopy on 14-12-2.
//  Copyright (c) 2014年 ZheJiang University Luop. All rights reserved.
//

//    Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
//
//    For example, given
//    s = "leetcode",
//    dict = ["leet", "code"].
//
//    Return true because "leetcode" can be segmented as "leet code".

#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        bool *dp = new bool[s.length() + 1];
        memset(dp, 0, sizeof(bool) * (s.length() + 1));
        dp[0] = true;
        for(int i = 1; i <= s.length(); i ++)
            for(int j = 0; j < i; j ++)
            {
                dp[i] = dp[i] || (dp[j] && dict.count(s.substr(j, i - j)));
            }
        return dp[s.length()];
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

