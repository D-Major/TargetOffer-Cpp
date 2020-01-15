#include <iostream>
#include <vector>

using namespace std;

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}    // 构造函数初值列
    Interval(int s, int e) : start(s), end(e) {}
};

template <typename T>
void print(vector<T> myVector) {
    if (myVector.empty())
        return;
    cout << "[";
    for (auto elem : myVector)
        if (elem != myVector.back()) cout << elem << ",";
        else cout << elem;
    cout << "]";
}

template <typename T>
void print(vector<vector<T>> matrix) {
    if (matrix.empty())
        return;
    cout << "[";
    for (auto row : matrix) {
        if (row != matrix.front()) cout << " [";
        else cout << "[";
        for (auto elem : row)
            if (elem != row.back()) cout << elem << ",";
            else cout << elem;
        if (row != matrix.back()) cout << "]" << endl;
        else cout << "]";
    }
    cout << "]" << endl;
}

void print_interval(vector<Interval> intervals) {
//    for (int i = 0; i < intervals.size(); ++i) {
//        cout << "[" << intervals[i].start << ", " << intervals[i].end << "]" << endl;
//    }
    for (auto interval : intervals) {
        cout << "[" << interval.start << ", " << interval.end << "]" << endl;
    }
}
