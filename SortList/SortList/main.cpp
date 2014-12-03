//
//  main.cpp
//  SortList
//
//  Created by pettersnoopy on 14-11-24.
//  Copyright (c) 2014年 ZheJiang University Luop. All rights reserved.
//

//  Sort a linked list in O(n log n) time using constant space complexity.

#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};



class Solution {
public:
    ListNode init(ListNode *head) {
        ListNode *p = nullptr;
        cout<<"Please input the number of linklist:(under 100)";
        int numOfLinklist;
        cin>>numOfLinklist;
        cout<<"Please input the nodes of linklist:";
        for (int i = 0; i<numOfLinklist; i++) {
            int x;
            cin>>x;
            ListNode *temp =new ListNode(x);
            if (i == 0) {
                head = p = temp;
                continue;
            }
            p->next = temp;
            p = temp;
        }
        return *head;
    }
    
    ListNode *sortList(ListNode *head) {
        ListNode *p = head;
        int n = 0;
        while (p) {
            n++;
            p = p->next;
        }
        if (n <= 1) {
            return head;
        }
        n >>= 1;
        p = head;
        while (--n) {
            p = p->next;
        }
        ListNode *temp = p->next;
        p->next = nullptr;
        ListNode *pre = sortList(head);
        ListNode *aft = sortList(temp);
        ListNode *newhead;
        if (pre->val < aft->val) {
            newhead = pre;
            pre = pre->next;
        } else {
            newhead = aft;
            aft = aft->next;
        }
        p = newhead;
        while (pre != nullptr && aft != nullptr) {
            if (pre->val < aft->val) {
                p->next = pre;
                p = p->next;
                pre = pre->next;
            } else {
                p->next = aft;
                p = p->next;
                aft = aft->next;
            }
        }
        while (pre != nullptr) {
            p->next = pre;
            p = p->next;
            pre = pre->next;
        }
        while (aft != nullptr) {
            p->next = aft;
            p = p->next;
            aft = aft->next;
        }
        p->next = nullptr;
        return newhead;
        
        
    }
    
    void print(ListNode *head) {
        while (head) {
            cout<<head->val<<"->";
            head = head->next;
        }
    }
};

int main(int argc, const char * argv[])
{
    
    Solution sol;
    ListNode *head;
    sol.init(head);
    sol.print(head);
    cout<<endl;
    sol.sortList(head);
    cout<<endl;
    sol.print(head);
    cout<<endl;
    

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

