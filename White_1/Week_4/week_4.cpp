#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <fstream>

using namespace std;

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

// Потоки ввода-вывода
int main() {
//    ifstream input("hello.txt");
//    string line;
//    getline(input, line);
//    cout << line << "\n";
//
//    getline(input, line);
//    cout << line << "\n";
//
//    getline(input, line);
//    cout << line << "\n";
// считываем сразу все строчки из файла
//    if (input.is_open()) {
//        while(getline(input, line)) {
//            cout << line << "\n";
//        }
//        cout << "file was writen";
//    }
//    else
//        cout << "write-time error";
    ifstream input("day.txt");
    string year, month, day;
    if (input) {
        getline(input, year, '-');
        getline(input, month, '-');
        getline(input, day, '-');
        cout << year;
    }
    cout << "year: " << year << "month: " << month
        << "day: " << day;
    return 0;
}
