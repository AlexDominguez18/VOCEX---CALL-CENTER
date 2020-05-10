#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#include <iostream>
#include <sstream>

#include "Name.h"
#include "Time.h"

class Client {
private:
    Name name;
    Time attentionHour;
    Time callDuration;

public:
    Client();
    ~Client();
    Client(const Client&);

    void setName(const Name&);
    void setAttentionHour(const Time&);
    void setCallDuration(const Time&);

    Name getName() const;
    Time getAttentionHour() const;
    Time getCallDuration() const;

    std::string toString() const;

    Client& operator = (const Client&);

    bool operator == (const Client&) const;
    bool operator != (const Client&) const;
    bool operator > (const Client&)  const;
    bool operator >= (const Client&) const;
    bool operator < (const Client&)  const;
    bool operator <= (const Client&) const;

    friend std::istream& operator >> (std::istream&,Client&);
    friend std::ostream& operator << (std::ostream&,const Client&);
};


#endif // CLIENT_H_INCLUDED
