#ifndef AGENTNODE_H_INCLUDED
#define AGENTNODE_H_INCLUDED

#include <iostream>
#include <string>

#include "agent.h"

class NodeException : public std::exception {
private:
    std::string msg;

public:
    explicit NodeException(const char* message) : msg(message) { }

    explicit NodeException(const std::string& message) : msg(message) { }

    virtual ~NodeException() throw() { }

    virtual const char* what() const throw (){
        return msg.c_str();
        }
    };

class AgentNode {
private:
    Agent* dataPointer;
    AgentNode* prev;
    AgentNode* next;

public:
    AgentNode();
    ~AgentNode();
    AgentNode(const Agent&);

    void setData(const Agent&);
    void setDataPtr(Agent*);
    void setPrev(AgentNode*);
    void setNext(AgentNode*);

    Agent& getData() const;
    Agent* getDataPtr() const;
    AgentNode* getPrev() const;
    AgentNode* getNext() const;
};

#endif // AGENTNODE_H_INCLUDED
