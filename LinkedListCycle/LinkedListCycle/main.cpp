//
//  main.cpp
//  LinkedListCycle
//
//  Created by pettersnoopy on 14-11-29.
//  Copyright (c) 2014年 ZheJiang University Luop. All rights reserved.
//

//    Given a linked list, determine if it has a cycle in it.
//
//    Follow up:
//    Can you solve it without using extra space?

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slowPointer, *fastPointer;
        slowPointer = fastPointer = head;
        if (slowPointer == nullptr) {
            return false;
        }
        do {
            if (slowPointer == nullptr || fastPointer == nullptr) {
                return false;
            }
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next;
            if (fastPointer == nullptr) {
                return false;
            }
            fastPointer = fastPointer->next;
            if (fastPointer == nullptr) return false;
        } while (slowPointer != fastPointer);
        return true;
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
    p5->next = p3;
    Solution sol;
    bool flag = sol.hasCycle(p0);
    cout<<flag;

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

