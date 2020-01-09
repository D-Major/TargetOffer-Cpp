#include <iostream>
#include <vector>

using namespace std;

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

void print_vector(vector<int> myVector) {
    if (myVector.empty())
        return;
    vector<int>::iterator it = myVector.begin();
//    cout << "[";
    for (; it != myVector.end(); ++it)
        cout << *(it) << " ";
//    cout << "]";
}

void print_matrix(vector<vector<int>> matrix) {
    if (matrix.empty())
        return;
    for (auto row : matrix) {
        cout << "[";
        for (auto elem : row) {
            cout << elem << ", ";
        }
        cout << "]" << endl;
    }
}

void print_interval(vector<Interval> intervals) {
    for (int i = 0; i < intervals.size(); ++i) {
        cout << "[" << intervals[i].start << ", " << intervals[i].end << "]" << endl;
    }
}
