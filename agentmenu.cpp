#include <windows.h>

#include "agentmenu.h"
#include "name.h"

using namespace std;


AgentMenu::AgentMenu(AgentList* p): agentListPtr(p){
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    logoScreen();
    mainMenu();
    logoScreen();
}

void AgentMenu::logoScreen(){
    GoToXY::screenMenu();
    GoToXY::coords(2,5);Sleep(100);SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
    cout<< "__     __ ___    ____  _____ __  __";
    GoToXY::coords(2,6);Sleep(100);SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
    cout<< "\\ \\   / // _ \\  / ___|| ____|\\ \\/ /";
    GoToXY::coords(2,7);Sleep(100);SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
    cout<< " \\ \\ / /| | | || |    |  _|   \\  / ";
    GoToXY::coords(2,8);Sleep(100);SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
    cout<< "  \\ V / | |_| || |___ | |___  /  \\ ";
    GoToXY::coords(2,9);Sleep(100);SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
    cout<< "   \\_/   \\___/  \\____||_____|/_/\\_\\";
    GoToXY::coords(2,10);Sleep(100);SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
    cout<<"   ____     _     _      _        ____  _____  _   _  _____  _____  ____   _ ";
    GoToXY::coords(2,11);Sleep(100);SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    cout<<"  / ___|   / \\   | |    | |      / ___|| ____|| \\ | ||_   _|| ____||  _ \\ | |";
    GoToXY::coords(2,12);Sleep(100);SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
    cout<<" | |      / _ \\  | |    | |     | |    |  _|  |  \\| |  | |  |  _|  | |_) || |";
    GoToXY::coords(2,13);Sleep(100);SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<" | |___  / ___ \\ | |___ | |___  | |___ | |___ | |\\  |  | |  | |___ |  _ < |_|";
    GoToXY::coords(2,14);Sleep(100);SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"  \\____|/_/   \\_\\|_____||_____|  \\____||_____||_| \\_|  |_|  |_____||_| \\_\\(_)";
    GoToXY::coords(2,25);Sleep(100);SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    cout<<"                                                                             ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    GoToXY::coords(1,17);
    GoToXY::loadBar();
    GoToXY::coords(1,23);
    enterToContinue();
}

void AgentMenu::mainMenu(){
    int option;
    bool returnMenu = false;
    string op;

    setlocale(LC_ALL,"spanish_mexico");
    do{
        GoToXY::screenMenu();
        GoToXY::coords(30,2);
        cout << "MENÚ PRINCIPAL";

        GoToXY::coords(4,7);
        cout << "1. AGREGAR UN AGENTE.";
        GoToXY::coords(4,8);
        cout << "2. MODIFICAR INFORMACIÓN DE UN AGENTE.";
        GoToXY::coords(4,9);
        cout << "3. CONSULTAR INFORMACIÓN DE UN AGENTE.";
        GoToXY::coords(4,10);
        cout << "4. MOSTRAR LISTA DE AGENTES.";
        GoToXY::coords(4,11);
        cout << "5. ORDENAR AGENTES.";
        GoToXY::coords(4,12);
        cout << "6. ELIMINAR AGENTE(S).";
        GoToXY::coords(4,13);
        cout << "7. GUARDAR DATOS.";
        GoToXY::coords(4,14);
        cout << "8. CARGAR DATOS.";
        GoToXY::coords(4,15);
        cout << "9. SALIR DEL PROGRAMA";
        GoToXY::coords(2,17);
        cout << "OPCIÓN: ";
        getline(cin,op);
        if (regex_match(op,regex("[1-9]"))){
            option = atoi(op.c_str());
            }
        else{
            option = 0;
            }
        switch(option){
        case 1:
            Sleep(1000);
            addAgent();
            break;
        case 2:
            Sleep(1000);
            modifyAgent();
            break;
        case 3:
            Sleep(1000);
            consultAgent();
            break;
        case 4:
            Sleep(1000);
            showAgentList();
            break;
        case 5:
            Sleep(1000);
            sortAgentList();
            break;
        case 6:
            Sleep(1000);
            deleteAgent();
            break;
        case 7:
            Sleep(1000);
            saveChanges();
            break;
        case 8:
            Sleep(1000);
            loadData();
            break;
        case 9:
            returnMenu = true;
            break;
        default:
            GoToXY::coords(20,20);
            cout << "¡OPCIÓN INVÁLIDA! INTENTELO DE NUEVO";
            Sleep(1000);
            }
        }while(!returnMenu);
    }

