#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include "utils/print_funcs.cpp"
#include "utils/Link_List.cpp"
#include "Target-Offer/10_NumberOf1.cpp"

using namespace std;

int main(){
    vector<int> test_vec = {4,7,9,6,1,2,5,6,3,0,-1,11};
    vector<int> test_vec_2 = {1,2,3,4,5};
    vector<vector<int>> test_matrix = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
    };
    // 10000000 00000000 00000000 10000000
    // 11111111 11111111 11111111 01111111
    // 11111111 11111111 11111111 10000000
    cout << NumberOf1_Iterative(-128) << endl;
    return 0;
}