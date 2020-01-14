// Created by renduo on 20-1-14.
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> res;
vector<int> path;

void find(TreeNode* node, int sum){
    path.push_back(node->val);
    if (!node->left && !node->right && node->val==sum)
        res.push_back(path);
    else {
        if (node->left) find(node->left, sum - node->val);
        if (node->right) find(node->right, sum - node->val);
    }
    path.pop_back();
}

vector<vector<int>> FindPath(TreeNode* root, int expectNumber){
    if (root)
        find(root, expectNumber);
    return res;
}