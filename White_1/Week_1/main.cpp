using namespace std;
#include <iostream>
#include <string>
#include <cmath>


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

