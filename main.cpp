#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include "utils/print_funcs.cpp"
#include "utils/Link_List.cpp"
//#include "utils/QuickSort.cpp"
#include "Target-Offer/08_MinNumberInRotateArray.cpp"

using namespace std;

int main(){
    vector<int> test_vec = {3, 4, 1, 1, 2};
    vector<int> test_vec_2 = {1, 1, 1, 0, 1};
    vector<vector<int>> test_matrix = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
    };

    int res = MinNumberInRotateArray(test_vec);
    printf("%d", res);
    return 0;
}