#include "clientlist.h"
#include "listexception.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

bool ClientList::isValidPos(ClientNode* p) const{
    ClientNode* aux(anchor);

    while (aux != nullptr){
        if (aux == p){
            return true;
            }
        aux = aux->getNext();
        }
    return false;
    }

void ClientList::copyAll(const ClientList& l) {
    ClientNode* aux(l.anchor);
    ClientNode* last(nullptr);
    ClientNode* newClientNode;
    while (aux != nullptr){
        if ((newClientNode = new ClientNode(aux->getData())) == nullptr){
            throw ListException("Memory not available, copyALl");
            }
        if (last == nullptr){
            anchor = newClientNode;
            }
        else{
            last->setNext(newClientNode);
            }
        last = newClientNode;
        aux = aux->getNext();
        }

}

ClientList::ClientList(): anchor(nullptr){   }

ClientList::~ClientList(){
    deleteAll();
    }

ClientList::ClientList(const ClientList& l): anchor(nullptr){
    copyAll(l);
    }

bool ClientList::isEmpty() const{
    return anchor == nullptr;
    }

void ClientList::insertData(ClientNode* p, const Client& e){
    if (p != nullptr and !isValidPos(p)){
        throw ListException("Invalid position to insert");
        }
    ClientNode* aux(new ClientNode(e));
    if (aux == nullptr){
        throw ListException("Memory space not accessible");
        }
    if (p == nullptr){
        aux->setNext(anchor);
        anchor = aux;
        }
    else{
        aux->setNext(p->getNext());
        p->setNext(aux);
        }
    }

void ClientList::insertSortData(const Client& e){
    ClientNode* prev(nullptr);
    ClientNode* aux(anchor);

    while (aux != nullptr and e>aux->getData()){
        prev = aux;
        aux = aux->getNext();
        }
    insertData(prev,e);
    }

void ClientList::deleteData(ClientNode* p){
    if (!isValidPos(p)){
        throw ListException("Invalid position for delete data");
        }
    if (p == anchor){
        anchor = p->getNext();
        }
    else{
        getPrevPos(p)->setNext(p->getNext());
        }
    delete p;
    }

ClientNode* ClientList::getFirstPos() const{
    return anchor;
    }

ClientNode* ClientList::getLastPos() const{
    if (isEmpty()){
        return nullptr;
        }
    ClientNode* aux(anchor);
    while (aux->getNext() != nullptr){
        aux = aux->getNext();
        }
    return aux;
}

ClientNode* ClientList::getPrevPos(ClientNode* p) const{
    if (p == anchor){
        return nullptr;
        }
    ClientNode* aux(anchor);
    while (aux != nullptr and aux->getNext() != p){
        aux = aux->getNext();
        }
    return aux;
}

ClientNode* ClientList::getNextPos(ClientNode* p) const{
    if (!isValidPos(p)){
        return nullptr;
        }
    return p->getNext();
    }

ClientNode* ClientList::findData(const Client& e) const{
    ClientNode* aux(anchor);
    while (aux != nullptr and aux->getData()!=e){
        aux = aux->getNext();
        }
    return aux;
}

Client ClientList::retrieve(ClientNode* p)const{
    if (!isValidPos(p)){
        throw ListException("Invalid position, retrieve");
        }
    return p->getData();
}

string ClientList::toString() const{
    ClientNode* aux(anchor);
    int lengthName,lengthAttH,lengthCallD;
    stringstream ss;
    while (aux != nullptr){
        lengthName = aux->getData().getName().toString().length();
        lengthAttH = aux->getData().getAttentionHour().toString().length();
        lengthCallD = aux->getData().getCallDuration().toString().length();
        ss << "|";
        ss << aux->getData().getName().toString() << setfill(' ') << setw(50-lengthName);
        ss << "|";
        ss << aux->getData().getAttentionHour().toString() << setfill(' ') << setw(15-lengthAttH);
        ss << "|";
        ss << aux->getData().getCallDuration().toString() << setfill(' ') << setw(14-lengthCallD);
        ss << "|" << endl << "|";
        for (int i=1;i<79;i++){
            ss << "-";
        }
        ss << "|" << endl;
        aux = aux->getNext();
    }
    return ss.str();
}

void ClientList::deleteAll(){
    ClientNode* aux;
    while (anchor != nullptr){
        aux = anchor;
        anchor = anchor->getNext();
        delete aux;
        }
    }

ClientList& ClientList::operator=(const ClientList& l){
    deleteAll();
    copyAll(l);
    return *this;
    }

void ClientList::writeToDisk(const std::string& fileName){
    ofstream myFile;

    myFile.open(fileName,ios_base::trunc);

    if (!myFile.is_open()){
        string message;
        message = "Error al tratar de abrir el archivo ";
        message += fileName;
        message += " para la escritura";

        throw ListException(message);
        }

    ClientNode* aux(anchor);

    while (aux != nullptr){
        myFile << aux->getData() << endl;
        aux = aux->getNext();
        }

    myFile.close();
    }

void ClientList::readFromDisk(const string& fileName){
    ifstream myFile;

    myFile.open(fileName,ios_base::in);

    if (!myFile.is_open()){
        string message;

        message = "Error al tratar de abrir el archivo ";
        message += fileName;
        message += " para lectura.";

        throw ListException(message);
        }

    Client c;
    ClientNode* last(nullptr);
    ClientNode* newNode;

    deleteAll();

    while (myFile >> c){
        if ((newNode = new ClientNode(c)) == nullptr){
            myFile.close();
            throw ListException("Memoria no disponible, ClienList::readFromDisk");
            }
        if (last == nullptr){
            anchor = newNode;
            }
        else{
            last->setNext(newNode);
            }
        last = newNode;
        }
    myFile.close();
    }
