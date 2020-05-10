#include <sstream>

#include "schedule.h"

using namespace std;


bool Schedule::isValid(const Time& s, const Time& e){
    return s < e;
    }

Schedule::Schedule(){ }

Schedule::~Schedule(){ }

Schedule::Schedule(const Schedule& s) : Schedule(){
    if (isValid(s.startTime,s.endTime)){
        startTime = s.startTime;
        endTime = s.endTime;
        }
    }

Schedule::Schedule(const Time& s, const Time& e) : Schedule(){
    if (isValid(s,e)){
        startTime = s;
        endTime = e;
        }
    }

void Schedule::setStart(const Time& s){
    this->startTime = s;
    }

void Schedule::setEnd(const Time& e){
    if (isValid(this->startTime,e)){
        this->endTime = e;
        }
    }

Time Schedule::getStart() const{
    return startTime;
    }

Time Schedule::getEnd() const{
    return endTime;
    }

string Schedule::toString() const{
    stringstream stringResult;
    stringResult << startTime.toString() << "|";
    stringResult << endTime.toString();
    return stringResult.str();
}

Schedule& Schedule::operator=(const Schedule& s){
    if (isValid(s.startTime,s.endTime)){
        this->startTime = s.startTime;
        this->endTime = s.endTime;
        }
        return *this;
    }

istream& operator >> (istream& is,Schedule& s){
    is >> s.startTime;
    is >> s.endTime;

    return is;
    }

ostream& operator << (ostream& os,Schedule& s){
    os << s.startTime;
    os << s.endTime;
    return os;
    }
