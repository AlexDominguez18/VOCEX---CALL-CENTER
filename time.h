#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <iostream>
#include <string>

class Time {
private:
    int hour;
    int minute;
    int second;

    bool isValid(const int& hour,const int& minute,const int& second) const;
public:
    Time();
    ~Time();
    Time(const Time&);
    Time(const int& hour,const int& minute,const int& second);

    void setHour(const int&);
    void setMinute(const int&);
    void setSecond(const int&);

    int getHour();
    int getMinute();
    int getSecond();
    int toInt() const;

    std::string toString() const;

    Time& operator = (const Time&);

    bool operator == (const Time&) const;
    bool operator != (const Time&) const;
    bool operator > (const Time&)  const;
    bool operator >= (const Time&) const;
    bool operator < (const Time&)  const;
    bool operator <= (const Time&) const;

    friend std::istream& operator >> (std::istream&,Time&);
    friend std::ostream& operator << (std::ostream&,const Time&);
};

#endif // TIME_H_INCLUDED
