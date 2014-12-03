//
//  main.cpp
//  InsertionSortList
//
//  Created by pettersnoopy on 14-11-24.
//  Copyright (c) 2014年 ZheJiang University Luop. All rights reserved.
//

//  Sort a linked list using insertion sort.

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode *newhead = head;
        if (head == nullptr) return nullptr;
        head = head->next;
        newhead->next = nullptr;
        while (head) {
            if (head->val < newhead->val) {
                ListNode *temp = head->next;
                head->next = newhead;
                newhead = head;
                head = temp;
                continue;
            }
            ListNode *pre = newhead;
            ListNode *p = newhead->next;
            while (p != nullptr && p->val < head->val) {
                p = p->next;
                pre = pre->next;
            }
            pre->next = head;
            head = head->next;
            pre = pre->next;
            pre->next = p;
        }
        return newhead;
    }
};

int main(int argc, const char * argv[])
{
    

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

