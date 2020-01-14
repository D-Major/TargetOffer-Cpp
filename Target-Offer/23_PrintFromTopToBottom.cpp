// Created by renduo on 20-1-14.
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> PrintFromTopToBottom(TreeNode* root) {
    vector<int> res;
    if (!root)
        return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        res.push_back(temp->val);
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    return res;
}