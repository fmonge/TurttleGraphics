#ifndef DIBUJAR_H
#define DIBUJAR_H

#include <string>
#include <string.>
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
    int x,x2;
    int y,y2;
    int anchoDeLinea;
    int lapiz;
    int color;
    //string instruccion;

    //string titulo;
private:
    LinkedList<Instrucciones> ListaInstrucciones;
    LinkedList<string> ListaDatos;





public:

    Dibujar()
    {
        ListaInstrucciones.insert(Instrucciones::home);
        avance = 0;
        grados = 0;
        gradosAumentar = 0;
        x = X_WINDOW/2;
        y = Y_WINDOW/2;
        anchoDeLinea = 1;
    }

    void dibujarLinea(){
        cout << "-+DIBUJANDO+--" << endl;
        int nuevaDistanciaX = avance * cos(grados*PI/180);
        int nuevaDistanciaY = avance * sin(grados*PI/180);
        x2 = x +  nuevaDistanciaX;
        y2 = y +  nuevaDistanciaY;
        line (x, y, x2, y2);
        delay(500);
        x = x2;
        y = y2;
    }


    void dibujarLista()
    {
        x = X_WINDOW/2;
        y = Y_WINDOW/2;
        cout << "-+-+dibujarlista()+-+--" << ListaInstrucciones.getPos() << "pos - size"  <<ListaInstrucciones.getSize()<< endl;

        if(ListaInstrucciones.getSize() == 0)
            cout << "Lista vacia" << endl;
        else{

                ListaInstrucciones.goToStart();
                ListaInstrucciones.next();
/////////

 Node<E>* tmp = head->next;
        for(; tmp!=NULL; tmp=tmp->next)
            cout << " - " << tmp->element << " - ";


/////////
            for(;ListaInstrucciones.getPos() < ListaInstrucciones.getSize();ListaInstrucciones.next())
            {
                cout << "estoy en el  for con pos = " <<  ListaInstrucciones.getPos() << endl;

                Instrucciones comando = ListaInstrucciones.getElement();
                string  valor = ListaDatos.getElement();
                ListaDatos.next();

                switch(comando)
                {
                    case Instrucciones::forward:
                    {
                            cout << " in ford"  << endl;
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
                    {
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
                    case Instrucciones::exit:
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
        }
    }





    void guardarComando(Instrucciones instruccion){

        switch(instruccion)
        {
            case Instrucciones::setpos:
            {
                dibujarLinea();
                break;
            }
            case Instrucciones::repeat:
            {

                break;
            }
        }
        ListaInstrucciones.append(instruccion);
    }

    void guardarEnLista(string instruccion){
          size_t pos = 0;
            string  delimitador = " ";
            string part1;
            string part2;
            string token;

            while ((pos = instruccion.find(delimitador)) != string::npos) {
                token = instruccion.substr(0, pos);
                part1 = token;
                instruccion.erase(0, pos + delimitador.length());
            }
            part2=  instruccion;
            cout << "---part1---" << part1<< endl;
            cout << "---part2---" << part2<< endl;
            Instrucciones toEnum = toValue(part1);
            guardarComando(toEnum);
            ListaDatos.append(part2);
    }





    int leerEntrada(){
        initwindow (X_WINDOW,Y_WINDOW);
        bool lectura = true;

        while (lectura){

            string instruccion = "";
            cout << "Digite las instrucciones"<<endl;
            getline(cin,instruccion);

            //cin >> instruccion;//= a ;//+ " " + b;
            cout << "fija--> "<<instruccion<< "<---"<< endl;
            if( instruccion.compare("exit")== 0)
            {
                 lectura = false;
                 closegraph();
                 return 0;
            }

            guardarEnLista(instruccion);
            cleardevice();
            dibujarLista();
            bar(x2-5, y2-5, x2+5, y2+5);
            cout << " in while" << endl;

        }

        closegraph();
        }

Instrucciones toValue(string cmd) {
 int value = 0;
 cout << "valor de cmd " << cmd << endl;
           if(strcmp(cmd.c_str(), string("forward").c_str())==0)
        value =1;else
    if(strcmp(cmd.c_str(), string("back").c_str())==0)
        value = 2;else
    if(strcmp(cmd.c_str(), string("right").c_str())==0)
        value = 3;else
    if(strcmp(cmd.c_str(), string("left").c_str())==0)
        value = 4;else
    if(strcmp(cmd.c_str(), string("setpos").c_str())==0)
        value = 5;else
    if(strcmp(cmd.c_str(), string("setx").c_str())==0)
        value = 6;else
    if(strcmp(cmd.c_str(), string("sety").c_str())==0)
        value = 7;else
    if(strcmp(cmd.c_str(), string("setheading").c_str())==0)
        value = 8;else
    if(strcmp(cmd.c_str(), string("home").c_str())==0)
        value = 9;else
    if(strcmp(cmd.c_str(), string("circle").c_str())==0)
        value = 10;else
    if(strcmp(cmd.c_str(), string("pos").c_str())==0)
        value = 11;else
    if(strcmp(cmd.c_str(), string("xcor").c_str())==0)
        value = 12;else
    if(strcmp(cmd.c_str(), string("ycor").c_str())==0)
        value = 13;else
    if(strcmp(cmd.c_str(), string("heanding").c_str())==0)
        value = 14;else
    if(strcmp(cmd.c_str(), string("pendown").c_str())==0)
        value = 15;else
    if(strcmp(cmd.c_str(), string("penup").c_str())==0)
        value = 16;else
    if(strcmp(cmd.c_str(), string("pensize").c_str())==0)
        value = 17;else
    if(strcmp(cmd.c_str(), string("color").c_str())==0)
        value = 18;else
    if(strcmp(cmd.c_str(), string("peninfo").c_str())==0)
        value = 19;else
    if(strcmp(cmd.c_str(), string("reset").c_str())==0)
        value = 20;else
    if(strcmp(cmd.c_str(), string("clear").c_str())==0)
        value = 21;else
    if(strcmp(cmd.c_str(), string("write").c_str())==0)
        value = 22;else
    if(strcmp(cmd.c_str(), string("repeat").c_str())==0)
        value = 23;else
    if(strcmp(cmd.c_str(), string("loadfile").c_str())==0)
        value = 24;else
    if(strcmp(cmd.c_str(), string("clearhistory").c_str())==0)
        value = 25;else
    if(strcmp(cmd.c_str(), string("exec").c_str())==0)
        value = 26;else
    if(strcmp(cmd.c_str(), string("exit").c_str())==0)
        value = 27;else
    if(strcmp(cmd.c_str(), string("pen").c_str())==0)
        value = 28;
    cout << "print value " << value  << endl;
    //Instrucciones value1 = (Instrucciones)value;
    return  nameMap[value];
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


