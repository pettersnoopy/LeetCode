//
//  main.cpp
//  CopyListWithRandomPointer
//
//  Created by pettersnoopy on 14-12-3.
//  Copyright (c) 2014年 ZheJiang University Luop. All rights reserved.
//

//    A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
//
//    Return a deep copy of the list.

//   思路，遍历每个节点，每个节点的copy放在节点后面，然后将random指针按规则复制，最后拆开。

#include <iostream>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *p = head, *newhead = nullptr, *tmp;
        if(p == nullptr) return nullptr;
        while(p != nullptr) {
            tmp = new RandomListNode(p->label);
            tmp->next = p->next;
            p->next = tmp;
            p = tmp->next;
        }
        newhead = head->next;
        p = head;
        while (p) {
            tmp = p->next;
            tmp->random = p->random == nullptr ? nullptr : p->random->next;
            p = tmp->next;
        }
        p = head;
        while (p) {
            tmp = p->next;
            p->next = tmp->next;
            p = tmp->next;
            tmp->next = p == nullptr ? nullptr : p->next;
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

