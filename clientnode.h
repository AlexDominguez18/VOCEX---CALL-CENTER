#ifndef CLIENTNODE_H_INCLUDED
#define CLIENTNODE_H_INCLUDED

#include "client.h"

class ClientNode {
private:
    Client data;
    ClientNode* next;
public:
    ClientNode();
    ~ClientNode();
    ClientNode(const Client&);

    void setData(const Client&);
    void setNext(ClientNode*);

    Client getData() const;
    ClientNode* getNext() const;
};

#endif // CLIENTNODE_H_INCLUDED
