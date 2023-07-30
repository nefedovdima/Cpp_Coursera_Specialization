#include "phone_number.h"
#include <sstream>
#include <iostream>

PhoneNumber::PhoneNumber(const string &international_number) {
    stringstream ss(international_number);

    bool ok = static_cast<bool>((ss.peek() == '+'));
    ss.ignore(1);

    int country_code;
    ok = ok && (ss >> country_code);

    ok = ok && ((ss.peek() == '-'));
    ss.ignore(1);

    int city_code;
    ok = ok && (ss >> city_code);

    ok = ok && ((ss.peek() == '-'));
    ss.ignore(1);

    string local_number;
    ok = ok && (ss >> local_number);

    if (!ok) {
        throw invalid_argument("Invalid, format");
    }
    country_code_ = to_string(country_code);
    city_code_ = to_string(city_code);
    local_number_ = local_number;
}

string PhoneNumber::GetCountryCode() const {
    return country_code_;
}
string PhoneNumber::GetCityCode() const {
    return city_code_;
}
string PhoneNumber::GetLocalNumber() const {
    return local_number_;
}
string PhoneNumber::GetInternationalNumber() const {
    return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
}