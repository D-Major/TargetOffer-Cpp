#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include "utils/Print_Funcs.cpp"
#include "utils/Link_List.cpp"
#include "Target-Offer/12_Print1ToMax.cpp"
#include "Target-Offer/16_ReverseList.cpp"

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
    ListNode* L;
    CreateList(&L, 10, false);
    ListNode* ReverseHead = ReverseList(L);
    cout << ReverseHead->val << endl;
    ListTraverse(ReverseHead);

    return 0;
}