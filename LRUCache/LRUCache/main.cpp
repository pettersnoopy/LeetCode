//
//  main.cpp
//  LRUCache
//
//  Created by pettersnoopy on 14-11-24.
//  Copyright (c) 2014年 ZheJiang University Luop. All rights reserved.
//


/*  
    Design and implement a data structure for Least Recently Used (LRU) cache. It should support the 
    following operations: get and set.
    get(key) - Get the value (will always be positive) of the key if the key exists in the cache,
    otherwise return -1.
    set(key, value) - Set or insert the value if the key is not already present. When the cache reached
    its capacity, it should invalidate the least recently used item before inserting a new item.
 
 */

#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

struct node {
    int key;
    int value;
    node *pre;
    node *next;
};

class LRUCache{
public:
    node *head = nullptr;
    int length = 0;
    int capOfLinklist;
    LRUCache(int capacity) {
        capOfLinklist = capacity;
    }
    
    int get(int key) {
        if (head != nullptr) {
            while (head) {
                if (head->key == key) {
                    return head->value;
                } else {
                    head = head->next;
                }
            }
        }
        return -1;
    }
    
    void set(int key, int value) {
        if (length <= capOfLinklist) {
            if (head == nullptr) {
                head->key = key;
                head->value = value;
                head->pre = nullptr;
                head->next = nullptr;
                length++;
            } else {
                while (head) {
                    if (head->key == key) {
                        break;
                    } else {
                        head = head->next;
                    }
                }
                node *a = head->pre;
                node *b = head->next;
                a->next = b;
                b->pre = a;
                
                node *p;
                p->key = key;
                p->value = value;
                b->next = p;
                p->pre = b;
            }

        } else {
            while (head) {
                if (head->key == key) {
                    break;
                } else {
                    head = head->next;
                }
            }
            node *a = head->pre;
            node *b = head->next;
            a->next = b;
            b->pre = a;
            
            node *p;
            p->key = key;
            p->value = value;
            b->next = p;
            p->pre = b;
            
        }
    }

};



int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

