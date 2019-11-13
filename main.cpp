#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "utils/print_funcs.cpp"
#include "Target-Offer/04_ReplaceBlank.cpp"

using namespace std;

int main(){
    int target = 6;
    char test_string[] = "We are happy.";
    int length = 20;
    vector<int> test_vec = {2, 3, 1, 1, 4};
    vector<int> test_vec_1 = {1, 2, 3, 4, 5};
    vector<Interval> test_intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> test_matrix = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
    };

    ReplaceBlank(test_string, length);

    return 0;
}