void AgentMenu::enterToContinue(){
    cout << "Presione ENTER para continuar...";
    cin.get();
    }

void AgentMenu::addAgent(){
    Agent a;
    char op;
    int option;
    unsigned int empNum,extNum;
    Name name;
    string str;
    Schedule sh;
    Time time;
    AgentNode* pos;

    system("cls");
    GoToXY::screenMenu();
    GoToXY::coords(32,1);
    cout << "AGREGAR A UN AGENTE";
    GoToXY::coords(10,5);
    cout << "Número de empleado: ";
    cin >> empNum;
    cin.get();
    a.setEmpNum(empNum);

    pos = agentListPtr->findData(a);
    if (pos != nullptr){
        GoToXY::coords(10,6);
        cout << "Ya existe un agente con ese número de empleado." << endl;
        GoToXY::coords(10,7);
        enterToContinue();
        return;
        }

    GoToXY::coords(10,6);
    cout << "Nombre(s): ";
    getline(cin,str);
    name.setFirst(str);

    GoToXY::coords(10,7);
    cout << "Apellido(s): ";
    getline(cin,str);
    name.setLast(str);
    a.setName(name);

    GoToXY::coords(50,5);
    cout << "Especialidades:";
   do{
        GoToXY::coords(50,6);
        cout << "1. SERVIDORES.";
        GoToXY::coords(50,7);
        cout << "2. DE ESCRITORIO.";
        GoToXY::coords(50,8);
        cout << "3. PORTATILES.";
        GoToXY::coords(50,9);
        cout << "4. LINUX.";
        GoToXY::coords(50,10);
        cout << "5. IMPRESORAS.";
        GoToXY::coords(50,11);
        cout << "6. REDES";
        GoToXY::coords(10,10);
        cout << "Especialidad: ";
        getline(cin,str);
        if (regex_match(str,regex("[1-6]"))){
            option = atoi(str.c_str());
        }
        else{
            option = 0;
        }
        switch(option){
        case 1: a.setSpeciality("Servidores");   break;
        case 2: a.setSpeciality("De escritorio");break;
        case 3: a.setSpeciality("Portatiles");   break;
        case 4: a.setSpeciality("Linux");        break;
        case 5: a.setSpeciality("Impresoras");   break;
        case 6: a.setSpeciality("Redes");        break;
        default: a.setSpeciality("No asignada");
        }
    }while(option==0);

    GoToXY::coords(10,11);
    cout << "Número de extensión: ";
    cin >> extNum;
    a.setExtNum(extNum);

    GoToXY::coords(10,12);
    cout << "Hora de entrada (HH:MM:SS): ";
    getline(cin,str,':');
    time.setHour(atoi(str.c_str()));
    getline(cin,str,':');
    time.setMinute(atoi(str.c_str()));
    getline(cin,str);
    time.setSecond(atoi(str.c_str()));
    sh.setStart(time);
    GoToXY::coords(10,13);
    cout << "Hora de salida (HH:MM:SS): ";
    getline(cin,str,':');
    time.setHour(atoi(str.c_str()));
    getline(cin,str,':');
    time.setMinute(atoi(str.c_str()));
    getline(cin,str);
    time.setSecond(atoi(str.c_str()));
    sh.setEnd(time);
    a.setSchedule(sh);

    GoToXY::coords(10,14);
    cout << "Horas extras (HH:MM:SS): ";
    getline(cin,str,':');
    time.setHour(atoi(str.c_str()));
    getline(cin,str,':');
    time.setMinute(atoi(str.c_str()));
    getline(cin,str);
    time.setSecond(atoi(str.c_str()));
    a.setExtHours(time);

    do{
        GoToXY::coords(10,16);
        cout << "¿Quiere agregarle a este agente una lista de clientes?";
        GoToXY::coords(10,17);
        cout << "[S] Si     [N] No";
        GoToXY::coords(10,18);
        cout << "Respuesta: ";
        cin >> op;
    }while(toupper(op) != 'S' and toupper(op) != 'N');

    if (toupper(op) == 'S'){
        new ClientMenu(&a.getClientList());
    }

    try{
        agentListPtr->insertData(agentListPtr->getLastPos(),a);
        }
    catch(ListException& ex){
        GoToXY::coords(10,19);
        cout << "Error al tratar de agregar a " << name.toString() << " a la lista de agentes.";
        GoToXY::coords(10,20);
        enterToContinue();
        return;
        }

    GoToXY::coords(10,19);
    cout << "¡Se ha insertado al agente exitosamente!";
    GoToXY::coords(10,20);
    enterToContinue();

    }


