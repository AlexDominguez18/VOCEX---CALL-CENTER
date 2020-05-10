#ifndef AGENTLIST_H_INCLUDED
#define AGENTLIST_H_INCLUDED

#include <iostream>
#include <string>

#include "Agent.h"
#include "AgentNode.h"

class AgentList {
private:
    AgentNode* header;

    bool isValidPos(AgentNode*);
    void copyAll(const AgentList&);

    void swapPtr(AgentNode* a,AgentNode* b);
    void sortByName(AgentNode* leftEdge,AgentNode* rightEdge);
    void sortBySpeciality(AgentNode* leftEdge,AgentNode* rightEdge);


public:
    AgentList();
    ~AgentList();
    AgentList(const AgentList&);

    bool isEmpty();
    void insertData(AgentNode*,const Agent&);
    void deleteData(AgentNode*);

    AgentNode* getFirstPos();
    AgentNode* getLastPos();
    AgentNode* getPrevPos(AgentNode*);
    AgentNode* getNextPos(AgentNode*);
    std::string toString(const bool&) const;

    AgentNode* findData(const Agent&);
    Agent& retrieve(AgentNode*);

    void sortByName();
    void sortBySpeciality();
    void deleteAll();

    AgentList& operator = (const AgentList&);

    void writeToDisk(const std::string& fileName);
    void readFromDisk(const std::string& fileName);
};

#endif // AGENTLIST_H_INCLUDED
