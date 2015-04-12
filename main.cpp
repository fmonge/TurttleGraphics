#include <iostream>
#include <winbgim.h>
#include <cmath>

#include  "LinkedList.h"
#include "Instrucciones.h"
#include "Dibujar.h"
/*
#define PI 3.14159265358979
#define X_WINDOW 600
#define Y_WINDOW 400*/


using namespace std;

int main()
{


   Dibujar dibujo;
    dibujo.leerEntrada();





        string linea[2];
        string delimitardor = " ";
        size_t pos = 0;
        string token;

string instruccion = "hola mundo";
        while ((pos = instruccion.find(delimitardor)) != string::npos) {
            token = instruccion.substr(0, pos);
            linea [0] = token ;
            instruccion.erase(0, pos + delimitardor.length());
        }
        linea[1] =  instruccion;

        cout << linea[0] << " -- " << linea[1] << endl;
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

    return 0;
}