void AgentMenu::modifyAgent(){
    Agent a;
    AgentNode* pos;
    Name name;
    Schedule schedule;
    Time time;
    bool returnMenu = false;
    int num,option;
    string str;

    system("cls");
    GoToXY::screenMenu();
    GoToXY::coords(24,1);
    cout << "MODIFICAR INFORMACIÓN DEL AGENTE";
    GoToXY::coords(2,4);
    cout << "Ingrese el numero de empleado del agente a quien desea hacerle cambios: ";
    GoToXY::coords(2,5);
    cout << "Número de empleado: ";
    cin >> num;
    cin.get();
    a.setEmpNum(num);

    pos = agentListPtr->findData(a);

    if (pos == nullptr){
        GoToXY::coords(2,7);
        cout << "No se ha encontrado a ningún agente con ese número de empleado.";
        GoToXY::coords(2,9);
        cout << "Le recomiendo consultar la lista de los agentes.";
        GoToXY::coords(2,11);
        enterToContinue();
        return;
    }

    a = pos->getData();

    do{
        system("cls");
        GoToXY::screenMenu();
        GoToXY::coords(24,1);
        cout << "MODIFICAR INFORMACIÓN DEL AGENTE";
        GoToXY::coords(29,7);
        cout << "¿QUÉ DESEA MODIFICAR?";
        GoToXY::coords(2,8);
        cout << "1. NÚMERO DE EMPLEADO.";
        GoToXY::coords(2,9);
        cout << "2. NOMBRE DEL EMPLEADO.";
        GoToXY::coords(2,10);
        cout << "3. NÚMERO DE EXTENSIÓN.";
        GoToXY::coords(2,11);
        cout << "4. ESPECIALIDAD.";
        GoToXY::coords(2,12);
        cout << "5. HORARIO DE TRABAJO.";
        GoToXY::coords(2,13);
        cout << "6. HORAS EXTRAS.";
        GoToXY::coords(2,14);
        cout << "7. CLIENTES ATENDIDOS.";
        GoToXY::coords(2,15);
        cout << "8. REGRESAR AL MENÚ PRINCIPAL.";
        GoToXY::coords(2,17);
        cout << "OPCIÓN: ";
        getline(cin,str);
        if (regex_match(str,regex("[1-8]"))){
            option = atoi(str.c_str());
        }
        else{
            option = 0;
        }
        switch(option){
        case 1:
            system("cls");
            GoToXY::screenMenu();
            GoToXY::coords(24,1);
            cout << "MODIFICAR INFORMACIÓN DEL AGENTE";
            GoToXY::coords(2,5);
            cout << "Ingrese el nuevo número del agente:";
            GoToXY::coords(2,7);
            cout << "***Número Previo = " << a.getEmpNum();
            GoToXY::coords(2,9);
            cout << "-Nuevo número: ";
            cin >> num;
            a.setEmpNum(num);
            break;
        case 2:
            system("cls");
            GoToXY::screenMenu();
            GoToXY::coords(24,1);
            cout << "MODIFICAR INFORMACIÓN DEL AGENTE";
            GoToXY::coords(2,5);
            cout << "Ingrese el nuevo nombre del agente:";
            GoToXY::coords(2,7);
            cout << "***Nombre Previo = " << a.getName().toUpper();
            GoToXY::coords(2,9);
            cout << "-Nombre(s): ";
            getline(cin,str);
            name.setFirst(str);
            GoToXY::coords(2,10);
            cout << "-Apellido(s): ";
            getline(cin,str);
            name.setLast(str);
            a.setName(name);
            break;
        case 3:
            system("cls");
            GoToXY::screenMenu();
            GoToXY::coords(24,1);
            cout << "MODIFICAR INFORMACIÓN DEL AGENTE";
            GoToXY::coords(2,5);
            cout << "Ingrese el nuevo número de extensión del agente:";
            GoToXY::coords(2,7);
            cout << "***Numero de extensión previo = " << a.getExtNum();
            GoToXY::coords(2,9);
            cout << "-Nuevo número de extensión: ";
            cin >> num;
            a.setExtNum(num);
            break;
        case 4:
            system("cls");
            GoToXY::screenMenu();
            GoToXY::coords(24,1);
            cout << "MODIFICAR INFORMACIÓN DEL AGENTE";
            GoToXY::coords(2,5);
            cout << "Ingrese la nueva especialidad del agente:";
            GoToXY::coords(2,7);
            cout << "***Especialidad previa = " << a.getSpeciality();
            do{
                GoToXY::coords(2,9);
                cout << "1. SERVIDORES.";
                GoToXY::coords(2,10);
                cout << "2. DE ESCRITORIO.";
                GoToXY::coords(2,11);
                cout << "3. PORTATILES.";
                GoToXY::coords(2,12);
                cout << "4. LINUX.";
                GoToXY::coords(2,13);
                cout << "5. IMPRESORAS.";
                GoToXY::coords(2,14);
                cout << "6. REDES";
                GoToXY::coords(2,16);
                cout << "OPCIÓN: ";
                getline(cin,str);
                if (regex_match(str,regex("[1-6]"))){
                    option = atoi(str.c_str());
                }
                else{
                    option = 0;
                }
                switch(option){
                case 1: a.setSpeciality("Servidores");   break;
                case 2: a.setSpeciality("De escritorio");break;
                case 3: a.setSpeciality("Portatiles");   break;
                case 4: a.setSpeciality("Linux");        break;
                case 5: a.setSpeciality("Impresoras");   break;
                case 6: a.setSpeciality("Redes");        break;
                default: a.setSpeciality("No asignada");
                }
            }while(option==0);
            break;
        case 5:
            system("cls");
            GoToXY::screenMenu();
            GoToXY::coords(24,1);
            cout << "MODIFICAR INFORMACIÓN DEL AGENTE";
            GoToXY::coords(2,5);
            cout << "Ingrese el nuevo horario del agente:";
            GoToXY::coords(2,7);
            cout << "***Horario previo = " << a.getShedule().getStart().toString()
                << " a " << a.getShedule().getEnd().toString();
            GoToXY::coords(2,9);
            cout << "-Nueva hora de entrada (HH:MM:SS): ";
            getline(cin,str,':');
            time.setHour(atoi(str.c_str()));
            getline(cin,str,':');
            time.setMinute(atoi(str.c_str()));
            getline(cin,str);
            time.setSecond(atoi(str.c_str()));
            schedule.setStart(time);
            GoToXY::coords(2,10);
            cout << "-Nueva hora de salida (HH:MM:SS): ";
            getline(cin,str,':');
            time.setHour(atoi(str.c_str()));
            getline(cin,str,':');
            time.setMinute(atoi(str.c_str()));
            getline(cin,str);
            time.setSecond(atoi(str.c_str()));
            schedule.setEnd(time);
            a.setSchedule(schedule);
            break;
        case 6:
            system("cls");
            GoToXY::screenMenu();
            GoToXY::coords(24,1);
            cout << "MODIFICAR INFORMACIÓN DEL AGENTE";
            GoToXY::coords(2,5);
            cout << "Ingrese el tiempo extra trabajado por el agente:";
            GoToXY::coords(2,7);
            cout << "***Horas extras previas = " << a.getExtHours().toString();
            GoToXY::coords(2,9);
            cout << "-Nuevo tiempo extra (HH:MM:SS): ";
            getline(cin,str,':');
            time.setHour(atoi(str.c_str()));
            getline(cin,str,':');
            time.setMinute(atoi(str.c_str()));
            getline(cin,str);
            time.setSecond(atoi(str.c_str()));
            a.setExtHours(time);
            break;
        case 7:
            new ClientMenu(&a.getClientList());
            break;
        case 8:
            returnMenu = true;
            break;
        default:
            GoToXY::coords(20,20);
            cout << "¡OPCIÓN INVÁLIDA! INTENTELO DE NUEVO";
            Sleep(1000);
        }
        cout << "| ";
        enterToContinue();
        pos->setData(a);
    }while (!returnMenu);

    }

