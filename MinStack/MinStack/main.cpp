//
//  main.cpp
//  MinStack
//
//  Created by pettersnoopy on 14-11-20.
//  Copyright (c) 2014年 ZheJiang University Luop. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    void push(int x) {
        st.push(x);
        if (min.empty()) {
            min.push(x);
        } else if (x <= min.top())
            min.push(x);
    }
    
    void pop() {
        if (st.top() == min.top()) {
            min.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min.top();
    }
    
private:
    stack<int> st;
    stack<int> min;
    
};

int main(int argc, const char * argv[])
{
    MinStack min;
//    int n;
//    cin>>n;
//    for (int i = 0; i<n; ++i) {
//        int x;
//        cout<<"please input the number you want to push:";
//        cin>>x;
//        min.push(x);
//    }
//    for (int i = 0; i<n; ++i) {
//        cout<<min.getMin()<<endl;
//        min.pop();
//    }
    min.push(0);
    min.push(1);
    min.push(0);
    cout<<min.getMin();
    min.pop();
    cout<<min.getMin();

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

