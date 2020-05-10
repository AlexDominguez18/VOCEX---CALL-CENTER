#ifndef CONSOLAGOTOXY_H_INCLUDED
#define CONSOLAGOTOXY_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <vector>

#include "time.h"

using namespace std;

class GoToXY {
public:
    static void coords(int x, int y) { // MEDIDA de ANCHO = 80, Alto = 25;
        HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X = x;
        dwPos.Y = y;
        SetConsoleCursorPosition(hcon, dwPos);
    }

    static void screenMenu() {
        system("cls");
        // ESQUINAS //
        GoToXY::coords(0,0);
        cout<<"*";
        GoToXY::coords(0,24);
        cout<<"*";
        GoToXY::coords(79,0);
        cout<<"*";
        GoToXY::coords(79,24);
        cout<<"*";

        // A a B //
        for(int i=1; i<79; i++) {
            GoToXY::coords(i,0);
            cout<<"-";
            }
        for(int i=1; i<79; i++) {
            GoToXY::coords(i,3);
            cout<<"-";
            }
        // TITULO //
        GoToXY::coords(2,2);
        cout<<"VOCEX";

        // B a D //
        for(int l=1; l<24; l++) {
            GoToXY::coords(79,l);
            cout<<"|";
            }
        // C a D //
        for(int j=1; j<79; j++) {
            GoToXY::coords(j,24);
            cout<<"-";
            }
        for(int j=1; j<79; j++) {
            GoToXY::coords(j,22);
            cout<<"-";
            }
        // A a C //

        for(int k=1; k<24; k++) {
            GoToXY::coords(0,k);
            cout<<"|";
            }

        // FOOTER //
        GoToXY::coords(2,1);
        cout<<"";

        GoToXY::coords(59,23);
        cout<<"VOCEX - Call now!";


        /* fecha/hora actual basado en el sistema actual */
        time_t now = time(0);

        /* Objeto de una estructura tm con fecha/hora local */
        tm* time = localtime(&now);

        vector<string> mes;
        mes.push_back("Enero");
        mes.push_back("Febrero");
        mes.push_back("Marzo");
        mes.push_back("Abril");
        mes.push_back("Mayo");
        mes.push_back("Junio");
        mes.push_back("Julio");
        mes.push_back("Agosto");
        mes.push_back("Septiembre");
        mes.push_back("Octubre");
        mes.push_back("Noviembre");
        mes.push_back("Diciembre");

        int year = 1900 + time->tm_year;

        //Formato=DIA, NUMERO de MES del AÑO
        GoToXY::coords(65,1);
        cout << time->tm_mday << "/" << mes[time->tm_mon] << "/" << year << endl;
        // HORA //
        Time t;
        GoToXY::coords(70,2);
        cout << t.toString() << endl;
    }

    static void loadBar(){
        Sleep(100);SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN);
        for (int i = 1;i < 78;i++){
                Sleep(50);
                cout << "=";
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    }
};

#endif // CONSOLAGOTOXY_H_INCLUDED
