#include <iostream>
#include "rectangle.h"
using namespace std;

int main() {
    Rectangle r = Rectangle(5, 7);
    cout << r.GetArea() << "\n";
    cout << r.GetWidth() << "\n";
    cout << r.GetHeight() << "\n";
    cout << r.GetPerimeter() << "\n";
}
