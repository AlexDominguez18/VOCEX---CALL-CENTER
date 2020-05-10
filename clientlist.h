#ifndef CLIENTLIST_H_INCLUDED
#define CLIENTLIST_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>

#include "client.h"
#include "clientnode.h"
#include "listexception.h"

class ClientList {
private:
    ClientNode* anchor;

    bool isValidPos(ClientNode*) const;
    void copyAll(const ClientList&);

public:
    ClientList();
    ~ClientList();
    ClientList(const ClientList&);

    bool isEmpty() const;

    void insertData(ClientNode*,const Client&);
    void insertSortData(const Client&);

    void deleteData(ClientNode*);

    ClientNode* getFirstPos() const;
    ClientNode* getLastPos() const;
    ClientNode* getPrevPos(ClientNode*) const;
    ClientNode* getNextPos(ClientNode*) const;

    ClientNode* findData(const Client&) const;
    Client retrieve(ClientNode*) const;

    std::string toString() const;

    void deleteAll();

    ClientList& operator = (const ClientList&);

    void writeToDisk(const std::string& fileName);
    void readFromDisk(const std::string& fileName);
};

#endif // CLIENTLIST_H_INCLUDED
