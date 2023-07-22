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

// 5. Синонимы
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

// 20. Сортировка целых чисел по модулю
/*
int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i=0; i<n; ++i) {
        int el;
        cin >> el;
        v.push_back(el);
    }
    sort(begin(v), end(v),
         [](int x, int y) {
        return abs(x) < abs(y);}
        );
    for (const auto& item : v) {
        cout << item << " ";
    }
    return 0;
}
*/

// 21. Сортировка без учета регистра
/*
int main() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto& i : v) {
        cin >> i;
    }
    sort(begin(v), end(v),
         [](const string& first, const string& second){
       string first_low, second_low;
       for (const auto& ch : first) {
           first_low += std::to_string(tolower(ch));
       }
       for (const auto& ch : first) {
           second_low += std::to_string(tolower(ch));
       }
             return first_low < second_low;
    });
    for (const auto& i : v) {
        cout << i << " ";
    }
    return 0;
}
 */

// Source-Destination
/*
int ComputeDistance(
        const string& source,
        const string& destination) {
    int dist = (destination.length() - source.length()) * 150;
    return abs(dist);
}

class Route {
public:
    Route() {
        source = "Moscow";
        destination = "Yoshkar-Ola";
        UpdateLength();
    }
    Route(const string& new_source, const string& new_destination) {
        source = new_source;
        destination = new_destination;
        UpdateLength();
    }
    ~Route() {
        for (const string& entry : compute_distance_log) {
            cout << entry << "\n";
        }
    }
    string GetSource() const {return source;}
    string GetDestinaion() const {return destination;}
    int GetLength() const {return length;}
    void SetSource(const string& new_source) {
        source = new_source;
        UpdateLength();
    }
    void SetDestination(const string& new_destination) {
        destination = new_destination;
        UpdateLength();
    }
private:
    void UpdateLength() {
        length = ComputeDistance(source, destination);
        compute_distance_log.push_back(source + " - " + destination);
    }
    string source;
    string destination;
    int length{};
    vector<string> compute_distance_log{};
};

void PrintRoute(const Route& route) {
    cout << "Route from " << route.GetSource() << " to " <<
         route.GetDestinaion() << " is " <<
         route.GetLength() << " km long\n";
}

int main() {
    Route route1 = {"Moscow", "Yoshkar-Ola"};
    route1.SetSource("Vyborg");
    route1.SetSource("Vologda");
    PrintRoute(route1);


    return 0;
}
*/

// 22. Отсортированные строки
/*
class SortedStrings {
public:
    void AddString(const string& s) {
        data.push_back(s);
        sort(begin(data), end(data));
    }
    vector<string> GetSortedStrings() {
        return data;

    }
private:
    vector<string> data;
};

void PrintSortedStrings(SortedStrings& strings) {
    for (const string& s : strings.GetSortedStrings()) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    SortedStrings strings;

    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);

    strings.AddString("second");
    PrintSortedStrings(strings);

    return 0;
}
*/

// 23. Имена и фамилии-1
/*
string GetNameByYear(const map<int, string>& name_by_year, const int& year) {
    string name;
    for (const auto& item: name_by_year) {
        int y = item.first;
        if (y <= year) {
            name = item.second;
        }
        else
            break;
    }
    return name;
}

class Person {
private:
    map<int, string> name_by_year;
    map<int, string> lastname_by_year;
public:
    void ChangeFirstName(const int& year, const string& name) {
        name_by_year[year] = name;
    }
    void ChangeLastName(const int& year, const string& lastname) {
        lastname_by_year[year] = lastname;
    }
    string GetFullName(const int& year) {
        string name, lastname;
        name = GetNameByYear(name_by_year, year);
        lastname = GetNameByYear(lastname_by_year, year);

        if (name.empty() and lastname.empty()) {
            return "Incognito";
        }
        else if (!name.empty() and lastname.empty()) {
            return name + " with unknown last name";
        }
        else if (name.empty() and !lastname.empty()) {
            return lastname + " with unknown first name";
        }
        else {
            return name + " " + lastname;
        }
    }
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }
    return 0;
}
*/

