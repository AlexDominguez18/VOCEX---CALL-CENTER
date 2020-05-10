#ifndef AGENT_H
#define AGENT_H

#include <iostream>
#include <string>

#include "name.h"
#include "clientlist.h"
#include "schedule.h"
#include "time.h"

class Agent {
private:
    unsigned int employeeNum;
    Name name;
    std::string speciality;
    unsigned int extensionNum;
    Schedule schedule;
    Time extraHours;

    ClientList clientList;
public:
    Agent();
    ~Agent();
    Agent(const Agent&);

    void setEmpNum(const unsigned int&);
    void setName(const Name&);
    void setSpeciality(const std::string&);
    void setExtNum(const int&);
    void setSchedule(const Schedule&);
    void setExtHours(const Time&);

    Name getName() const;
    int getEmpNum() const;
    std::string getSpeciality() const;
    int getExtNum() const;
    Schedule getShedule() const;
    Time getExtHours() const;
    ClientList& getClientList();

    std::string toString() const;

    Agent& operator = (const Agent&);
    bool operator == (const Agent&) const;
    bool operator != (const Agent&) const;
    bool operator > (const Agent&)  const;
    bool operator >= (const Agent&) const;
    bool operator < (const Agent&)  const;
    bool operator <= (const Agent&) const;

    friend std::istream& operator >> (std::istream&,Agent&);
    friend std::ostream& operator << (std::ostream&,Agent&);
};

#endif // AGENT_H
