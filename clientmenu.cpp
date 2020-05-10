#include <iostream>
#include <string>
#include <stdio.h>
#include <regex>
#include <cstring>
#include <string.h>
#include <cstdlib>
#include <clocale>

#include "clientmenu.h"

using namespace std;

void ClientMenu::mainMenu() {
    string optionsMenu[5]= {"1. AGREGARLE UN CLIENTE","2. MOSTRAR SU LISTA DE CLIENTES","3. MODIFICAR DATOS DE UN CLIENTE",
                            "4. ELIMINAR UN CLIENTE SU LISTA","5. REGRESAR AL MENÚ ANTERIOR"};
    bool returnMenu = false;
    int option;
    string op1;
    setlocale(LC_ALL,"spanish_mexico");
    do {
        system("cls");
        GoToXY::screenMenu();
        GoToXY::coords(31,3);
        cout << "CLIENTES ATENDIDOS";

        GoToXY::coords(10,7);
        cout << optionsMenu[0];
        GoToXY::coords(10,8);
        cout << optionsMenu[1];
        GoToXY::coords(10,9);
        cout << optionsMenu[2];
        GoToXY::coords(10,10);
        cout << optionsMenu[3];
        GoToXY::coords(10,11);
        cout << optionsMenu[4];
        GoToXY::coords(8,13);
        cout << "OPCIÓN: ";
        cin >> op1;
        if (regex_match(op1,regex("[1-5]"))){
            option =atoi(op1.c_str());
        }
        else{
            option = 0;
        }
        switch(option){
        case 1:
            Sleep(1000);
            addClient();
            break;
        case 2:
            Sleep(1000);
            showClientList();
            break;
        case 3:
            Sleep(1000);
            modifyClient();
            break;
        case 4:
            Sleep(1000);
            deleteClient();
            break;
        case 5:
            returnMenu = true;
            break;
        default:
            GoToXY::coords(20,20);
            cout << "¡OPCIÓN INVÁLIDA! INTENTELO DE NUEVO";
            Sleep(1000);
        }
    }while(!returnMenu);
}


void ClientMenu::enterToContinue(){
    cout << "| Presione enter para continuar . . .";
    cin.get();
    cin.get();
}

void ClientMenu::backToMenu(){
    GoToXY::coords(35,19);
    cout << "Regresando al menú anterior";
    for (int i=0;i<3;i++){
        Sleep(1000);
        cout << ". ";
        }
}

void ClientMenu::addClient() {
    string str;
    Client client;
    Name name;
    Time time,callD;
    ClientNode* pos;

    system("cls");
    GoToXY::screenMenu();
    GoToXY::coords(32,1);
    cout << "AGREGAR CLIENTE";
    GoToXY::coords(10,7);cout << "Nombre: ";
    cin.get();
    getline(cin,str);
    name.setFirst(str);

    GoToXY::coords(10,8);cout << "Apellido: ";
    getline(cin,str);
    name.setLast(str);
    client.setName(name);

    GoToXY::coords(10,9);
    cout << "Hora de atención (HH:MM:SS): ";
    getline(cin,str,':');
    time.setHour(atoi(str.c_str()));
    getline(cin,str,':');
    time.setMinute(atoi(str.c_str()));
    getline(cin,str);
    time.setSecond(atoi(str.c_str()));
    client.setAttentionHour(time);

    GoToXY::coords(10,10);
    cout << "Duración de la llamada (HH:MM:SS): ";
    getline(cin,str,':');
    callD.setHour(atoi(str.c_str()));
    getline(cin,str,':');
    callD.setMinute(atoi(str.c_str()));
    getline(cin,str);
    callD.setSecond(atoi(str.c_str()));
    client.setCallDuration(callD);

    pos = clientListPtr->findData(client);
    if (pos != nullptr){
        GoToXY::coords(10,15);
        cout << client.toString() << " - Ya está en la lista de clientes.";
        backToMenu();
        return;
    }
    try{
        clientListPtr->insertSortData(client);
        }
    catch (ListException& ex){
        GoToXY::coords(10,12);
        cout << "Error al tratar de agregar a " << name.toString() << "a la lista de clientes";
        }
    GoToXY::coords(10,12);
    cout << "¡Cliente agregado con éxito!";
    backToMenu();
    }

