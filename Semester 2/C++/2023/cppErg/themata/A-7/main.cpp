#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

class Date {
private:
    unsigned int day;
    unsigned int month;
    unsigned int year;

public:
    Date(unsigned int = 1, unsigned int = 1, unsigned int = 1999);
    Date(const Date &);
    ~Date();
    Date &operator+(unsigned int);
    bool operator>(const Date &);
    Date operator=(const Date &);
    std::string toString();
};

Date::Date(unsigned int d, unsigned int m, unsigned int y) {
    if (d > 30 || m > 12)
        throw "Error. Invalid Date.";
    day = d;
    month = m;
    year = y;
}

Date::Date(const Date &date) {
    day = date.day;
    month = date.month;
    year = date.year;
}

Date::~Date() {}

Date &Date::operator+(unsigned int d) {
    day += d;
    month = month + day / 30;
    year = year + month / 12;
    day = day % 30;
    month = month % 12;
    if (day == 0) {
        day = 30;
        month--;
    }
    if (month == 0) {
        month = 12;
        year--;
    }
    return *this;
}

bool Date::operator>(const Date &date) {
    if (year > date.year)
        return true;
    else if (year == date.year && month > date.month)
        return true;
    else if (year == date.year && month == date.month && day > date.day)
        return true;
    return false;
}

Date Date::operator=(const Date &date) {
    return Date(date);
}

std::string Date::toString() {
    std::string d = std::to_string(day);
    std::string m = std::to_string(month);
    std::string y = std::to_string(year);
    return d + "/" + m + "/" + y;
}

std::vector<Date *> sort(std::vector<Date *> dates) {
    for (unsigned int i = 0; i < dates.size(); i++) {
        for (unsigned int j = i + 1; j < dates.size() - 1; j++) {
            if (*dates[i] > *dates[j]) {
                Date *tmp = dates[i];
                dates[i] = dates[j];
                dates[j] = tmp;
            }
        }
    }
    return dates;
}

int main(int argc, char **argv) {
    
    Date nikos(10, 4, 2666);
    Date bill(nikos);
    std::cout<< bill.toString()<< std::endl;
    try {
        Date d1;
        std::cout << d1.toString() << std::endl;
        Date d2(10, 2, 2003);
        std::cout << d2.toString() << std::endl;
        Date d4(d2);
        d4 + 21;
        std::cout << d4.toString() << std::endl;
        Date d3(365, 11, 2001);
        std::cout << d3.toString() << std::endl;
        
    } catch (const char *msg) {
        std::cerr << msg << std::endl;
    }

    std::cout << std::endl;
    
    return 0;
}
