
#include "agentnode.h"

using namespace std;

AgentNode::AgentNode(): dataPointer(nullptr),prev(nullptr),next(nullptr){
    }

AgentNode::~AgentNode(){
    delete dataPointer;
    }

AgentNode::AgentNode(const Agent& a): dataPointer(new Agent(a)),prev(nullptr),next(nullptr){
    if (dataPointer == nullptr){
        throw NodeException("Memoria no dispnible, AgentNode(const Agent& a)");
        }
    }

void AgentNode::setData(const Agent& a){
    if (dataPointer == nullptr){
        if ((dataPointer = new Agent(a)) == nullptr){
            throw NodeException("Memoria no disponible, setData(const Agent& a)");
            }
        }
    else{
        *dataPointer = a;
    }
}

void AgentNode::setDataPtr(Agent* p){
    dataPointer = p;
    }

void AgentNode::setPrev(AgentNode* p){
    prev = p;
    }

void AgentNode::setNext(AgentNode* p){
    next = p;
    }

Agent& AgentNode::getData() const{
    if (dataPointer == nullptr){
        throw NodeException("El dato no existe, getData()");
        }
    return *dataPointer;
    }

Agent* AgentNode::getDataPtr() const{
    return dataPointer;
    }

AgentNode* AgentNode::getPrev() const{
    return prev;
    }

AgentNode* AgentNode::getNext() const{
    return next;
    }