// 24. Имена и фамилии-2
/*
vector<string> NamesHistory(const map<int, string>& name_by_year, const int& year) {
    // возращает вектор c историей имен в порядке возрастания годов их создания
    // принимает (словарь год->имя/фамилия, год)
    vector<string> names;
    for (const auto& item: name_by_year) {
        int now_year = item.first;
        // если год  не из будующего и либо вектор имен пуст, либо текущий элемент не свопадает с пред-им
        if (now_year <= year && (names.empty() || names.back() != item.second)) {
            // добавляем текущее имя в историю
            names.push_back(item.second);
        }
    }
    return names;
}

string BuildHistoryName(vector<string> names) {
    if (names.empty())
        return "";
    else {
        reverse(begin(names), end(names));
        string builded_name = names[0];
        for (int i=1; i<names.size(); ++i) {
            if (i == 1)
                builded_name += " (";
            else
                builded_name += ", ";
            builded_name += names[i];
        }
        if (names.size() > 1)
            builded_name += ")";
        return builded_name;
    }

}

string BuildFullName(const string& name, const string& lastname) {
    if (name.empty() and lastname.empty())
        return "Incognito";

    else if (!name.empty() and lastname.empty())
        return name + " with unknown last name";

    else if (name.empty() and !lastname.empty())
        return lastname + " with unknown first name";

    return name + " " + lastname;
}


class Person {
private:
    map<int, string> name_by_year;
    map<int, string> lastname_by_year;
public:
    void ChangeFirstName(const int& year, const string& name) {
        name_by_year[year] = name;
    }
    void ChangeLastName(const int& year, const string& lastname) {
        lastname_by_year[year] = lastname;
    }
    string GetFullName(const int& year) {
        string name, lastname;
//      // находим вектора истории имен и фамилий
        const vector<string> name_with_history = NamesHistory(name_by_year, year);
        const vector<string> lastname_with_history = NamesHistory(lastname_by_year, year);

        if (!name_with_history.empty())
            name = name_with_history.back();
        if (!lastname_with_history.empty())
            lastname = lastname_with_history.back();

        return BuildFullName(name, lastname);

    }
    string GetFullNameWithHistory(const int& year) {
        // находим вектора истории имен и фамилий
        const string history_name = BuildHistoryName(NamesHistory(name_by_year, year));
        const string history_lastname = BuildHistoryName(NamesHistory(lastname_by_year, year));

        return BuildFullName(history_name, history_lastname);
    }
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;

    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;

    return 0;
}
*/

// 25. Строка ReversibleString
/*
class ReversibleString {
public:
    ReversibleString() {};
    ReversibleString(const string& str) {
        data = str;
    }
    void Reverse() {
        reverse(begin(data), end(data));
    }
    string ToString() const {
        return data;
    }
private:
    string data;
};

int main() {
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
}
 */


// 26. Имена и фамилии-3
/*
vector<string> NamesHistory(const map<int, string>& name_by_year, const int& year) {
    // возращает вектор c историей имен в порядке возрастания годов их создания
    // принимает (словарь год->имя/фамилия, год)
    vector<string> names;
    for (const auto& item: name_by_year) {
        int now_year = item.first;
        // если год  не из будующего и либо вектор имен пуст, либо текущий элемент не свопадает с пред-им
        if (now_year <= year && (names.empty() || names.back() != item.second)) {
            // добавляем текущее имя в историю
            names.push_back(item.second);
        }
    }
    return names;
}

string BuildHistoryName(vector<string> names) {
    if (names.empty())
        return "";
    else {
        reverse(begin(names), end(names));
        string builded_name = names[0];
        for (int i=1; i<names.size(); ++i) {
            if (i == 1)
                builded_name += " (";
            else
                builded_name += ", ";
            builded_name += names[i];
        }
        if (names.size() > 1)
            builded_name += ")";
        return builded_name;
    }

}

string BuildFullName(const string& name, const string& lastname) {
    if (name.empty() and lastname.empty())
        return "Incognito";

    else if (!name.empty() and lastname.empty())
        return name + " with unknown last name";

    else if (name.empty() and !lastname.empty())
        return lastname + " with unknown first name";

    return name + " " + lastname;
}


class Person {
private:
    map<int, string> name_by_year;
    map<int, string> lastname_by_year;
    string name, lastname;
    int birthyear;
public:
    Person(const string& first_name,
           const string& last_name,
           const int& birth_year) {
        name = first_name;
        lastname = last_name;
        birthyear = birth_year;
        name_by_year[birth_year] = name;
        lastname_by_year[birth_year] = last_name;
    }
    void ChangeFirstName(const int& year, const string& new_name) {
        if (year >= birthyear){
            name = new_name;
            name_by_year[year] = name;
        }
    }
    void ChangeLastName(const int& year, const string& new_lastname) {
        if (year >= birthyear) {
            lastname = new_lastname;
            lastname_by_year[year] = lastname;
        }
    }
    string GetFullName(const int& year) {
        if (year < birthyear)
            return "No person";
//      // находим вектора истории имен и фамилий
        const vector<string> name_with_history = NamesHistory(name_by_year, year);
        const vector<string> lastname_with_history = NamesHistory(lastname_by_year, year);

        if (!name_with_history.empty())
            name = name_with_history.back();
        if (!lastname_with_history.empty())
            lastname = lastname_with_history.back();

        return BuildFullName(name, lastname);

    }
    string GetFullNameWithHistory(const int& year) {
        if (year < birthyear)
            return "No person";
        // находим вектора истории имен и фамилий
        const string history_name = BuildHistoryName(NamesHistory(name_by_year, year));
        const string history_lastname = BuildHistoryName(NamesHistory(lastname_by_year, year));

        return BuildFullName(history_name, history_lastname);
    }
};

int main() {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}
*/

