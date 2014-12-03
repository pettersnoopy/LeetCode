//
//  main.cpp
//  WordBreakII
//
//  Created by pettersnoopy on 14-12-3.
//  Copyright (c) 2014年 ZheJiang University Luop. All rights reserved.
//

//  Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

//    Return all such possible sentences.
//
//    For example, given
//    s = "catsanddog",
//    dict = ["cat", "cats", "and", "sand", "dog"].
//
//    A solution is ["cats and dog", "cat sand dog"].

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> DFS(const string &s, vector<int> *site, int ith)
    {
        vector<string> res;
        for(int i = 0; i < site[ith].size(); i ++)
        {
            vector<string> tmp;
            string str = s.substr(site[ith][i], ith - site[ith][i]);
            if(site[site[ith][i]].size() == 0)
                res.push_back(str);
            else
            {
                tmp = DFS(s, site, site[ith][i]);
                for(int j = 0; j < tmp.size(); j ++)
                    res.push_back(tmp[j] + " " + str);
            }
        }
        return res;
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<int> *site = new vector<int>[s.length() + 1];
        bool *dp = new bool[s.length() + 1];
        memset(dp, 0, sizeof(bool) * s.length());
        dp[0] = true;
        for(int i = 1; i <= s.length(); i ++)
        {
            for(int j = 0; j < i; j ++)
            {
                if(dp[j] == true && dict.count(s.substr(j, i - j)))
                    site[i].push_back(j), dp[i] = true;
            }
        }
        return DFS(s, site, (int)s.length());
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

