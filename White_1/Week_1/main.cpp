using namespace std;
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

// 1.Минимальная строка
/*
int main() {
    string a, b, c;
    cin >> a >> b >> c;
    if (a <= b && a <= c)
        cout << a;
    else if (b <= a && b <= c)
        cout << b;
    else
        cout << c;
    return 0;
}
*/


// 2.Квадратное уравнение
/*
int main() {
    double a, b, c;
    cin >> a >> b >> c;
    if (a == 0) {
        if (b != 0)
            cout << -c / b;
    }
    else {
        double D;
        D = b*b - 4*a*c;
        if (D == 0)
            cout << -b / (2*a);
        else if (D > 0) {
            double x1, x2;
            x1 = (-b + sqrt(D)) / (2*a);
            x2 = (-b - sqrt(D)) / (2*a);
            cout << x1 << " "<< x2;
        }
    }
    return 0;
}
*/

// 3.Деление
/*
int main() {
    int a, b;
    cin >> a >> b;
    if (b == 0)
        cout << "Impossible";
    else
        cout << a / b;
    return 0;
}
*/


// 4.Расчет стоимости товара
/*
int main() {
    double n, a, b, x, y;
    cin >> n >> a >> b >> x >> y;
    if (n > b)
        cout << n * (1 - y / 100);
    else if (n > a)
        cout << n * (1 - x / 100);
    else
        cout << n;
    return 0;
}
*/

// 5. Четные числа
/*
int main() {
    int a, b;
    cin >> a >> b;
    if (a % 2 == 1)
        a++;
    // a становится первым четным >= a
    while (a <= b) {
        cout << a << " ";
        a += 2;
    }
    return 0;
}
*/


// 6. Второе вхождение
/*
int main() {
    string s;
    cin >> s;
    int meet_f = -2;
    for (int i=0; i < s.size(); ++i) {
        if (s[i] == 'f') {
            if (meet_f == -2)   // если f встретилась первый раз
                meet_f = -1;    //ставим f в -1
            else {              // если f встретилась второй раз
                meet_f = i;     //записываем в f индекс второго вхождения
                break;          // и выходим
            }
        }
    }
    cout << meet_f;
}
 */

// 7. НОД
//Работает только на малых a и b
/*
int main() {
    int a, b;
    cin >> a >> b;
    while (b != 0) {
        int tmp;
        // a, b = b, a % b
        tmp = a;
        a = b;
        b = tmp % b;
    }
    cout << a;
    return 0;
}
 */

// 8. Двоичные числа
/*
int main() {
    int n;
    cin >> n;
    vector<int> bits;
    while (n != 0) {
        bits.push_back(n % 2);
        n /= 2;
    }
    for (int i=0; i< bits.size(); ++i) {
        cout << bits[bits.size()-1-i];
    }
    return 0;
}
 */
