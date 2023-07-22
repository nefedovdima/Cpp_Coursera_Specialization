#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
using namespace std::chrono;


// 1. Факториал
/*
int Factorial(int n) {
    int p = 1;
    for (int i=2; i <=n; ++i) {
        p *= i;
    }
    return p;
}

int main() {
    int n;
    cin >> n;
    cout << Factorial(n);
    return 0;
}
 */

// 2.IsPalindrome
/*
bool IsPalindrome(string s) {
    for (int i=0; i < s.size()/2; ++i) {
        if (s[i] != s[s.size()-1-i])
            return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    cout << IsPalindrome(s);
    return 0;
}*/

//3. PalindromeFilter
/*
vector<string> PalindromeFilter(const vector<string>& words, int MinLength) {
    vector<string> good_words;
    for (auto w : words) {
        if (w.size() >= MinLength) {
            bool good = true;
            for (int i = 0; i < w.size() / 2; ++i) {
                if (w[i] != w[w.size() - 1 - i]) {
                    good = false;
                    break;
                }
            }
            if (good)
                good_words.push_back(w);
        }
    }
    return good_words;
}


int main() {
    vector<string> words;
    int n;
    cout << "enter vector size:";
    cin >> n;
    cout << "enter MinLength: ";
    int MinLength;
    cin >> MinLength;
    cout << "enter vector: ";
    for (int i=0; i < n; ++i) {
        string word;
        cin >> word;
        words.push_back(word);
    }
    auto good_words = PalindromeFilter(words, MinLength);
    for (const auto& w : good_words) {
        cout << w << " ";
    }
    return 0;
}
 */


// Ex.Get-PrintMoscowPopulation
/*
struct Person {
    string name;
    string surname;
    int age;
};


vector<Person> GetMoscowPopulation();

void PrintMoscowPopulation(const vector<Person>& p) {
    cout << "There are " << p.size() << " people ";
    cout << "in Moscow\n";
}

int main() {
    auto start = steady_clock::now();
    vector<Person> people = GetMoscowPopulation();
    auto finish = steady_clock::now();
    cout << "GetMoscowPopulation: "
    << duration_cast<milliseconds>(finish - start).count() << "ms" << "\n";

    start = steady_clock::now();
    PrintMoscowPopulation(people);
    finish = steady_clock::now();
    cout << "PrintMoscowPopulation: "
         << duration_cast<milliseconds>(finish - start).count() << "ms";

    return 0;
}


vector<Person> GetMoscowPopulation() {
    vector<Person> population;
    for (int i=0; i < 12500000; ++i) {
        Person pers = {"Ivan", "Ivanov", i};
        population.push_back(pers);
    }
    return population;
}
 */

// 4. Максимизатор
/*
void UpdateIfGreater(int a, int& b) {
    if (a > b)
        b = a;
}

int main() {
    int a, b;
    cin >> a >> b;
    UpdateIfGreater(a, b);
    cout << "a = " << a << "\n";
    cout << "b = " << b;
    return 0;
}
 */

// 5. Перемещение строк
/*
void MoveStrings(vector<string>& source, vector<string>& destination) {
    for (const string& el : source)
        destination.push_back(el);
    source.clear();
}

int main() {
    vector<string> source = {"a", "b", "c"};
    vector<string> destination = {"z"};
    MoveStrings(source, destination);
    cout << "source: ";
    for (const auto& s : source) {
        cout << s << " ";
    }
    cout << "\n";
    cout << "destination:\n";
    for (const auto& d : destination)
        cout << d << " ";
}
 */

// 6. Разворот последовательности
/*
void Reverse(vector<int>& v) {
    for (int i=0; i < v.size()/2; ++i) {
        int tmp = v[v.size()-1-i];
        v[v.size()-1-i] = v[i];
        v[i] = tmp;
    }
}

int main() {
    vector<int> numbers = {1, 5, 3, 4, 2};
    Reverse(numbers);
    for (const auto& el :numbers) {
        cout << el << " ";
    }
    return 0;
}
*/

// 7. Разворот последовательности-2
/*
vector<int> Reversed(const vector<int>& v) {
    vector<int> ans;
    for (int i=0; i < v.size(); ++i) {
        ans.push_back(v[v.size()-1-i]);
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 5, 3, 4, 2};
    vector<int> rev_nums = Reversed(nums);
    cout << "nums: ";
    for (const auto& el : nums) {
        cout << el << " ";
    }
    cout << "\nrev_nums: ";
    for (const auto& el : rev_nums) {
        cout << el << " ";
    }
    return 0;
}
 */

