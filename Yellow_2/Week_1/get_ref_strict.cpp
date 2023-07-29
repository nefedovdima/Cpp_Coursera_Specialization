#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <utility>
#include <sstream>
#include <algorithm>
using namespace std;

template <typename Key, typename Value>
Value& GetRefStrict(map<Key, Value>& m, const Key& key) {
    if (m.count(key) == 0) {
        throw runtime_error("Ключа " + to_string(key) + "нет в словаре");
    }
    return m.at(key);
}


int main() {
    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl;
    return 0;
}