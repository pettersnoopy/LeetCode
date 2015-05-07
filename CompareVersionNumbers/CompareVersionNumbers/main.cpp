//
//  main.cpp
//  CompareVersionNumbers
//
//  Created by pettersnoopy on 15-3-13.
//  Copyright (c) 2015年 ZheJiang University Luop. All rights reserved.
//

//    Compare two version numbers version1 and version2.
//    If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
//
//    You may assume that the version strings are non-empty and contain only digits and the . character.
//    The . character does not represent a decimal point and is used to separate number sequences.
//    For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
//
//    Here is an example of version numbers ordering:
//
//    0.1 < 1.1 < 1.2 < 13.37
//    Credits:
//    Special thanks to @ts for adding this problem and creating all test cases.

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int ver1, ver2;
        if (version1.empty() && version2.empty())
            return 0;
        size_t pos1 = version1.find(".");
        if (version1.empty()) {
            ver1 = 0;
        } else {
            if (pos1 == string::npos) {
                pos1 = version1.length();
            }
            ver1 = atoi(version1.substr(0, pos1).c_str());
        }
        size_t pos2 = version2.find(".");
        if (version2.empty()) {
            ver2 = 0;
        } else {
            if (pos2 == string::npos) {
                pos2 = version2.length();
            }
            ver2 = atoi(version2.substr(0, pos2).c_str());
        }
        if (ver1 > ver2)
            return 1;
        else if (ver1 < ver2)
            return -1;
        else
            return compareVersion(pos1 == version1.length()? "" : version1.substr(pos1+1), pos2 == version2.length() ? "" : version2.substr(pos2+1));
    }
};

int main(int argc, const char * argv[])
{

    Solution sol;
    string a = "1.1";
    string b = "1.2";
    int i = 0;
    i = sol.compareVersion(a, b);
    cout<<i;
    std::cout << "Hello, World!\n";
    return 0;
}

