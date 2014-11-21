//
//  main.cpp
//  ReverseWordsInAString
//
//  Created by pettersnoopy on 14-11-21.
//  Copyright (c) 2014年 ZheJiang University Luop. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        int begin = 0;
        int end = 0;
        
        while(end < s.size()){
            if(s[end] == ' '){
                swapString(s, begin, end - 1);
                begin = end+1;
                end = begin;
            }
            else{
                end++;
            }
        }
        swapString(s, begin, end - 1);
        
        swapString(s, 0, s.size()-1);
    }
    
    void swapString(string &s, int begin, int end){
        while(end > begin){
            char c = s[begin];
            s[begin] = s[end];
            s[end] = c;
            begin++;
            end--;
        }
    }
};

int main(int argc, const char * argv[])
{

    string s = "the sky is blue";
    Solution sol;
    sol.reverseWords(s);
    cout<<s;
    std::cout << "Hello, World!\n";
    return 0;
}

