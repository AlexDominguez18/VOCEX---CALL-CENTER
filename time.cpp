#include "time.h"

#include <iostream>
#include <chrono>
#include <ctime>
#include <stdio.h>

using namespace std;


bool Time::isValid(const int& hour, const int& minute, const int& second) const{
    return (hour>=0 and hour<=24) and (minute>=0 and minute<60) and (second >=0 and second<60);
    }

Time::Time(){
    chrono::system_clock::time_point today(chrono::system_clock::now());
    time_t tt;
    tt = chrono::system_clock::to_time_t(today);
    struct tm* timeInfo;
    timeInfo = localtime(&tt);

    hour = timeInfo->tm_hour;
    minute = timeInfo->tm_min;
    second = timeInfo->tm_sec;
    }

int Time::toInt() const{
    return (hour*60*60) + (minute*60) + second;
    }

Time::~Time(){ }

Time::Time(const Time& t): hour(t.hour), minute(t.minute), second(t.second){ }

Time::Time(const int& h, const int& m, const int& s): Time() {
    if (isValid(h,m,s)){
        hour = h;
        minute = m;
        second = s;
        }
    }

void Time::setHour(const int& h){
    if (isValid(h,minute,second)){
        hour = h;
        }
    }

void Time::setMinute(const int& m){
    if (isValid(hour,m,second)){
        minute = m;
        }
    }

void Time::setSecond(const int& s){
    if (isValid(hour,minute,s)){
        second = s;
        }
    }

int Time::getHour(){
    return hour;
    }

int Time::getMinute(){
    return minute;
    }

int Time::getSecond(){
    return second;
    }

string Time::toString() const{
    char stringResult[8];

    sprintf(stringResult,"%02i:%02i:%02i",hour,minute,second);

    return stringResult;
    }

Time& Time::operator=(const Time& t){
    hour = t.hour;
    minute = t.minute;
    second = t.second;

    return *this;
    }

bool Time::operator==(const Time& t) const{
    return hour == t.hour and minute == t.minute and second == t.second;
    }

bool Time::operator!=(const Time& t) const{
    return hour != t.hour and minute != t.minute and second != t.second;
    }

bool Time::operator>(const Time& t) const{
    return toInt() > t.toInt();
    }

bool Time::operator>=(const Time& t) const{
    return toInt() >= t.toInt();
    }

bool Time::operator<(const Time& t) const{
    return toInt() < t.toInt();
    }

bool Time::operator<=(const Time& t) const{
    return toInt() <= t.toInt();
    }

istream& operator >> (istream& is,Time& t){
    string str;

    getline(is,str,':');
    t.hour = atoi(str.c_str());
    getline(is,str,':');
    t.minute = atoi(str.c_str());
    getline(is,str,'|');
    t.second = atoi(str.c_str());

    return is;
    }

ostream& operator << (ostream& os,const Time& t){
    os << t.toString() << "|";
    return os;
    }
