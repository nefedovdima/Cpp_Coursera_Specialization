// Пример тестирование функции Суммы с помощью assert
#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <utility>
#include <sstream>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

template <typename T>
T Sum(const T& x, const T& y) {
    return x + y;
}
void TestSum() {
    assert(Sum(2, 3) == 5);
    assert(Sum(-2, -3) == -6);
    assert(Sum(2, 0) == 2);
    assert(Sum(2, -2) == 0);
    assert(Sum(2.2, 3.3) == 5.5);
    cout << "TestSum Ok" << endl;
}


int main() {
    TestSum();
    return 0;
}