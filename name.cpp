#include "name.h"

#include <sstream>
#include <stdio.h>
#include <cstring>
#include <string.h>

using namespace std;

Name::Name(){
    first = "Undefined";
    last = "Undefined";
    }

Name::~Name(){ }

Name::Name(const Name& n){
    first = n.first;
    last = n.last;
    }

Name::Name(const string& last, const string& first){
    this->first = first;
    this->last = last;
    }

void Name::setLast(string& last){
    this->last = last;
    }

void Name::setFirst(string& first){
    this->first = first;
    }

string Name::toString() const{
    stringstream name;
    name << last << " " << first;
    return name.str();
    }

string Name::toUpper() const {
    string name;
    name += last + " " + first;
    for (unsigned int i = 0; i<name.length();i++){
            name[i] = toupper(name[i]);
        }
    return name;
    }

string Name::getLast(){
    return last;
    }

string Name::getFirst(){
    return first;
    }

Name& Name::operator=(const Name& n){
    first = n.first;
    last = n.last;
    return *this;
    }

bool Name::operator==(const Name& n) const{
    return toUpper() == n.toUpper();
    }

bool Name::operator!=(const Name& n) const{
    return toUpper() != n.toUpper();
    }

bool Name::operator>(const Name& n) const{
    return toUpper() > n.toUpper();
    }

bool Name::operator>=(const Name& n) const{
    return toUpper() >= n.toUpper();
    }

bool Name::operator<(const Name& n) const{
    return toUpper() < n.toUpper();
    }

bool Name::operator<=(const Name& n) const{
    return toUpper() <= n.toUpper();
    }

ostream& operator << (ostream& os,const Name& n){
    os << n.last << ",";
    os << n.first;
    return os;
    }

istream& operator >> (istream& i,Name& n){
    getline(i, n.last, ',');
    getline(i, n.first,'|');
    return i;
    }