// 8. Средняя температура
/*
int main() {
    int n;
    cin >> n;
    vector<int> t(n);
    // вычисление среднего
    int mean;
    int s = 0;
    for (int& temp : t) {
        cin >> temp;
        s += temp;
    }
    mean = s / n;
    // поиск элементов, больших, чем среднее и иъ количества
    int k = 0;
    vector<int> greater_then_mean;
    for (int i=0; i<t.size(); ++i) {
        if (t[i] > mean) {
            greater_then_mean.push_back(i);
            ++k;
        }
    }
    // вывод результатов
    cout << k << "\n";
    for (const auto& el : greater_then_mean)
        cout << el << " ";
    return 0;
}
 */

// 9. Очередь
/*
int main() {
    vector<bool> worry;
    int q;
    cin >> q;
    for (int j=0; j<q; ++j) {
        string cmd;
        cin >> cmd;
        if (cmd == "WORRY") {
            int i;
            cin >> i;
            worry[i-1]=true;
        }
        else if (cmd == "QUIET") {
            int i;
            cin >> i;
            worry[i-1]=false;
        }
        else if (cmd == "COME") {
            int k;
            cin >> k;
            worry.resize(worry.size()+k, false);
        }
        else if (cmd == "WORRY_COUNT") {
            cout << count(begin(worry), end(worry), true);
        }
    }
    return 0;
}
 */

// 10. Ежедневные дела
/*
void PrintVector(const vector<vector<string>>& v) {
    for (int i=0; i<v.size(); ++i) {
        cout << i << ": ";
        for (const string& el : v[i]) {
            cout << el << " ";
        }
        cout << "\n";
    }
}

int main() {
    vector<int> days_by_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<vector<string>> deals(31);
    int current_month = 0;
    int q;
    cin >> q;
    for (int j=0; j<q; ++j) {
        string cmd;
        cin >> cmd;
        if (cmd == "ADD") {
            int i;
            cin >> i;
            string s;
            cin >> s;
            deals[i-1].push_back(s);
        }
        else if (cmd == "DUMP") {
            int i;
            cin >> i;
            for (const auto& deal : deals[i-1]) {
                cout << deal << " ";
            }
            cout << "\n";
        }
        else if (cmd == "NEXT") {
            int next_month = (current_month + 1) % 12;
            if (days_by_month[next_month] < days_by_month[current_month]) {
                for (auto day=days_by_month[next_month+1]-1;
                        day < days_by_month[current_month]; ++day) {
                    for (string& deal : deals[day]) {
                        deals[days_by_month[next_month]-1].push_back(deal);
                    }
                }
            }
            deals.resize(days_by_month[next_month]);
            current_month = next_month;
        }
        PrintVector(deals);
    }

    return 0;
}
 */

// 11. Анаграммы
/*
map<char, int> BuildCharCounters(const string& s) {
    map<char, int> counters;
    for (char ch : s) {
        ++counters[ch];
    }
    return counters;
}

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
        string first, second;
        cin >> first >> second;
        map<char, int> first_set = BuildCharCounters(first);
        map<char, int> second_set = BuildCharCounters(second);
        if (first_set == second_set)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    return 0;
}
 */

// 12.Справочик столиц

/*
void PrintMap(map<string, string> m) {
    cout << "--------------------------------------\n";
    for (const auto& [key, value] : m) {
        cout << key << ": " << value << " \n";
    }
    cout << "--------------------------------------\n";
}

int main() {
    map<string, string> capital_by_country;
    int q;
    cin >> q;
    for (int i=0; i<q; ++i) {
        string cmd;
        cin >> cmd;
        if (cmd == "CHANGE_CAPITAL") {
            string country, new_capital;
            cin >> country >> new_capital;
            if (capital_by_country.count(country) == 0) {
                capital_by_country[country] = new_capital;
                cout << "Introduce new country " << country << " with capital " << new_capital << "\n";
            }
            else {
                string old_capital = capital_by_country[country];
                if (old_capital == new_capital)
                    cout << "Country " << country << " hasn't changed its capital\n";
                else {
                    capital_by_country[country] = new_capital;
                    cout << "Country " << country << " has changed its capital from "
                    << old_capital << " to " << new_capital << "\n";
                }
            }
        }
        else if (cmd == "RENAME") {
            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;
            if (capital_by_country.count(old_country_name) == 0 || capital_by_country.count(new_country_name) == 1) {
                cout << "Incorrect rename, skip\n";
            }
            else {
                string capital = capital_by_country[old_country_name];
                capital_by_country.erase(old_country_name);
                capital_by_country[new_country_name] = capital;
                cout << "Country " << old_country_name << " with capital "
                << capital << " has been renamed to " << new_country_name << "\n";
            }
        }
        else if (cmd == "ABOUT") {
            string country;
            cin >> country;
            if (capital_by_country.count(country) == 0)
                cout << "Country "<< country << " doesn't exist\n";
            else {
                string capital = capital_by_country[country];
                cout << "Country " << country << " has capital " << capital << "\n";
            }
        }
        else if (cmd == "DUMP") {
            if (capital_by_country.empty()) {
                cout << "There are no countries in the world\n";
            }
            else {
                for (const auto& [country, capital] : capital_by_country) {
                    cout << country << ": " << capital << " ";
                }
                cout << "\n";
            }
        }
        PrintMap(capital_by_country);
    }
    return 0;
}
 */