void ClientMenu::modifyClient() {
    int option;
    bool returnMenu = false;
    string str;
    Client client;
    Name name;
    Time attH;
    ClientNode* pos;
    string optionsMenu[4] = {"1. NOMBRE","2. HORA DE ATENCIÓN","3. DURACIÓN DE LLAMADA",
                            "4. REGRESAR AL MENÚ DE CLIENTES"};

    GoToXY::screenMenu();
    GoToXY::coords(2,5);
    cout << "Ingrese la hora de llamada del cliente a modificar (HH:MM:SS): ";
    getline(cin,str,':');
    attH.setHour(atoi(str.c_str()));
    getline(cin,str,':');
    attH.setMinute(atoi(str.c_str()));
    getline(cin,str);
    attH.setSecond(atoi(str.c_str()));
    client.setAttentionHour(attH);

    pos = clientListPtr->findData(client);
    if (pos != nullptr){
        client = clientListPtr->retrieve(pos);
    }
    else{
        GoToXY::coords(10,7);
        cout << "No existe níngun cliente con esa hora de llamada";
        backToMenu();
        return;
    }
    do{
        GoToXY::screenMenu();
        GoToXY::coords(10,7);
        cout << optionsMenu[0];
        GoToXY::coords(10,8);
        cout << optionsMenu[1];
        GoToXY::coords(10,9);
        cout << optionsMenu[2];
        GoToXY::coords(10,10);
        cout << optionsMenu[3];
        GoToXY::coords(8,13);
        cout << "OPCIÓN: ";
        cin >> option;
        cin.get();

        GoToXY::screenMenu();
        switch(option){
        case 1:
            GoToXY::coords(10,7);
            cout << "Nombre: ";
            getline(cin,str);
            name.setFirst(str);
            GoToXY::coords(10,8);
            cout << "Apellido: ";
            getline(cin,str);
            name.setLast(str);
            client.setName(name);
            backToMenu();
            break;
        case 2:
            GoToXY::coords(10,7);
            cout << "Hora de atención (HH:MM:SS): ";
            getline(cin,str,':');
            attH.setHour(atoi(str.c_str()));
            getline(cin,str,':');
            attH.setMinute(atoi(str.c_str()));
            getline(cin,str);
            attH.setSecond(atoi(str.c_str()));
            client.setAttentionHour(attH);
            backToMenu();
            break;
        case 3:
            GoToXY::coords(10,7);
            cout << "Duración de la llamada (HH:MM:SS): ";
            getline(cin,str,':');
            attH.setHour(atoi(str.c_str()));
            getline(cin,str,':');
            attH.setMinute(atoi(str.c_str()));
            getline(cin,str);
            attH.setSecond(atoi(str.c_str()));
            client.setCallDuration(attH);
            backToMenu();
            break;
        case 4:
            returnMenu = true;
            break;
        default:
            GoToXY::coords(20,12);
            cout << "¡OPCIÓN INVÁLIDA! INTENTELO DE NUEVO";
            }
        }while(!returnMenu);
        clientListPtr->insertData(pos,client);
        clientListPtr->deleteData(pos);
    }

void ClientMenu::showClientList() {
    GoToXY::screenMenu();
    GoToXY::coords(31,1);
    cout << "LISTA DE CLIENTES";
    GoToXY::coords(22,4);
    cout << "Nombre";
    GoToXY::coords(50,4);
    cout << "|";
    GoToXY::coords(53,4);
    cout << "Hora Att.";
    GoToXY::coords(65,4);
    cout << "|";
    GoToXY::coords(68,4);
    cout << "Duración";
    GoToXY::coords(1,5);
    for(int x = 1;x<79;x++){
        cout << "-";
    }
    cout << endl;
    cout << clientListPtr->toString();
    enterToContinue();
    }

