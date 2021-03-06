//
//  main.cpp
//  SubsetsII
//
//  Created by pettersnoopy on 14-12-24.
//  Copyright (c) 2014年 ZheJiang University Luop. All rights reserved.
//

//    Given a collection of integers that might contain duplicates, S, return all possible subsets.
//
//    Note:
//    Elements in a subset must be in non-descending order.
//    The solution set must not contain duplicate subsets.
//    For example,
//    If S = [1,2,2], a solution is:
//
//    [
//     [2],
//     [1],
//     [1,2,2],
//     [2,2],
//     [1,2],
//     []
//     ]

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int>> results;
        if (S.size() == 1) {
            vector<int> a = {};
            results.push_back(a);
            results.push_back(S);
            return results;
        }
        int k = S[S.size() - 1];
        S.pop_back();
        vector<int> temp = S;
        vector<vector<int>> s1 = subsets(temp);
        vector<vector<int>>::iterator iter;
        for (iter = s1.begin(); iter != s1.end(); iter++) {
            vector<int> temp = *iter;
            sort(temp.begin(), temp.end());
            results.push_back(temp);
            temp.push_back(k);
            sort(temp.begin(), temp.end());
            results.push_back(temp);
        }
        removeDup(results);
        return results;
    }
    
    void removeDup(vector<vector<int>> &l) {
        for(vector<vector<int>>::iterator iter1=l.begin(); iter1!=l.end(); iter1++) {
            for(vector<vector<int>>::iterator iter2=iter1+1; iter2!=l.end(); ) {
                if(*iter1==*iter2) {
                    l.erase(iter2);
                }
                else
                    iter2++;   //只有在没有删除操作的情况下，下移指针
            }
        }
    }
};

int main(int argc, const char * argv[])
{
    Solution sol;
    vector<int> S = {1, 2, 2};
    vector<vector<int>> s1 = sol.subsets(S);
    vector<vector<int>>::iterator iter;
    for (iter = s1.begin(); iter != s1.end(); iter++) {
        vector<int> temp = *iter;
        vector<int>::iterator it;
        for (it = temp.begin(); it != temp.end(); it++) {
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
