//
//  main.cpp
//  ListCycleII
//
//  Created by pettersnoopy on 14-11-29.
//  Copyright (c) 2014年 ZheJiang University Luop. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode *slow, *fast;
        slow = fast = head;
        int n = 0;
        do
        {
            n ++;
            if(slow == NULL || fast == NULL) return NULL;
            slow = slow->next;
            fast = fast->next;
            if(fast == NULL) return NULL;
            fast = fast->next;
            if(fast == NULL) return NULL;
        }while(slow != fast);
        fast = head;
        while(slow != fast)
            slow = slow->next, fast = fast->next;
        return fast;
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

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

