// Created by renduo on 20-1-10.
#include <iostream>
#include <vector>

using namespace std;

bool DoesTree1HaveTree2(TreeNode* pRoot1, TreeNode* pRoot2) {
    if (!pRoot2)    // 子结构已经循环完毕，代表全部匹配
        return true;
    if (!pRoot1)    // 大树已经循环完毕，并未成功匹配
        return false;
    if (pRoot1->val != pRoot2->val)     // 两个节点都存在但是不相等, 其相对位置是相同的
        return false;
    return DoesTree1HaveTree2(pRoot1->left, pRoot2->left) &&
            DoesTree1HaveTree2(pRoot1->right, pRoot2->right);
}

bool HasSubTree(TreeNode* pRoot1, TreeNode* pRoot2) {
    if (!pRoot1 || !pRoot2)
        return false;
    if (pRoot1->val == pRoot2->val) {
        if (DoesTree1HaveTree2(pRoot1, pRoot2))
            return true;
    }
    return HasSubTree(pRoot1->left, pRoot2) ||
            HasSubTree(pRoot1->right, pRoot2);
}