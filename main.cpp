#include <iostream>
#include <winbgim.h>
#include <string.h>
//#include <string>
#include <cmath>

#include  "LinkedList.h"
#include "Instrucciones.h"
#include "Turtle.h"
/*
#define PI 3.14159265358979
#define X_WINDOW 600
#define Y_WINDOW 400*/
//#include <array>


using namespace std;
int main()
{
    system("cls");
    system("Title Turtle Graphics - ITCR - Estructura de Datos");
    system("color a");

    // color a;
    Turtle *turtle = new Turtle();

    bool lectura = true;
    cout << endl;
    cout << "Digite los comandos malignos para la invocacion de los demonios. "<<endl;
    cout << "Reinicie su equipo despues de cada comando para el correcto funcionamiento. "<<endl << endl;
    while (lectura){
        cout << "LUser@winBug~$ ";
        string instruccion = "";
        getline(cin,instruccion);
        //cout << endl;
        if( instruccion.compare("exit")== 0)
        {
             lectura = false;
             closegraph();
             return 0;
        }
        turtle->leerInstruccion(instruccion);
    }

    return 0;
}