// 13. Автобусные остановки
/*
void PrintMap(const map<string, vector<string>>& m) {
    for (const auto& item : m) {
        string key = item.first;
        vector<string> values = item.second;
        cout << key << ": ";
        for (const auto& v : values) {
            cout << v << " ";
        }
        cout << "\n";
    }
}

int main() {
    map<string, vector<string>> stops_by_bus;
    map<string, vector<string>> buses_by_stop;
    int q;
    cin >> q;

    for (int i=0; i<q; ++i) {
        string cmd;
        cin >> cmd;

        if (cmd == "NEW_BUS") {
            string bus;
            cin >> bus;
            int stop_count;
            cin >> stop_count;
            for (int j=0; j<stop_count; j++) {
                string stop;
                cin >> stop;
                stops_by_bus[bus].push_back(stop);
                buses_by_stop[stop].push_back(bus);
            }
        }
        else if (cmd == "BUSES_FOR_STOP") {
            string stop;
            cin >> stop;
            if (buses_by_stop.count(stop)==0) {
                cout << "No stop\n";
            }
            else {
                for (const auto& bus : buses_by_stop[stop]) {
                    cout << bus << " ";
                }
                cout << "\n";
            }
        }
        else if (cmd == "STOPS_FOR_BUS") {
            string bus;
            cin >> bus;
            if (stops_by_bus.count(bus) == 0)
                cout << "No bus\n";
            else {
                for (const auto& stop : stops_by_bus[bus]) {
                    cout << "Stop " << stop << ": ";
                    if (buses_by_stop[stop].size() == 1) {
                        cout << "No interchange\n";
                    }
                    else {
                        for (const auto& b : buses_by_stop[stop]) {
                            if (b != bus)
                                cout << b << " ";
                        }
                        cout << "\n";
                    }
                }
            }
        }
        else if (cmd == "ALL_BUSES") {
            if (stops_by_bus.empty())
                cout << "No buses\n";
            else {
                for (const auto &item: stops_by_bus) {
                    string bus = item.first;
                    vector<string> stops = item.second;
                    cout << "Bus " << bus << ": ";
                    for (const string &stop: stops) {
                        cout << stop << " ";
                    }
                    cout << "\n";
                }
            }
        }
        cout << "----------------------------------\n";
        cout << "stops_by_bus:\n";
        PrintMap(stops_by_bus);
        cout << "----------------------------------\n";
        cout << "buses_by_stop:\n";
        PrintMap(buses_by_stop);
        cout << "----------------------------------\n";
    }

    return 0;
}
 */



// 14. Анаграммы
/*
map<char, int> BuildCharCounters(const string& s) {
    map<char, int> counters;
    for (char ch : s) {
        ++counters[ch];
    }
    return counters;
}

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
        string first, second;
        cin >> first >> second;
        map<char, int> first_set = BuildCharCounters(first);
        map<char, int> second_set = BuildCharCounters(second);
        if (first_set == second_set)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    return 0;
}
 */

// 15.Справочик столиц

