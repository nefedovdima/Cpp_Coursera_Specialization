#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <utility>
#include <sstream>
#include <algorithm>
using namespace std;

// База регионов
/*
enum class Lang {
    DE, FR, IT
};

struct Region {
    string std_name;
    string parent_std_name;
    map<Lang, string> names;
    int64_t population;
};

int FindMaxRepetitionCount(const vector<Region>& regions) {
    int max_repetition = 0;
    map<tuple<string, string, map<Lang, string>, int64_t>, int> repetition_count;
    for (const Region& region : regions) {
        auto reg = tie(region.std_name,
                       region.parent_std_name,
                       region.names,
                       region.population);
        ++repetition_count[reg];
        max_repetition = max(max_repetition, repetition_count[reg]);
    }
    return max_repetition;
}

int main() {
    cout << FindMaxRepetitionCount({{
        "Moscow",
        "Russia",
        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
        89},{
        "Russia",
        "Eurasia",
        {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
        89}, {
        "Moscow",
        "Russia",
        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
        89}, {
        "Moscow",
        "Russia",
        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
        89}, {
        "Russia",
        "Eurasia",
        {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
        89}}) << endl;

    cout << FindMaxRepetitionCount({{
        "Moscow",
        "Russia",
        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
        89}, {
        "Russia",
        "Eurasia",
        {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
        89}, {
        "Moscow",
        "Russia",
        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
        89}, {
        "Moscow",
        "Toulouse",
        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
        89}, {
        "Moscow",
        "Russia",
        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
        31}}) << endl;

    return 0;
}
*/
// Введение в шаблоны

template <typename First, typename Second>
pair<First, Second> operator*(const pair<First, Second>& lhs,
                              const pair<First, Second>& rhs) {
    pair<First, Second> res = {lhs.first *rhs.first,
                               lhs.second*rhs.second};
    return res;
}

template <typename T>
T Sqr(const T& x) {
    return x*x;
}

template <typename First, typename Second>
ostream& operator<<(ostream& os, const pair<First, Second>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

template <class Collection>
string Join(const Collection& c, const string& sep) {
    stringstream ss;
    bool first = true;
    for (const auto i : c) {
        if (!first)
            ss << sep;
        first = false;
        ss << i;
    }
    return ss.str();
}

// Универсальные функции вывода в поток

template <class Key, class Value>
ostream& operator<< (ostream& out, const map<Key, Value>& m) {
    return out << "{" << Join(m, ", ") << "}";
}

template <class T>
ostream& operator<< (ostream& out, const vector<T> v) {
    return out << "["<< Join(v, ", ") << "]";
}

template <class T>
        T Max(const T& a, const T& b) {
            if (a > b)
                return a;
            return b;
        }

int main() {
    cout << Sqr(2) << " " << Sqr(2.5) << "\n";
    auto p = make_pair(2, 3.5);
    cout << Sqr(p) << "\n";
    //
    vector<double> vi = {1.1, 2, 3.14};
    cout << vi << endl;
    //
    map<int, int> m = { {1, 2}, {3, 4} };
    cout << m << endl;
    //
    vector<map<int, vector<string>>> vector_mapov = { {{1, {"hello", "it's", "me"}},
                                                      {2, {"just", "kill", "a", "man"}}},
                                                      {{3, {"pull", "me", "against his head"}},
                                                       {4, {"other"}}}
                                                      };
    cout << vector_mapov << "\n";
    //
    cout << "Max from 2 and 5.5: "<< Max<double>(2, 5.5) << "\n";
    cout << "Max from 2 and 5.5: "<< Max<int>(2, 5.5) << "\n";
    cout << "Max from 2 and 5.5: "<< max<float>(2, 5.5) << "\n";
    return 0;
}
