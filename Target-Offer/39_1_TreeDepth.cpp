// Created by renduo on 20-1-7.
#include <iostream>
#include <vector>

using namespace std;

int TreeDepth(TreeNode* pRoot)
{
    if(!pRoot)
        return 0;
    int i = TreeDepth(pRoot->left);
    int j = TreeDepth(pRoot->right);
    return (i>j) ? (i+1) : (j+1);
}