void AgentMenu::consultAgent(){
    string str;
    Name name;
    Agent a;
    AgentNode* pos;
    AgentNode* aux(agentListPtr->getFirstPos());

    GoToXY::screenMenu();
    GoToXY::coords(25,1);
    cout << "CONSULTAR INFORMACIÓN DE AGENTE";
    GoToXY::coords(2,5);
    cout << "Ingrese el nombre del agente por buscar:";
    GoToXY::coords(2,6);
    cout << "Nombre(s): ";
    getline(cin,str);
    name.setFirst(str);
    GoToXY::coords(2,7);
    cout << "Apellido(s): ";
    getline(cin,str);
    name.setLast(str);
    a.setName(name);

    pos = nullptr;
    while (aux!=agentListPtr->getPrevPos(agentListPtr->getFirstPos())){
        if (aux->getData().getName() == name){
            pos = aux;
            a = agentListPtr->retrieve(pos);
            cout << endl << "| Agente encontrado: " << a.getName().toUpper() << endl;
            cout << "\t-No. Empleado: " << a.getEmpNum() << endl;
            cout << "\t-No. Extension: " << a.getExtNum() << endl;
            cout << "\t-Especialidad:  " << a.getSpeciality() << endl;
            cout << "\t-Horario: " << a.getShedule().getStart().toString() << " a ";
            cout << a.getShedule().getEnd().toString() << endl;
            cout << "\t-Horas extras: " << a.getExtHours().toString() << endl;
        }
        aux = aux->getNext();
    }

    if (pos == nullptr){
        GoToXY::coords(2,9);
        cout << "No existe ingún agente con ese nombre.";
        GoToXY::coords(2,11);
        cout << "Le recomiendo consultar la lista de agentes.";
        GoToXY::coords(2,13);
        enterToContinue();
        return;
    }
    cout <<  endl << "| ";
    enterToContinue();
    }

