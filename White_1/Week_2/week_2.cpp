#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>
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