#include <iostream>
#include <string>

using namespace std;

class Time {
private:
    unsigned int seconds;
    unsigned int minutes;
    unsigned int hours;

public:
    Time(unsigned int = 0, unsigned int = 0, unsigned int = 0);
    Time(const Time &);
    ~Time();
    Time &operator+(const unsigned int &);
    Time &operator+(const Time &);
    bool operator==(const Time &);
    string toString();
};

Time::Time(unsigned int h, unsigned int m, unsigned int s) {
    seconds = s % 60;
    minutes = m + s / 60;
    hours = h + minutes / 60;
    minutes = minutes % 60;
}

Time::Time(const Time &time) : seconds(time.seconds), minutes(time.minutes), hours(time.hours) {}

Time::~Time() {}

Time &Time::operator+(const unsigned int &s) {
    seconds += s;
    minutes += seconds / 60;
    hours += minutes / 60;
    seconds = seconds % 60;
    minutes = minutes % 60;
    return *this;
}

Time &Time::operator+(const Time &time) {
    seconds += time.seconds;
    minutes += time.minutes + seconds / 60;
    hours += time.hours + minutes / 60;
    seconds = seconds % 60;
    minutes = minutes % 60;
    return *this;
}

bool Time::operator==(const Time &time) {
    return seconds == time.seconds && minutes == time.minutes && hours == time.hours;
}

string Time::toString() {
    string h = to_string(hours);
    string m = to_string(minutes);
    string s = to_string(seconds);
    return h + ":" + m + ":" + s;
}

int main(int argc, char **argv) {
    Time t1(5, 3, 0);
    Time t2(4, 57, 60);
    Time t3(t2);
    t1 + t2;
    t1 + 6426;
    cout << t1.toString() << endl;
    cout << "T1 == T2: " << (t1 == t2) << endl;
    cout << "T2 == T3: " << (t2 == t3) << endl;
    return 0;
}
