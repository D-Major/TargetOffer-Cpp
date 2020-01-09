// Created by renduo on 19-11-15.
#include <iostream>
#include <vector>

using namespace std;

/* Definition for binary tree */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}    // 构造函数
};

void PreOrderTraverse(TreeNode* T)
{
    if(T==NULL)
        return;
    cout << T->val << " ";/* 显示结点数据，可以更改为其它对结点操作 */
    PreOrderTraverse(T->left); /* 再先序遍历左子树 */
    PreOrderTraverse(T->right); /* 最后先序遍历右子树 */
}

void InOrderTraverse(TreeNode* T)
{
    if(T==NULL)
        return;
    InOrderTraverse(T->left); /* 中序遍历左子树 */
    cout << T->val << " ";/* 显示结点数据，可以更改为其它对结点操作 */
    InOrderTraverse(T->right); /* 最后中序遍历右子树 */
}

void PostOrderTraverse(TreeNode* T)
{
    if(T==NULL)
        return;
    PostOrderTraverse(T->left); /* 后序遍历左子树 */
    PostOrderTraverse(T->right); /* 后序遍历右子树 */
    cout << T->val << " ";/* 显示结点数据，可以更改为其它对结点操作 */
}

TreeNode* ReConstructBinaryTree(vector<int> pre,vector<int> vin) {
    if(pre.empty() || vin.empty())
        return NULL;
    TreeNode* root = new TreeNode(pre[0]);
    vector<int> pre_left, pre_right, in_left, in_right;
    int i = 0;
    while(vin[i] != pre[0]){
        pre_left.push_back(pre[i+1]);
        in_left.push_back(vin[i]);
        i++;
    }
    while(i+1 < pre.size()){
        pre_right.push_back(pre[i+1]);
        in_right.push_back(vin[i+1]);
        i++;
    }
    root->left = ReConstructBinaryTree(pre_left, in_left);
    root->right = ReConstructBinaryTree(pre_right, in_right);
    return root;
}

int TreeDepth(TreeNode* pRoot)
{
    if(!pRoot)
        return 0;
    int i = TreeDepth(pRoot->left);
    int j = TreeDepth(pRoot->right);
    return (i>j) ? (i+1) : (j+1);
}

TreeNode* LeftObliqueTree() {
    vector<int> left_pre_order = {1,2,3,4};
    vector<int> left_in_order = {4,3,2,1};
    TreeNode* left_oblique_tree = ReConstructBinaryTree(left_pre_order, left_in_order);
    return left_oblique_tree;
}

TreeNode* RightObliqueTree() {
    vector<int> right_pre_order = {5,6,7,8};
    vector<int> right_in_order = {5,6,7,8};
    TreeNode* right_oblique_tree = ReConstructBinaryTree(right_pre_order, right_in_order);
    return right_oblique_tree;
}

TreeNode* SingleNodeTree(){
    TreeNode* pRootNode = new TreeNode(5);
    return pRootNode;
}
