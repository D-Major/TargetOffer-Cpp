#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include "utils/Print_Funcs.cpp"
#include "utils/Link_List.cpp"
#include "Target-Offer/12_Print1ToMax.cpp"
#include "Target-Offer/17_MergeSortedLists.cpp"

using namespace std;

int main(){
    vector<int> test_vec = {4,7,9,6,8,1,3,2,5,6,10,8,-1,11};
    vector<int> test_vec_2 = {-4,-3,-2,-1,1,2,3,4,5,6,7};
    vector<vector<int>> test_matrix = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
    };

//    Print1ToMax(2);
    ListNode* L1;
    ListNode* L2;
    CreateList(&L1, 1, 6, true);
    CreateList(&L2, 1, 7, true);
    ListNode* MergedList = Merge(L1->next, L2->next);
    ListTraverse(MergedList);

    return 0;
}