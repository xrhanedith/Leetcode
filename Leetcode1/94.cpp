//
//  94.cpp
//  Leetcode1
//
//  Created by Xinran Han on 9/8/19.
//  Copyright © 2019 Xinran Han. All rights reserved.
//

#include <stdio.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result, result_right;
        if (root == NULL) return result;
        result = inorderTraversal(root->left);
        result.push_back(root->val);
        result_right = inorderTraversal(root->right);
        
        //could change to for loop
        result.insert(result.end(),result_right.begin(), result_right.end());
        return result;
    }
};