/*
void PrintMap(map<string, string> m) {
    cout << "--------------------------------------\n";
    for (const auto& [key, value] : m) {
        cout << key << ": " << value << " \n";
    }
    cout << "--------------------------------------\n";
}

int main() {
    map<string, string> capital_by_country;
    int q;
    cin >> q;
    for (int i=0; i<q; ++i) {
        string cmd;
        cin >> cmd;
        if (cmd == "CHANGE_CAPITAL") {
            string country, new_capital;
            cin >> country >> new_capital;
            if (capital_by_country.count(country) == 0) {
                capital_by_country[country] = new_capital;
                cout << "Introduce new country " << country << " with capital " << new_capital << "\n";
            }
            else {
                string old_capital = capital_by_country[country];
                if (old_capital == new_capital)
                    cout << "Country " << country << " hasn't changed its capital\n";
                else {
                    capital_by_country[country] = new_capital;
                    cout << "Country " << country << " has changed its capital from "
                    << old_capital << " to " << new_capital << "\n";
                }
            }
        }
        else if (cmd == "RENAME") {
            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;
            if (capital_by_country.count(old_country_name) == 0 || capital_by_country.count(new_country_name) == 1) {
                cout << "Incorrect rename, skip\n";
            }
            else {
                string capital = capital_by_country[old_country_name];
                capital_by_country.erase(old_country_name);
                capital_by_country[new_country_name] = capital;
                cout << "Country " << old_country_name << " with capital "
                << capital << " has been renamed to " << new_country_name << "\n";
            }
        }
        else if (cmd == "ABOUT") {
            string country;
            cin >> country;
            if (capital_by_country.count(country) == 0)
                cout << "Country "<< country << " doesn't exist\n";
            else {
                string capital = capital_by_country[country];
                cout << "Country " << country << " has capital " << capital << "\n";
            }
        }
        else if (cmd == "DUMP") {
            if (capital_by_country.empty()) {
                cout << "There are no countries in the world\n";
            }
            else {
                for (const auto& [country, capital] : capital_by_country) {
                    cout << country << ": " << capital << " ";
                }
                cout << "\n";
            }
        }
        PrintMap(capital_by_country);
    }
    return 0;
}
 */

// 16. Автобусные оставновки-2
/*
int main() {
    map<vector<string>, int> no_by_path;
    int no = 1;

    int q;
    cin >> q;
    for (int i=0; i<q; ++i) {
        int n;
        cin >> n;
        vector<string> path;
        for(int j=0; j<n; ++j) {
            string stop;
            cin >> stop;
            path.push_back(stop);
        }
        if (no_by_path.count(path) != 0) {
            int num = no_by_path[path];
            cout << "Already exists for " << num << "\n";
        }
        else {
            no_by_path[path] = no;
            cout << "New bus " << no << "\n";
            ++no;
        }
    }
    return 0;
}
*/

// Преобразование set -> vector. Обратно аналогично.
/*
int main() {
    set<string> s = {"cat", "dog", "bones", "milk"};
    vector<string> v(begin(s), end(s));
    for (auto& i : v) {
        cout << i << " ";
    }
    return 0;
}
*/

// 17. Количество уникальных строк
/*
int main() {
    int n;
    cin >> n;
    set<string> unique_words;
    for (int i=0; i<n; ++i) {
        string word;
        cin >> word;
        unique_words.insert(word);
    }
    cout << unique_words.size();
    return 0;
}
*/

// 18. Множество значений словаря
/*
set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> values;
    for (const auto& item : m) {
        string value = item.second;
        values.insert(value);
    }
    return values;
}


int main() {
    set<string> values = BuildMapValuesSet({
        {1, "odd"},
        {2, "even"},
        {3, "odd"},
        {4, "even"},
        {5, "odd"}
    });

    for (const string& value : values) {
        cout << value << endl;
    }
}
*/

// Синонимы
/*
int main() {
    map<string, set<string>> synonyms;
    int q;
    cin >> q;
    for (int i=0; i<q; ++i) {
        string cmd;
        cin >> cmd;
        if (cmd == "ADD") {
            string word1, word2;
            cin >> word1 >> word2;
            synonyms[word1].insert(word2);
            synonyms[word2].insert((word1));
        }
        else if (cmd == "COUNT") {
            string word;
            cin >> word;
            cout << synonyms[word].size() << "\n";
        }
        else if (cmd == "CHECK") {
            string word1, word2;
            cin >> word1 >> word2;
            if (synonyms[word1].count(word2)==1)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}
*/

// 19. Автобусные остановки-3
/*
int main() {
    map<set<string>, int> no_by_path;
    int no = 1;

    int q;
    cin >> q;
    for (int i=0; i<q; ++i) {
        int n;
        cin >> n;
        set<string> path;
        for(int j=0; j<n; ++j) {
            string stop;
            cin >> stop;
            path.insert(stop);
        }
        if (no_by_path.count(path) != 0) {
            int num = no_by_path[path];
            cout << "Already exists for " << num << "\n";
        }
        else {
            no_by_path[path] = no;
            cout << "New bus " << no << "\n";
            ++no;
        }
    }
    return 0;
}
*/
