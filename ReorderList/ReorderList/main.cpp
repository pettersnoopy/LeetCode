//
//  main.cpp
//  ReorderList
//
//  Created by pettersnoopy on 14-11-28.
//  Copyright (c) 2014年 ZheJiang University Luop. All rights reserved.
//

//  Given a singly linked list L: L0→L1→…→Ln-1→Ln,
//  reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

//  You must do this in-place without altering the nodes' values.

//  For example,
//  Given {1,2,3,4}, reorder it to {1,4,2,3}.

#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    stack<ListNode *> s;
    void reorderList(ListNode *head) {
        ListNode *p = head;
        int length = 0;
        while (p) {
            length++;
            p = p->next;
        }
        if (length == 1) {
            return ;
        }
        p = head;
        int now = 0;
        while (p) {
            now++;
            if (now >= length / 2) {
                s.push(p);
            }
            p = p->next;
        }
        p = head;
        ListNode *temp = p;
        for (int i = 0; i<length; ++i) {
            if (i % 2 != 0) {
                ListNode *q = s.top();
                s.pop();
                temp->next = q;
                q->next = p;
                temp = p;
            } else {
                temp = p;
                p = p->next;
            }
            if (i == length - 1 && i % 2 != 0) {
                p->next = nullptr;
            }
            if (i == length - 1 && i % 2 == 0) {
                p->next->next = nullptr;
            }
        }
    }
    
    void print(ListNode *head) {
        while (head) {
            cout<<head->val<<" ";
            head = head->next;
        }
        cout<<endl;
    }
};

int main(int argc, const char * argv[])
{
    ListNode *p0 = new ListNode(0);
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(3);
    ListNode *p4 = new ListNode(4);
    ListNode *p5 = new ListNode(5);
    p0->next = p1;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    
    Solution sol;
    sol.print(p0);
    sol.reorderList(p0);
    sol.print(p0);

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

