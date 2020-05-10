#include "clientnode.h"

using namespace std;

ClientNode::ClientNode(): next(nullptr) {   }

ClientNode::~ClientNode(){  }

ClientNode::ClientNode(const Client& c): data(c), next(nullptr) {   }

void ClientNode::setData(const Client& e){
    data = e;
    }

void ClientNode::setNext(ClientNode* e) {
    next = e;
    }

Client ClientNode::getData() const{
    return data;
    }

ClientNode* ClientNode::getNext() const{
    return next;
    }