void ClientMenu::deleteClient() {
    int option;
    char answer;
    Client client;
    Time time;
    ClientNode* pos;
    bool returnMenu = false;
    string str;
    string optionsMenu[3] = {"1. ELIMINAR UN CLIENTE","2. ELIMINAR A TODOS LOS CLIENTES",
                            "3. REGRESAR AL MENÚ DE CLIENTES"};
    do{
        GoToXY::screenMenu();
        GoToXY::coords(30,1);
        cout << "ELIMINAR CLIENTE(S)";
        GoToXY::coords(10,7);
        cout << optionsMenu[0];
        GoToXY::coords(10,8);
        cout << optionsMenu[1];
        GoToXY::coords(10,9);
        cout << optionsMenu[2];
        GoToXY::coords(8,11);
        cout << "OPCIÓN: ";
        cin >> option;
        cin.get();

        switch(option){
        case 1:
            GoToXY::screenMenu();
            GoToXY::coords(29,1);
            cout << "ELIMINAR A UN CLIENTE";
            GoToXY::coords(2,7);
            cout << "Ingrese la hora de atencíon del cliente a eliminar (HH:MM:SS): ";
            getline(cin,str,':');
            time.setHour(atoi(str.c_str()));
            getline(cin,str,':');
            time.setMinute(atoi(str.c_str()));
            getline(cin,str);
            time.setSecond(atoi(str.c_str()));
            client.setAttentionHour(time);
            pos = clientListPtr->findData(client);
            if (pos != nullptr){
                client = clientListPtr->retrieve(pos);
                GoToXY::coords(2,8);
                cout << "Cliente encontrado: " << client.toString();
            }
            else{
                GoToXY::coords(2,8);
                cout << "No existe ningún cliente con esa hora de llamada.";
                backToMenu();
                return;
            }
            GoToXY::coords(21,10);
            cout << "¿SEGURO QUE QUIERE ELIMINAR A ESTE CLIENTE?";
            GoToXY::coords(30,11);
            cout << "[S] = Si   [N] = No";
            GoToXY::coords(35,13);
            cout << "Respuesta: ";
            cin >> answer;
            answer = toupper(answer);

            if (answer == 'S'){
                clientListPtr->deleteData(pos);
                GoToXY::coords(26,15);
                cout << "Eliminando al cliente";
                for (int i=0;i<3;i++){
                    Sleep(200);
                    cout << " . ";
                }
            }
            else{
                GoToXY::coords(26,15);
                cout << "No se eliminó el cliente...";
            }
            backToMenu();
            break;
        case 2:
            GoToXY::screenMenu();
            GoToXY::coords(27,1);
            cout << "ELIMINAR TODOS LOS CLIENTES";
            GoToXY::coords(21,7);
            cout << "¿SEGURO QUE QUIERE ELIMINAR A TODOS LOS CLIENTES?";
            GoToXY::coords(30,11);
            cout << "[S] = Si   [N] = No";
            GoToXY::coords(35,13);
            cout << "Respuesta: ";
            cin >> answer;
            answer = toupper(answer);

            if (answer == 'S'){
                clientListPtr->deleteAll();
                GoToXY::coords(26,15);
                cout << "Eliminando a todos los clientes";
                for (int i=0;i<3;i++){
                    Sleep(200);
                    cout << " . ";
                }
            }
            else{
                GoToXY::coords(26,15);
                cout << "Se han conservado a todos los clientes";
            }
            backToMenu();
            break;
        case 3:
            returnMenu = true;
            break;
        default:
            GoToXY::coords(20,12);
            cout << "¡OPCIÓN INVÁLIDA! INTENTELO DE NUEVO";
        }
        }while(!returnMenu);
    }

ClientMenu::ClientMenu(ClientList* p) : clientListPtr(p) {
    mainMenu();
    }
