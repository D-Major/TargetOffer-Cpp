#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include "utils/print_funcs.cpp"
#include "utils/Link_List.cpp"
#include "Target-Offer/07_QueueWithTwoStacks.cpp"

using namespace std;

int main(){
    vector<int> test_vec = {2, 3, 1, 1, 4};
    vector<vector<int>> test_matrix = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
    };

    Stack_Queue* queue = new Stack_Queue();
    for(int i = 1; i <= 10; i++)
    {
        printf("%d ", i);
        queue->push(i);
    }
    for(int i = 10; i > 0; i--)
        printf("%d ", queue->pop());

    return 0;
}