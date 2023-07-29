#include <iostream>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
/*
class Date {
public:
    Date() {}
    Date(const int& new_year, const int& new_month, const int& new_day) {
        year = new_year;
        month = new_month;
        day = new_day;
    }
    int GetYear() const {
        return year;
    }
    int GetMonth() const {
        return month;
    }
    int GetDay() const {
        return day;
    }
private:
    int year{};
    int month{};
    int day{};
};

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() != rhs.GetYear())
        return lhs.GetYear() < rhs.GetYear();
    else if (lhs.GetMonth() != rhs.GetMonth())
        return lhs.GetMonth() < rhs.GetMonth();
    return lhs.GetDay() < rhs.GetDay();
}

ostream& operator<<(ostream& stream, const Date& date) {
    stream << setw(4) << setfill('0') << date.GetYear() << "-"
           << setw(2) << setfill('0') << date.GetMonth() << "-"
           << setw(2) << setfill('0') << date.GetDay();
    return stream;
}

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        db[date].insert(event);
    }
    bool DeleteEvent(const Date& date, const string& event) {
        if (db.count(date) > 0 && db[date].count(event) > 0) {
            db[date].erase(event);
            return true;
        }
        return false;
    }
    int  DeleteDate(const Date& date) {
        int deleted = 0;
        if (db.count(date) != 0) {
            deleted = db[date].size();
            db[date].clear();
        }
        return deleted;
    }

    [[nodiscard]] set<string> Find(const Date& date) const {
        if (db.count(date) > 0) {
            return db.at(date);
        }
        return {};
    }


    void Print() const {
        for (const auto& [date, events] : db) {
            for (const string& event : events) {
                cout << date << " " << event << "\n";
            }
        }
    }
private:
    map<Date, set<string>> db;
};

Date ParseDate(const string& date) {
    stringstream date_stream(date);

    bool ok = true;

    int year;
    ok = ok && (date_stream >> year);
    ok = ok && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int month;
    ok = ok && (date_stream >> month);
    ok = ok && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int day;
    ok = ok && (date_stream >> day);
    ok = ok && date_stream.eof();

    if (!ok) {
        throw logic_error("Wrong date format: " + date);
    }
    if (month < 1 || month > 12) {
        throw logic_error("Month value is invalid: " + to_string(month));
    }
    if (day < 1 || day > 31) {
        throw logic_error("Day value is invalid: " + to_string(day));
    }
    return {year, month, day};
}

int main() {
    Database db;
    string command_line;
    try {
        while (getline(cin, command_line)) {
            stringstream ss(command_line);
            string command;
            ss >> command;
            if (command == "Add") {
                string date_str, event;
                ss >> date_str >> event;
                Date date = ParseDate(date_str);
                db.AddEvent(date, event);

            }
            else if (command == "Del") {
                string date_str;
                ss >> date_str;
                string event;
                if (!ss.eof()) {
                    ss >> event;
                }
                const Date date = ParseDate(date_str);
                if (event.empty()) {
                    const int deleted = db.DeleteDate(date);
                    cout << "Deleted " << deleted << " events\n";
                }
                else {
                    bool event_deleted = db.DeleteEvent(date, event);
                    if (event_deleted)
                        cout << "Deleted successfully\n";
                    else
                        cout << "Event not found";
                }
            }
            else if (command == "Find") {
                string date_str;
                ss >> date_str;
                const Date date = ParseDate(date_str);
                set<string> events = db.Find(date);
                for (const string& ev : events) {
                    cout << ev << "\n";
                }
            }
            else if (command == "Print") {
                db.Print();
            }
            else if (!command.empty()) {
                throw logic_error("Unknown command: " + command);
            }
        }
    } catch (const exception& ex) {
        cout << ex.what();
    }
    return 0;
}
 */