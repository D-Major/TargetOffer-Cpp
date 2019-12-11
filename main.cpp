#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include "utils/print_funcs.cpp"
#include "utils/Link_List.cpp"
#include "Target-Offer/12_Print1ToMax.cpp"
#include "Target-Offer/13_DeleteNodeInO(1).cpp"

using namespace std;

int main(){
    vector<int> test_vec = {4,7,9,6,1,2,5,6,3,0,-1,11};
    vector<int> test_vec_2 = {1,2,3,4,5};
    vector<vector<int>> test_matrix = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
    };

//    Print1ToMax(2);

    LinkList L;
    InitList(&L);
    CreateList(&L, 3);
    LinkList deleted_node = L->next->next;
//    printf("%d", deleted_node->data);
    DeleteNode(&L, deleted_node);
    ListTraverse(L);
    return 0;
}