void AgentMenu::showAgentList(){
    char op;

    system("cls");
    GoToXY::screenMenu();
    GoToXY::coords(32,1);
    cout << "LISTA DE AGENTES";
    do{
        GoToXY::coords(16,5);
        cout << "¿Quiere mostrar a los agentes con la lista de clientes?";
        GoToXY::coords(24,7);
        cout << "[S] Si     [N] No";
        GoToXY::coords(10,9);
        cout << "Respuesta: ";
        cin >> op;
    }while(toupper(op) != 'S' and toupper(op) != 'N');
    system("cls");
    GoToXY::screenMenu();
    GoToXY::coords(32,1);
    cout << "LISTA DE AGENTES";
    GoToXY::coords(1,4);
    cout << "#Emp.| ";
    GoToXY::coords(14,4);
    cout << "Nombre";
    GoToXY::coords(39,4);
    cout << "| Especialidad |";
    GoToXY::coords(55,4);
    cout << "No.Ext";
    GoToXY::coords(61,4);
    cout << "|Entrada |";
    GoToXY::coords(71,4);
    cout << "Salida " << endl;
    cout << "|";
    for (int i =1;i<79;i++){
        cout << "-";
    }
    cout << endl << agentListPtr->toString(toupper(op) == 'S');
    cin.get();
    cin.get();

    }

