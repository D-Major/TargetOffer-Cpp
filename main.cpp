#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include "utils/print_funcs.cpp"
#include "utils/Link_List.cpp"
#include "utils/QuickSort.cpp"

using namespace std;

int main(){
    vector<int> test_vec = {2, 3, 1, 1, 4};
    vector<vector<int>> test_matrix = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
    };

    vector<int> res = QuickSort(test_vec);
    print_vector(res);
}