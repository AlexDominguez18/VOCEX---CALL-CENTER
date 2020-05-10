#ifndef SCHEDULE_H_INCLUDED
#define SCHEDULE_H_INCLUDED

#include <iostream>
#include <string>

#include "Time.h"

class Schedule {
private:
    Time startTime;
    Time endTime;

    bool isValid(const Time&,const Time&);
public:
    Schedule();
    ~Schedule();
    Schedule(const Schedule&);
    Schedule(const Time&,const Time&);

    void setStart(const Time&);
    void setEnd(const Time&);

    Time getStart() const;
    Time getEnd() const;
    std::string toString() const;

    Schedule& operator = (const Schedule&);

    friend std::istream& operator >> (std::istream&,Schedule&);
    friend std::ostream& operator << (std::ostream&,Schedule&);
};

#endif // SCHEDULE_H_INCLUDED
