using namespace std;
#include <iostream>
#include <string>

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
}