#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include "utils/print_funcs.cpp"
#include "utils/Link_List.cpp"
#include "utils/QuickSort.cpp"
#include "Target-Offer/09_Fibonacci.cpp"

using namespace std;

int main(){
    vector<int> test_vec = {3, 4, 1, 1, 2};
    vector<int> test_vec_2 = {1,2,3,4,5};
    vector<vector<int>> test_matrix = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
    };

    cout << JumpFloor(5);

    return 0;
}