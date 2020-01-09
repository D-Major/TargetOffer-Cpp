// Created by renduo on 20-1-9.
#include <iostream>
#include <vector>

using namespace std;

void Mirror(TreeNode *pRoot) {
    // TODO: 为什么不用避免访问空的左孩子?只要不访问它的值就可以吗? (pRoot->left==NULL && pRoot->right))
    if (pRoot == NULL)
        return;
    TreeNode* pTemp = pRoot->left;
    pRoot->left = pRoot->right;
    pRoot->right = pTemp;
    if (pRoot->left)
        Mirror(pRoot->left);
    if (pRoot->right)
        Mirror(pRoot->right);
}