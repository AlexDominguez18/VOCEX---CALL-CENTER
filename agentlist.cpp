
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
#include <sstream>
#include "agentlist.h"

using namespace std;

bool AgentList::isValidPos(AgentNode* p){
    AgentNode* aux(header->getNext());
    while(aux != header){
        if (aux == p){
            return true;
        }
        aux = aux->getNext();
    }
    return false;
}

void AgentList::copyAll(const AgentList& l){
    AgentNode* aux(l.header->getNext());
    AgentNode* newAgentNode;

    while (aux != l.header){
        newAgentNode = new AgentNode(aux->getData());
        newAgentNode->setPrev(aux->getPrev());
        newAgentNode->setNext(header);
        header->getPrev()->setNext(newAgentNode);
        header->setPrev(newAgentNode);
        aux = aux->getNext();
        }
    }

void AgentList::swapPtr(AgentNode* a,AgentNode* b){
    if (a != b){
        Agent* aux(a->getDataPtr());
        a->setDataPtr(b->getDataPtr());
        b->setDataPtr(aux);
        }
    }

void AgentList::sortByName(AgentNode* leftEdge,AgentNode* rightEdge){
    if (leftEdge == rightEdge){ ///Default case
        return;
        }

    if (leftEdge->getNext() == rightEdge){ ///When we have only two elements
        if (leftEdge->getData().getName() > rightEdge->getData().getName()){
            swapPtr(leftEdge,rightEdge);
            }
        return;
        }

    AgentNode* i(leftEdge);
    AgentNode* j(rightEdge);

    while (i != j){
        ///Left edge comparison
        while(i != j and i->getData().getName() <= rightEdge->getData().getName()){
            i = i->getNext();
            }
        ///Right edge comparison
        while (i != j and j->getData().getName() >= rightEdge->getData().getName()){
            j = j->getPrev();
            }
        swapPtr(i,j);
        }
    swapPtr(i,rightEdge);

    if (i != leftEdge){
        sortByName(leftEdge,i->getPrev());
        }

    if (i != rightEdge){
        sortByName(i->getNext(),rightEdge);
        }
    }

void AgentList::sortBySpeciality(AgentNode* leftEdge,AgentNode* rightEdge){
    if (leftEdge == rightEdge){ ///Default case
        return;
        }

    if (leftEdge->getNext() == rightEdge){ ///When we have only two elements
        if (leftEdge->getData().getSpeciality() > rightEdge->getData().getSpeciality()){
            swapPtr(leftEdge,rightEdge);
            }
        return;
        }

    AgentNode* i(leftEdge);
    AgentNode* j(rightEdge);

    while (i != j){
        ///Left edge comparison
        while(i != j and i->getData().getSpeciality() <= rightEdge->getData().getSpeciality()){
            i = i->getNext();
            }
        ///Right edge comparison
        while (i != j and j->getData().getSpeciality() >= rightEdge->getData().getSpeciality()){
            j = j->getPrev();
            }
        swapPtr(i,j);
        }
    swapPtr(i,rightEdge);

    if (i != leftEdge){
        sortBySpeciality(leftEdge,i->getPrev());
        }

    if (i != rightEdge){
        sortBySpeciality(i->getNext(),rightEdge);
        }
    }

AgentList::AgentList(): header(new AgentNode()){
    if (header == nullptr){
        throw ListException("Memoria no disponible, AgentList()");
        }
    header->setPrev(header);
    header->setNext(header);
    }

AgentList::~AgentList(){
    deleteAll();
    delete header;
}

AgentList::AgentList(const AgentList& l): AgentList(){
    copyAll(l);
    }

bool AgentList::isEmpty(){
    return header->getNext() == header;
    }

void AgentList::insertData(AgentNode* p,const Agent& a){
    if (!isValidPos(p) and p!=nullptr){
        throw ListException("Posición inválida, insertData()");
        }
    if (p == nullptr){
        p = header;
    }
    AgentNode* newNode;
    try{
        newNode = new AgentNode(a);
    }catch(NodeException& ex){
        string msg("Error, no se pudo insertar el nodo");
        msg+=ex.what();
        throw NodeException(msg);
    }
    if (newNode == nullptr){
       throw ListException("Memoria no disponible, insertData(AgentNode*,const Agent&)");
    }
    newNode->setPrev(p);
    newNode->setNext(p->getNext());
    p->getNext()->setPrev(newNode);
    p->setNext(newNode);
}

void AgentList::deleteData(AgentNode* p){
    if (!isValidPos(p)){
        throw ListException("Posicion invalida, deleteData");
        }

    p->getPrev()->setNext(p->getNext());
    p->getNext()->setPrev(p->getPrev());
    delete p;
}

