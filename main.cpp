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
//int main(int argc, char **argv)


    /*string a1 = "hola";
    string a2 = "hola";
    string a3 = "hoala";
    if(strcmp(a1.c_str(),a2.c_str()) == 0)
        cout << "son iguales ";
    else
        cout << "NO son iguales ";
    if(strcmp(string("hola").c_str(),a2.c_str()) == 0)
        cout << "2son iguales ";
    else
        cout << "2NO son iguales ";*/
    //if(strcmp(a1,a2))


  //    LinkedList<Array> ListaInstrucciones;
    //  ListaInstrucciones.append(["palabra","palabra"]);
    //  ListaInstrucciones.append(["palabra2","Palabra"]);


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
   // Dibujar dibujo;
    //dibujo.leerEntrada();
//

/*


        string linea[2];
        string delimitardor = "-";
        size_t pos = 0;
        string token;
        string a,b;

    string instruccion;// = "hola mundo";
    cout << "Digita la inst" << endl;
    cin >> instruccion;
        while ((pos = instruccion.find(delimitardor)) != string::npos) {
            token = instruccion.substr(0, pos);
            a = token ;
            instruccion.erase(0, pos + delimitardor.length());
        }
        b =  instruccion;

        cout << a << " -- " << b << endl;
/*


    int avance = 100;
    int x = 250;
    int y = 250;
    int grados = 0;

    int nuevaDistanciaX = avance * cos(grados*PI/180);
    int nuevaDistanciaY = avance * sin(grados*PI/180);
    int x2 = x +  nuevaDistanciaX;
    int y2 = y +  nuevaDistanciaY;


    line (x, y, x2, y2);

    initwindow (600,400);
    setcolor(15);
    setlinestyle(1, 0, 1)   ;
    line (x, y, x2, y2);

    //void bar(int izq, int arriba, int derecha, int abajo);
    //circle(2,2,2,2);
    bar(x2-5, y2-5, x2+5, y2+5);
    getch();

    closegraph();*/

