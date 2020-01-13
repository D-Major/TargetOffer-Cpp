#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include "utils/Print_Funcs.cpp"
#include "utils/Link_List.cpp"
#include "utils/Tree_Node.cpp"
#include "Target-Offer/12_Print1ToMax.cpp"
#include "Target-Offer/22_IsPopOrder.cpp"
#include "Target-Offer/21_StackWithMin.cpp"

using namespace std;

int main(){
    vector<int> test_vec = {4,7,9,6,8,1,3,2,5,6,10,8,-1,11};
    vector<vector<int>> test_matrix = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
    };
    /* 构造一个链表 */
//    ListNode* L1;
//    CreateList(&L1, 10, true);
    /* 构造一棵树 */
    vector<int> pre_order = {1,2,4,8,9,5,10,3,6,7};
    vector<int> in_order = {8,4,9,2,10,5,1,6,3,7};
    TreeNode* pRoot = ReConstructBinaryTree(pre_order, in_order);
    /* ========题目代码======== */
//    Print1ToMax(2);
    StackWithMin* s = new StackWithMin();
    s->push(4);
    s->push(3);
    s->push(1);
    s->push(5);
    s->pop();
    s->pop();
    s->push(0);

    vector<int> push_vec = {1,2,3,4,5};
    vector<int> pop_vec = {4,3,5,1,2};
    vector<int> pop_vec2 = {4,5,3,2,1};
    cout << IsPopOrder(push_vec, pop_vec2);

    return 0;
}