AgentNode* AgentList::getFirstPos(){
    if (isEmpty()){
        return nullptr;
    }
    return header->getNext();
}

AgentNode* AgentList::getLastPos(){
    if (isEmpty()){
        return nullptr;
    }
    return header->getPrev();
    }

AgentNode* AgentList::getPrevPos(AgentNode* p){
    if (!isValidPos(p) or p == header){
        return nullptr;
        }
    return p->getPrev();
    }

AgentNode* AgentList::getNextPos(AgentNode* p){
    if (p==header->getPrev() or !isValidPos(p)){
        return nullptr;
        }
    return p->getNext();
    }

string AgentList::toString(const bool& op) const{
    string s,saux;
    int nl,sl,i;
    AgentNode* aux(header->getNext());
    stringstream ss;
    while(aux != header){
        saux = "";
        s = std::to_string(aux->getData().getEmpNum());
        for (i=0;i<5;i++){
            saux += s[i];
        }
        nl = strlen(aux->getData().getName().toString().c_str());
        sl = strlen(aux->getData().getSpeciality().c_str());
        ss << "|" << saux << "|";
        ss << aux->getData().getName().toString() << setfill(' ') << setw(33-nl) << "|";
        ss << aux->getData().getSpeciality() << setfill(' ') << setw(15-sl) << "|";
        saux = "";
        s = std::to_string(aux->getData().getExtNum());
        for (i=0;i<6;i++){
            if (i<s.length()){
                saux += s[i];
            }
            else{
                saux += " ";
            }
        }
        ss << saux << "|";
        ss << aux->getData().getShedule().toString() << endl;
        ss << "|";
        for (i=1;i<79;i++){
            ss << "-";
        }
        ss << "|" << endl;
        if (op){
            ss << "| Lista de clientes: ";
            ss << aux->getData().toString();
            ss << "|";
            for (i=1;i<79;i++){
                ss << "_";
                }
            ss << "|";
            }
        aux = aux->getNext();
        }
    return ss.str();
    }

AgentNode* AgentList::findData(const Agent& a){
    AgentNode* aux(header->getNext());
    while (aux != header){
        if (aux->getData() == a){
            return aux;
            }
        aux = aux->getNext();
        }
    return nullptr;
    }

Agent& AgentList::retrieve(AgentNode* p){
    if (!isValidPos(p)){
        throw ListException("Posicion invalida, retrieve");
        }
    return p->getData();
    }

void AgentList::sortByName(){
    sortByName(header->getNext(),header->getPrev());
    }

void AgentList::sortBySpeciality(){
    sortBySpeciality(header->getNext(),header->getPrev());
    }

void AgentList::deleteAll(){
    AgentNode* aux;

    while(header->getNext() != header){
        aux = header->getNext();
        header->setNext(aux->getNext());
        delete aux;
        }
    header->setPrev(header);
}

AgentList& AgentList::operator=(const AgentList& l){
    deleteAll();
    copyAll(l);
    return *this;
    }

void AgentList::writeToDisk(const string& fileName){
    ofstream myFile;

    myFile.open(fileName,ios_base::trunc);

    if (!myFile.is_open()){
        string message;

        message = "Error al tratar de abrir el archivo ";
        message += fileName;
        message += " para escritura.";

        throw ListException(message);
        }

    AgentNode* aux(header->getNext());
    system("del *_clientes.*");
    while (aux != header){
        myFile << aux->getData() << endl;
        stringstream ss;
        ss << aux->getData().getEmpNum();
        string str = ss.str();
        try{
            aux->getData().getClientList().writeToDisk(str + "_clientes.txt");
        } catch (ListException& ex){
            cout << ex.what() << endl;
            }
        aux = aux->getNext();
        }
    myFile.close();
    }

void AgentList::readFromDisk(const string& fileName){
    ifstream myFile;

    myFile.open(fileName);

    if (!myFile.is_open()){
        string message;

        message = "Error al tratar de abrir el archivo ";
        message += fileName;
        message += " para lectura.";

        throw ListException(message);
        }

    Agent a;
    AgentNode* aux;

    deleteAll();

    while (myFile >> a){
        stringstream ss;
        ss << a.getEmpNum();
        string str = ss.str();
        try{
            a.getClientList().readFromDisk(str + "_clientes.txt");
        }catch (ListException& ex){
            cout << "Ocurrió un error a la hora de leer: ";
            cout << ex.what();
            }
        if ((aux = new AgentNode(a)) == nullptr){
            myFile.close();
            throw ListException("Memoria no disponible, AgentList::readFromDisk");
            }

        aux->setPrev(header->getPrev());
        aux->setNext(header);
        header->getPrev()->setNext(aux);
        header->setPrev(aux);
        }
    myFile.close();
    }