// Поля по-умолчанию
/*
struct Lecture {
    string title = "C++";
    int duration = 0;
};

int main() {
    Lecture lec1 = {"OOP"};
    Lecture lec2 = {"", 27};
}
 */

// 27. Incognizable
/*
class Incognizable{
private:
    int fisrt, second;
public:
    Incognizable() {}
    Incognizable(const int& f) {
        fisrt = f;
    }
    Incognizable(const int& f, const int& s) {
        fisrt = f;
        second = s;
    }

};

struct Incognizable{
    int x=0;
    int y=0;
};

int main() {
    Incognizable a;
    Incognizable b = {};
    Incognizable c = {0};
    Incognizable d = {0, 1};
    return 0;
}
*/

// 28. Структура Date
/*
struct Day {
    int value;
    explicit Day(int new_value) {
        value = new_value;
    }
};

struct Month {
    int value;
    explicit Month(int new_value) {
        int value = new_value;
    }
};

struct Year {
    int value;
    explicit Year(int new_value) {
        value = new_value;
    }
};

struct Date {
    int date;
    int month;
    int year;
    Date(Day new_day, Month new_month, Year new_year) {
        date = new_day.value;
        month = new_month.value;
        year = new_year.value;
    }
};

void PrintDate(const Date& d) {
    cout << d.date << "." << d.month << "." << d.year << "\n";
}


int main() {
    Date date = {Day{21}, Month{7}, Year{23}};
//    Date date1 = {21, 7, 23}; - больше неработает.
//    Теперь неявное преобразование int в Date(int) невозможно
    PrintDate(date);
    return 0;
}
*/

// 29. Структура LectureTitle
/*
struct Specialization {
    string data;
    explicit Specialization(const string& new_data) {
        data = new_data;
    }
};
struct Course {
    string data;
    explicit Course(const string& new_data) {
        data = new_data;
    }
};

struct Week {
    string data;
    explicit Week(const string& new_data) {
        data = new_data;
    }
};



struct LectureTitle {
    string specialization;
    string course;
    string week;
    LectureTitle(const Specialization& new_specialization,
                 const Course& new_course,
                 const Week& new_week) {
        specialization = new_specialization.data;
        course = new_course.data;
        week = new_week.data;
    }
};


int main() {
    LectureTitle title(
            Specialization("C++"),
            Course("White belt"),
            Week("4th")
    );
    return 0;
}
 */

// 30. Класс FunctionPart
/*
struct Image {
    double quility;
    double freshness;
    double rating;
};

struct Params {
    double a;
    double b;
    double c;
};

class FunctionPart {
public:
    FunctionPart(char new_operation, double new_value) {
        operation = new_operation;
        value = new_value;
    }
    double Apply(double source_value) const {
        if (operation == '+') {
            return source_value + value;
        }
        else
            return source_value - value;
    }
    void Invert() {
        if (operation == '+')
            operation = '-';
        else
            operation = '+';
    }
private:
    char operation;
    double value;

};

class Function {
public:
    void AddPart(char operation, double value) {
        parts.push_back({operation, value});
    }
    double Apply(double value) const {
        for (const FunctionPart& part : parts) {
            value = part.Apply(value);
        }
        return value;
    }
    void Invert() {
        for (FunctionPart& part : parts) {
            part.Invert();
        }
        reverse(begin(parts), end(parts));
    }
private:
    vector<FunctionPart> parts;
};


Function MakeWeightFunction(const Params& params,
                            const Image& image) {
    Function function;
    function.AddPart('-', image.freshness * params.a + params.b);
    function.AddPart('+', image.rating * params.c);
    return function;
}


double ComputeImageWeight(const Params& params, const Image& image) {
    Function function = MakeWeightFunction(params, image);
    double weight = function.Apply(image.quility);
    return weight;
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              const double weight) {
    Function function = MakeWeightFunction(params, image);
    function.Invert();
    double quility = function.Apply(weight);
    return quility;
}

int main() {
    Image image = {10, 2, 6};
    Params params = {4, 2, 6};
    // weight = quility - freshness * a - b + rating * c
    // weight = 10 - 2 * 4 - 2 + 6 * 6 = 36
    cout << "weight: " << ComputeImageWeight(params, image) << "\n";
    cout << "quility: " << ComputeQualityByWeight(params, image, 36);
    return 0;
}
 */
int main() {
    return 0;
}