#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;
/*
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
*/