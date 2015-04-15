#ifndef TURTLE_H
#define TURTLE_H
#include <iostream>
#include <winbgim.h>
//#include <string.h>
#include <cmath>
#include  "LinkedList.h"
#include "Instrucciones.h"
#define PI 3.14159265358979
#define X_WINDOW 600
#define Y_WINDOW 400

using namespace std;
class Turtle{


public:
    Turtle(){

        initwindow (X_WINDOW,Y_WINDOW);
        avance = 0;
        grados = 0;
        lapiz = 1;
        color = 0;
        gradosAumentar = 0;
        x = X_WINDOW/2;
        y = Y_WINDOW/2;
        x2 = y2 = 0;

        anchoDeLinea = 1;
    }

    void leerInstruccion(string cmd)
    {
        gurdarComando(cmd);
        dibujarLista();
    }
private:

    int avance;
    int grados;
    int lapiz;
    int gradosAumentar;
    int x,x2;
    int y,y2;
    int anchoDeLinea;
    int color;
    static int numDeInstrucciones;
   //Instrucciones instruccion;

    LinkedList<Instrucciones> ListaInstrucciones;
    LinkedList<string> ListaDatos;

    Instrucciones toInstruction(string cmd){return  mapString[cmd];}

    int gurdarComando(string cmd)
    {
        size_t pos = 0;
        string delimitador = " ";
        string part1;
        string part2;
        string token;

        while ((pos = cmd.find(delimitador)) != string::npos) {
            token = cmd.substr(0, pos);
            part1 = string(token);
            cmd.erase(0, pos + delimitador.length());
        }
        part2=  string(cmd);
        Instrucciones nuevaInstruccion = toInstruction(part1);//*****

        ListaInstrucciones.append(nuevaInstruccion);//**********
        if(strcmp(string("").c_str(),part2.c_str()) == 0)
            ListaDatos.append("nextLine");
        else
            ListaDatos.append(part2);
        return 0;
    }

    void dibujarLinea(){
        //cout << "info:       -+DIBUJANDO+-- -> "  <<endl;
        //cout  <<"info:      " << avance<< endl;
        int nuevaDistanciaX = avance * cos(grados*PI/180);
        int nuevaDistanciaY = avance * sin(grados*PI/180);
        x2 = x +  nuevaDistanciaX;
        y2 = y +  nuevaDistanciaY;
        line (x, y, x2, y2);
        delay(10);
        x = x2;
        y = y2;
    }


    void dibujarLista()
    {
        x = X_WINDOW/2;
        y = Y_WINDOW/2;
       // cout << "---Recorrer-lista-----<" << "size< "  <<ListaInstrucciones.getSize()<<" >"<< endl;

        if(ListaInstrucciones.getSize() == 0)
            cout << "Lista vacia" << endl;
        else
        {
            cleardevice();
            grados = 0;
            ListaInstrucciones.goToStart();
            ListaDatos.goToStart();
            int size = ListaInstrucciones.getSize();
            int sizeList = ListaDatos.getSize();
            //cout << "el Tamaño de la lista es de: " << sizeList << endl;
            if(size != sizeList){
                cout <<     "Algo salio mal! D: listas nos compatibles" << endl;
            }else
            for(int i = 0; i!=sizeList; i++)
            {
                //cout << " Estoy en el  for con pos = " << i << endl;

                string valor = ListaDatos.getElement();
                Instrucciones instruccion = ListaInstrucciones.getElement();
                //cout << "   Instruccion actual: "<< int(instruccion) <<". Con el dato: " << valor <<endl;
               ejecutarInstruccion(ListaInstrucciones.getElement(),ListaDatos.getElement());
               ListaDatos.next();
               ListaInstrucciones.next();
            }
             bar(x2-5,y2-5,x2+5,y2+5);

        }
    }

    void ejecutarInstruccion(Instrucciones instruccion, string valor){
        switch(instruccion)
        {
            case Instrucciones::forward:
            {
                avance = atoi(valor.c_str());
                dibujarLinea();

                break;
            }
            case Instrucciones::back:
            {
                avance = atoi(valor.c_str());
                grados +=180;
                dibujarLinea();
                grados-=180;

                break;
            }
            case Instrucciones::right:
            {   // problemas
                grados += atoi(valor.c_str());
                break;
            }
            case Instrucciones::left:
            {
                grados -= atoi(valor.c_str());
                break;
            }
            case Instrucciones::setpos:
            {

                break;
            }
            case Instrucciones::setx:
            {

                break;
            }
            case Instrucciones::sety:
            {

                break;
            }
            case Instrucciones::setheading:
            {

                break;
            }
            case Instrucciones::home:
            {

                break;
            }
            case Instrucciones::circle:
            {

                break;
            }
            case Instrucciones::pos:
            {

                break;
            }
            case Instrucciones::xcor:

            {

                break;
            }
            case Instrucciones::ycor:
            {

                break;
            }
            case Instrucciones::heanding:
            {

                break;
            }
            case Instrucciones::pendown:
            {

                break;
            }
            case Instrucciones::penup:
            {

                break;
            }
            case Instrucciones::pensize:
            {

                break;
            }
            case Instrucciones::color:
            {

                break;
            }
            case Instrucciones::pen:
            {

                break;
            }
            case Instrucciones::loadfile:
            {

                break;
            }
            case Instrucciones::exec:
            {

                break;
            }
            case Instrucciones::clear:
            {

                break;
            }
            case Instrucciones::clearhistory:
            {

                break;
            }
            case Instrucciones::reset:
            {

                break;
            }
            case Instrucciones::write:
            {

                break;
            }
            case Instrucciones::repeat:
            {

                break;
            }
        }
    }








    virtual ~Turtle() {}
protected:
};

#endif // TURTLE_H
