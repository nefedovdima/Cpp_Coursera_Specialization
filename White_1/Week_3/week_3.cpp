#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

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