void AgentMenu::deleteAgent(){
    Name name;
    AgentNode* pos(nullptr);
    AgentNode* aux(agentListPtr->getFirstPos());
    string str;
    int option;
    char answer;

    system("cls");
    GoToXY::screenMenu();
    GoToXY::coords(33,1);
    cout << "ELIMINAR AGENTE";
    GoToXY::coords(32,5);
    cout << "¿QUÉ DESEA HACER?";
    GoToXY::coords(2,7);
    cout << "1. ELIMINAR A UN AGENTE.";
    GoToXY::coords(2,8);
    cout << "2. ELIMINAR A TODOS LOS AGENTES.";
    GoToXY::coords(2,9);
    cout << "3. REGRESAR AL MENÚ PRINCIPAL.";
    GoToXY::coords(2,11);
    cout << "OPCIÓN: ";
    getline(cin,str);
    if (regex_match(str,regex("[1-2]"))){
        option = atoi(str.c_str());
        }
    else{
        option = 0;
        }
    switch(option){
    case 1:
        system("cls");
        GoToXY::screenMenu();
        GoToXY::coords(33,1);
        cout << "ELIMINAR AGENTE";
        GoToXY::coords(2,5);
        cout << "Ingrese el nombre del agente a eliminar:";
        GoToXY::coords(2,7);
        cout << "Nombre(s): ";
        getline(cin,str);
        name.setFirst(str);
        GoToXY::coords(2,8);
        cout << "Apellido(s): ";
        getline(cin,str);
        name.setLast(str);

        while (aux!=agentListPtr->getPrevPos(agentListPtr->getFirstPos())){
            if (aux->getData().getName() == name){
                pos = aux;
                break;
            }
            aux = aux->getNext();
        }
        if (pos == nullptr){
            GoToXY::coords(2,10);
            cout << "No existe ningún agente con ese nombre";
            GoToXY::coords(2,11);
            cout << "Le recomiendo consultar la lista de agentes.";
            GoToXY::coords(2,13);
            enterToContinue();
            return;
        }
        GoToXY::coords(2,10);
        cout << "Agente a eliminar: " << pos->getData().getName().toString();
        GoToXY::coords(22,12);
        cout << "¿SEGURO DE QUÉ DESEA ELIMINAR A ESTE AGENTE?";
        GoToXY::coords(33,13);
        cout << "[S]Si    [N]No";
        GoToXY::coords(22,15);
        cout << "RESPUESTA: ";
        cin >> answer;
        if (toupper(answer) == 'S'){
            agentListPtr->deleteData(pos);
            GoToXY::coords(35,17);
            cout << "ELIMINANDO";
            GoToXY::coords(1,18);
            for (int i = 1;i < 79;i++){
                Sleep(100);
                cout << "#";
                }
            }
        else{
            GoToXY::coords(27,17);
            cout << "SE HA CONSERVADO AL AGENTE";
        }
        break;
    case 2:
        system("cls");
        GoToXY::screenMenu();
        GoToXY::coords(33,1);
        cout << "ELIMINAR AGENTE";
        GoToXY::coords(14,5);
        cout << "USTED ESTÁ A APUNTO DE ELIMINAR A TODOS LOS AGENTES";
        GoToXY::coords(22,7);
        cout << "¿SEGURO DE QUERER ELIMINAR A TODOS?";
        GoToXY::coords(33,8);
        cout << "[S]Si    [N]No";
        GoToXY::coords(17,10);
        cout << "RESPUESTA: ";
        cin >> answer;
        if (toupper(answer) == 'S'){
            agentListPtr->deleteAll();
            GoToXY::coords(25,12);
            cout << "ELIMINANDO A TODOS LOS AGENTES";
            GoToXY::coords(1,13);
            GoToXY::loadBar();
        }
        else{
            GoToXY::coords(22,12);
            cout << "SE HAN CONSERVADO A TODOS LOS AGENTES";
        }
        break;
    default:
        GoToXY::coords(20,20);
        cout << "¡OPCIÓN INVÁLIDA! INTENTELO DE NUEVO";
        Sleep(1000);
        }
    cout << endl << "| ";
    enterToContinue();
    }


