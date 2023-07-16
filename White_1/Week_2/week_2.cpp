#include <iostream>
#include <string>
#include <vector>
#include <chrono>
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

