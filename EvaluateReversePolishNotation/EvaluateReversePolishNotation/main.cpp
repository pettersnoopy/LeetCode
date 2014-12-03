//
//  main.cpp
//  EvaluateReversePolishNotation
//
//  Created by pettersnoopy on 14-11-21.
//  Copyright (c) 2014年 ZheJiang University Luop. All rights reserved.
//


/*  Evaluate the value of an arithmetic expression in Reverse Polish Notation.

    Valid operators are +, -, *, /. Each operand may be an integer or another expression.

    Some examples:
    ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
    ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 
 */


#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    
    int change(string s) {
        stringstream ss;
        ss<<s;
        int i;
        ss>>i;
        return i;
    }
    
    bool isNum(string s) {
        stringstream sin(s);
        double t;
        char p;
        if (!(sin >>t)) {
            return false;
        }
        if (sin>>p) {
            return false;
        } else return true;
    }
    
    int evalRPN(vector<string> &tokens) {
        stack<int> st;
        vector<string>::iterator it;
        int result = 0;
        for (it = tokens.begin(); it != tokens.end(); it++) {
            if (isNum(*it)) {
                st.push(change(*it));
                continue;
            }
            
            int a, b;
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            switch ((*it)[0]) {
                case '+':
                    st.push(b + a);
                    break;
                case '-':
                    st.push(b - a);
                    break;
                case '*':
                    st.push(b * a);
                    break;
                case '/':
                    st.push(b / a);
                    break;
            }
            
        }
        return st.top();
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

