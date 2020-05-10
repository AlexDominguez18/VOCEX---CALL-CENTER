#ifndef CLIENTMENU_H_INCLUDED
#define CLIENTMENU_H_INCLUDED

#include "clientlist.h"
#include "client.h"
#include "clientnode.h"
#include "clientmenu.h"
#include "listexception.h"
#include "consolaGotoxy.h"

class ClientMenu {
private:
    ClientList* clientListPtr;

    void mainMenu();
    void addClient();
    void modifyClient();
    void showClientList();
    void deleteClient();
    void backToMenu();
    void enterToContinue();

public:
    ClientMenu(ClientList*);
};

#endif // CLIENTMENU_H_INCLUDED
