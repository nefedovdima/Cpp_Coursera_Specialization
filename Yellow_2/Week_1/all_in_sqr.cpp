#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <utility>
#include <sstream>
#include <algorithm>
using namespace std;
/*
// Sqr для чисел
template <typename T> T Sqr(const T& x);
// Оператор умножения для пар
template <typename First, typename Second>
pair<First, Second> operator*(const pair<First, Second>& lhs, const pair<First, Second>& rhs);
// Sqr для пар
template <typename First, typename Second> pair<First, Second> Sqr(const pair<First, Second>& p);
// Sqr для вектора
template <typename T> vector<T> Sqr(const vector<T>& v);
// Sqr для словаря
template <typename Key, typename Value> map<Key, Value> Sqr(const map<Key, Value>& m);

template <typename T>
T Sqr(const T& x) {
    return x * x;
}

template <typename First, typename Second>
pair<First, Second> operator*(const pair<First, Second>& lhs, const pair<First, Second>& rhs) {
    First f = lhs.first * rhs.first;
    Second s = lhs.second * rhs.second;
    return {f, s};
}

template <typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second>& p) {
    return p*p;
}

template <typename T>
vector<T> Sqr(const vector<T>& v){
    vector<T> sqred_v;
    for (const T& i : v)
        sqred_v.push_back(Sqr(i));
    return sqred_v;
}

template <typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value>& m){
    map<Key, Value> sqred_m;
    for (const pair<const Key, Value>& item : m)
        sqred_m[item.first] = Sqr(item.second);
    return sqred_m;
}


int main() {
    Sqr(make_pair(2, 7));
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
            {4, {2, 2}},
            {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }

    return 0;
}
 */