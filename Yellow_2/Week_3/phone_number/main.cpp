#include <iostream>
#include "phone_number.h"
using namespace std;

int main() {
    string phone_num;
    cin >> phone_num;
    auto phone = PhoneNumber(phone_num);
    cout << "GetCityCode: " <<phone.GetCityCode() << "\n";
    cout << "GetCountryCode: " <<phone.GetCountryCode() << "\n";
    cout << "GetInternationalNumber: " <<phone.GetInternationalNumber() << "\n";
    cout << "GetLocalNumber: " <<phone.GetLocalNumber() << "\n";
    return 0;
}


