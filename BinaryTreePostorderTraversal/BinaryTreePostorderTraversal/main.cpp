//
//  main.cpp
//  BinaryTreePostorderTraversal
//
//  Created by pettersnoopy on 14-11-27.
//  Copyright (c) 2014年 ZheJiang University Luop. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> postordered;
        stack<TreeNode *> s;
        if (root == nullptr) {
            return postordered;
        } else {
            TreeNode *p;
            TreeNode *pre = nullptr;
            s.push(root);
            while (!s.empty()) {
                p = s.top();
                if ((p->left == nullptr && p->right == nullptr) || ((pre!=nullptr) && (pre == p->left || pre == p->right))) {
                    postordered.push_back(p->val);
                    s.pop();
                    pre = p;
                    
                } else {
                    if (p->right) {
                        s.push(p->right);
                    }
                    if (p->left) {
                        s.push(p->left);
                    }
                }
                
            }
        }
       
        
        return postordered;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

