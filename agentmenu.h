#ifndef AGENTMENU_H_INCLUDED
#define AGENTMENU_H_INCLUDED

#include <iostream>
#include <clocale>
#include <regex>
#include "agentlist.h"
#include "agent.h"
#include "agentnode.h"
#include "name.h"
#include "schedule.h"
#include "time.h"
#include "clientmenu.h"

class AgentMenu {
private:
    AgentList* agentListPtr;

    void logoScreen();
    void enterToContinue();
    void mainMenu();
    void addAgent();
    void modifyAgent();
    void consultAgent();
    void showAgentList();
    void deleteAgent();
    void saveChanges();
    void loadData();
    void sortAgentList();
public:
    AgentMenu(AgentList*);
};

#endif // AGENTMENU_H_INCLUDED