void AgentMenu::saveChanges(){
    system("cls");

    GoToXY::screenMenu();
    GoToXY::coords(32,1);
    cout << "GUARDAR CAMBIOS";
    GoToXY::coords(19,5);
    cout << "GUARDANDO DATOS DEL AGENTE Y SUS CLIENTES";
    GoToXY::coords(31,6);
    cout << "ESPERE, POR FAVOR";
    GoToXY::coords(1,8);
    GoToXY::loadBar();

    try{
        agentListPtr->writeToDisk("lista_agentes.txt");
    } catch (ListException& ex){
        GoToXY::coords(2,10);
        cout << "Ocurrió un error: " << ex.what() << endl;
        GoToXY::coords(2,12);
        enterToContinue();
        return;
        }
    GoToXY::coords(21,10);
    cout << "SE HAN GUARDADO LOS DATOS EXITOSAMENTE";
    GoToXY::coords(2,12);
    enterToContinue();
    }

void AgentMenu::loadData(){
    system("cls");

    GoToXY::screenMenu();
    GoToXY::coords(34,1);
    cout << "CARGAR DATOS";
    GoToXY::coords(23,5);
    cout << "CARGANDO DATOS, ESTO PUEDE TARDAR";
    GoToXY::coords(31,6);
    cout << "ESPERE, POR FAVOR";

    try{
        agentListPtr->readFromDisk("lista_agentes.txt");
    }catch (ListException& ex){
        GoToXY::coords(2,8);
        cout << "Ocurrió un error: " << endl << ex.what();
        GoToXY::coords(2,10);
        enterToContinue();
        return;
        }

    GoToXY::coords(1,7);
    GoToXY::loadBar();
    GoToXY::coords(26,8);
    cout << "DATOS CARGADOS EXITOSAMENTE";
    GoToXY::coords(2,10);
    enterToContinue();
    }

void AgentMenu::sortAgentList(){
    int option;
    string op;
    bool returnMenu = false;
    do{
        system("cls");
        GoToXY::screenMenu();
        GoToXY::coords(32,1);
        cout << "ORDENAR AGENTES";
        GoToXY::coords(27,5);
        cout << "¿CÓMO LOS QUIERE ORDENAR?";
        GoToXY::coords(2,7);
        cout << "1. ORDENAR POR NOMBRE";
        GoToXY::coords(2,8);
        cout << "2. ORDENAR POR ESPECIALIDAD.";
        GoToXY::coords(2,9);
        cout << "3. REGRESAR AL MENÚ PRINCIPAL.";
        GoToXY::coords(2,11);
        cout << "OPCIÓN: ";
        getline(cin,op);
        if (regex_match(op,regex("[1-3]"))){
            option = atoi(op.c_str());
            }
        else{
            option = 0;
            }
        switch(option){
        case 1:
            system("cls");
            GoToXY::screenMenu();
            GoToXY::coords(32,1);
            cout << "ORDENAR AGENTES";
            GoToXY::coords(21,7);
            cout << "ORDENANDO A LOS AGENTES POR SU NOMBRE";
            GoToXY::coords(17,8);
            cout << "SI EL PROCESO DEMORA, REINICIE SU COMPUTADORA" << endl << endl;
            agentListPtr->sortByName();
            GoToXY::coords(1,9);
            GoToXY::loadBar();
            break;
        case 2:
            system("cls");
            GoToXY::screenMenu();
            GoToXY::coords(32,1);
            cout << "ORDENAR AGENTES";
            GoToXY::coords(21,7);
            cout << "ORDENANDO A LOS AGENTES POR SU ESPECIALIDAD";
            GoToXY::coords(17,8);
            cout << "SI EL PROCESO DEMORA, REINICIE SU COMPUTADORA" << endl << endl;
            agentListPtr->sortBySpeciality();
            GoToXY::coords(1,9);
            GoToXY::loadBar();
            break;
        case 3:
            returnMenu = true;
            break;
        default:
            GoToXY::coords(19,14);
            cout << "¡OPCIÓN INVÁLIDA! INTENTELO DE NUEVO...";
            Sleep(1000);
            }
        GoToXY::coords(2,14);
        enterToContinue();
        }while(!returnMenu);
    }
