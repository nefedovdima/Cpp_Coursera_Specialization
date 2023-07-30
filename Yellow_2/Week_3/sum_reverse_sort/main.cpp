#include <iostream>
#include "sum_reverse_sort.h"
using namespace std;

template <class T>
ostream& operator<<(ostream& os, const vector<T> v) {
    for (const auto& i : v)
        cout << i << " ";
    return os;
}

ostream& operator<<(ostream& os, const string& s) {
    for (const auto& i : s)
        cout << i;
    return os;
}

int main() {
    cout << Sum(5, 6) << "\n";
    vector<int> vec = {6, 4, 1};
    Sort(vec);
    cout << vec << "\n";
    string str = "hello";
    string rev_str = Reverse(str);
    cout << rev_str;
    return 0;
}
