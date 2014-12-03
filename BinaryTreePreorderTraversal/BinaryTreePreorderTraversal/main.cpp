//
//  main.cpp
//  BinaryTreePreorderTraversal
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
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:

    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode *> s;
        vector<int> preordered;
        if (root == nullptr) {
            return preordered;
        }
        s.push(root);
        while (!s.empty()) {
            root = s.top();
            s.pop();
            preordered.push_back(root->val);
            if (root->right != nullptr) s.push(root->right);
            if (root->left != nullptr) s.push(root->left);
        }
        
        return preordered;
    }
    
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

