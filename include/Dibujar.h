#ifndef DIBUJAR_H
#define DIBUJAR_H

#include <string>
#include <iostream>
#include <string>
#include <winbgim.h>
#include <stdlib.h>

#include  "LinkedList.h"
//#include "Instrucciones.h"

#define PI 3.14159265358979
#define X_WINDOW 600
#define Y_WINDOW 400

using namespace std;

class Dibujar
{
private:
    int avance;
    int grados;
    int gradosAumentar;
    int x;
    int y;
    int anchoDeLinea;
    int lapiz;
    int color;
    string instruccion;

    //string titulo;
    LinkedList<string> ListaInstrucciones;

public:

    Dibujar()
    {
        initwindow (X_WINDOW,Y_WINDOW);
        avance = 0;
        grados = 0;
        gradosAumentar = 0;
        int x = X_WINDOW/2;
        int y = Y_WINDOW/2;
        anchoDeLinea = 1;
        instruccion = "";
    }

    void dibujarLinea(){
        int nuevaDistanciaX = avance * cos(grados*PI/180);
        int nuevaDistanciaY = avance * sin(grados*PI/180);
        int x2 = x +  nuevaDistanciaX;
        int y2 = y +  nuevaDistanciaY;
        line (x, y, x2, y2);
        x = x2;
        y = y2;
        bar(x2-5, y2-5, x2+5, y2+5);

    }


    void dibujarLista()
    {
        //initwindow (X_WINDOW,Y_WINDOW);
        x = X_WINDOW/2;
        y = Y_WINDOW/2;
        cleardevice();
        cout << "-+--+-+--" << endl;
        if(ListaInstrucciones.getSize() == 0)
            cout << "Lista vacia" << endl;
        else
            for(ListaInstrucciones.goToStart();ListaInstrucciones.getPos() < ListaInstrucciones.getSize();ListaInstrucciones.next())
            {
                string palabra = instruccion = ListaInstrucciones.getElement();
                size_t pos = 0;
                string  delimitador = " ";
                string part1;
                string part2;
                string token;

                while ((pos = instruccion.find(delimitador)) != string::npos) {
                    token = instruccion.substr(0, pos);
                    part1 = token ;
                    instruccion.erase(0, pos + delimitador.length());
                }
                part2=  instruccion;
                cout << "-linea-1---" << part1<< endl;
                cout << "-linea-2---" << part2<< endl;

                    if(part1.compare("linea")==0)
                    {   cout << "-entro a linea-" << endl;
                        avance =atoi(part2.c_str());
                        dibujarLinea();
                    }else
                    if(part1.compare("der")==0)
                        grados +=  atoi(part2.c_str());
                    else
                    if(part1.compare("izq")==0)
                        grados -=atoi(part2.c_str());

                    else
                    if(part1.compare("grosor")==0)
                        anchoDeLinea = atoi(part2.c_str());
                    else
                    if(part1.compare("color")==0)
                        color = atoi(part2.c_str());
                    else
                    if(part1.compare("lapiz")==0)
                        lapiz = atoi(part2.c_str());
                    else
                    if(part1.compare("pos")==0) // x,y
                    {
                        palabra = atoi(part2.c_str());
                        string token;
                        string  delimitador = ",";
                        string part1;
                        string part2;
                        while ((pos = palabra.find(delimitador)) != string::npos)
                        {
                            token=   palabra.substr(0, pos);
                            x =  atoi(palabra.c_str());
                            palabra.erase(0, pos + delimitador.length());
                        }
                        y =  atoi(token.c_str());
                    }
            }
            delay(100);
            //getch();
        }



    void leerEntrada(){

        bool lectura = true;

        while (lectura){
            cout << "Digite las instrucciones"<<endl;
            getline(cin,instruccion);
            cin.get();
            //getline(0,instruccion);

            cout << "fija--> "<<instruccion<< "<---"<< endl;
            if( instruccion.compare("salir")== 0)
            {
                 lectura = false;
                 closegraph();
            }
            else
            {
                ListaInstrucciones.append(instruccion);
                dibujarLista();
            }
        }
        closegraph();
    }


};
 /*


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

#endif // DIBUJAR_H

