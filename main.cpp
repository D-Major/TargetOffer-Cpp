#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <unordered_map>
#include <algorithm>
#include "utils/Print_Funcs.h"
#include "utils/Link_List.h"
#include "utils/Tree_Node.h"
#include "Target-Offer/12_Print1ToMax.cpp"
#include "Target-Offer/28_StringPermutation.cpp"
#include "Target-Offer/30_KLeastNumbers.cpp"
#include "Target-Offer/09_Fibonacci.cpp"

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
//    vector<int> pre_order = {1,2,4,8,9,5,10,3,6,7};
//    vector<int> in_order = {8,4,9,2,10,5,1,6,3,7};
//    TreeNode* pRoot = ReConstructBinaryTree(pre_order, in_order);
    /* ========题目代码======== */
//    Print1ToMax(2);
//    string s = "abc";
//    vector<string> res = Permutation(s);
//    print(res);
//    print(GetLeastNumbers_Solution(test_vec, 6));
    Fibonacci_Str(6, "abc", "af");


    return 0;
}