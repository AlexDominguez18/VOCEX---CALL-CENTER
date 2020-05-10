#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include "agent.h"
#include "consolaGotoxy.h"

using namespace std;

Agent::Agent(){}

Agent::~Agent(){}

Agent::Agent(const Agent& a): employeeNum(a.employeeNum),name(a.name),speciality(a.speciality),
    extensionNum(a.extensionNum),schedule(a.schedule), extraHours(a.extraHours),clientList(a.clientList){
    }

void Agent::setEmpNum(const unsigned int& n){
    employeeNum = n;
    }

void Agent::setName(const Name& n){
    name = n;
    }

void Agent::setSpeciality(const string& s){
    speciality = s;
    }

void Agent::setExtNum(const int& e){
    extensionNum = e;
    }

void Agent::setSchedule(const Schedule& s){
    schedule = s;
    }

void Agent::setExtHours(const Time& h){
    extraHours = h;
    }

Name Agent::getName() const{
    return name;
    }

int Agent::getEmpNum() const{
    return employeeNum;
    }

string Agent::getSpeciality() const{
    return speciality;
    }

int Agent::getExtNum() const{
    return extensionNum;
    }

Schedule Agent::getShedule() const{
    return schedule;
    }

Time Agent::getExtHours() const{
    return extraHours;
    }

ClientList& Agent::getClientList(){
    return clientList;
}

string Agent::toString() const{
    int ln,la,lc,i=1;
    string s;
    stringstream ss;
    ClientNode* aux;
    if (!clientList.isEmpty()){
        aux = clientList.getFirstPos();
        while(aux != nullptr){
            ln = aux->getData().getName().toString().length();
            la = aux->getData().getAttentionHour().toString().length();
            lc = aux->getData().getCallDuration().toString().length();
            s = std::to_string(i);
            ss << endl << "|" <<  i++ << setfill(' ') << right << setw(6-s.length());
            ss << "|" << aux->getData().getName().toString() << setfill(' ') << setw(43-ln);
            ss << "|";
            ss << aux->getData().getAttentionHour().toString() << setfill(' ') << setw(15-la);
            ss << "|";
            ss << aux->getData().getCallDuration().toString() << setfill(' ') << setw(15-lc);
            ss << "|";
            aux = aux->getNext();
            }
        }
    else{
        ss << "NO TIENE CLIENTES" << endl;
        }
    return ss.str();
    }

Agent& Agent::operator=(const Agent& a){
    employeeNum = a.employeeNum;
    name = a.name;
    speciality = a.speciality;
    extensionNum = a.extensionNum;
    schedule = a.schedule;
    extraHours = a.extraHours;
    clientList = a.clientList;
    return *this;
    }

bool Agent::operator==(const Agent& a) const{
    return employeeNum == a.employeeNum;
    }

bool Agent::operator!=(const Agent& a) const{
    return employeeNum != a.employeeNum;
    }

bool Agent::operator>(const Agent& a) const{
    return employeeNum > a.employeeNum;
    }

bool Agent::operator>=(const Agent& a) const{
    return employeeNum >= a.employeeNum;
    }

bool Agent::operator<(const Agent& a) const{
    return employeeNum < a.employeeNum;
    }

bool Agent::operator<=(const Agent& a) const{
    return employeeNum <= a.employeeNum;
    }

istream& operator >> (istream& is,Agent& a){
    string str;
    getline(is,str,'|');
    a.employeeNum = atoi(str.c_str());
    is >> a.name;
    getline(is,a.speciality,'|');
    getline(is,str,'|');
    a.extensionNum = atoi(str.c_str());
    is >> a.schedule;
    is.get();
    is >> a.extraHours;
    is.get();

    return is;
    }

ostream& operator << (ostream& os,Agent& a){
    os << a.employeeNum << "|";
    os << a.name << "|";
    os << a.speciality << "|";
    os << a.extensionNum << "|";
    os << a.schedule << "|";
    os << a.extraHours;
    return os;
    }
