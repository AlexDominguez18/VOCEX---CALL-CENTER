#include <iostream>
#include <string>
#include <sstream>

#include "client.h"
#include "time.h"

using namespace std;

Client::Client(){ }

Client::~Client(){ }

Client::Client(const Client& c): name(c.name), attentionHour(c.attentionHour), callDuration(c.callDuration){ }


void Client::setName(const Name& n){
    name = n;
    }

void Client::setAttentionHour(const Time& t){
    attentionHour = t;
    }

void Client::setCallDuration(const Time& t){
    callDuration = t;
    }

Name Client::getName() const {
    return name;
    }

Time Client::getAttentionHour() const {
    return attentionHour;
    }

Time Client::getCallDuration() const{
    return callDuration;
    }

string Client::toString() const{
    stringstream stringResult;

    stringResult << name.toString() << "|";
    stringResult << attentionHour.toString() << "|";
    stringResult << callDuration.toString();

    return stringResult.str();
}

Client& Client::operator=(const Client& c){
    name = c.name;
    attentionHour = c.attentionHour;
    callDuration = c.callDuration;

    return *this;
    }

bool Client::operator==(const Client& c) const{
    return attentionHour.toInt() == c.attentionHour.toInt();
    }

bool Client::operator!=(const Client& c) const{
    return attentionHour.toInt() != c.attentionHour.toInt();
    }

bool Client::operator>(const Client& c) const{
    return attentionHour.toInt() > c.attentionHour.toInt();
    }

bool Client::operator>=(const Client& c) const{
    return attentionHour.toInt() >= c.attentionHour.toInt();
    }

bool Client::operator<(const Client& c) const{
    return attentionHour.toInt() < c.attentionHour.toInt();
    }

bool Client::operator<=(const Client& c) const{
    return attentionHour.toInt() <= c.attentionHour.toInt();
    }

istream& operator >> (istream& is,Client& c){
    is >> c.name;
    is >> c.attentionHour;
    is.get();
    is >> c.callDuration;
    is.get();

    return is;
    }

ostream& operator << (ostream& os,const Client& c){
    os << c.name << "|";
    os << c.attentionHour << "|";
    os << c.callDuration;
    return os;
    }
