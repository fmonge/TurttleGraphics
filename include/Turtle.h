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
#include <sstream>

using namespace std;
class Turtle{


public:
    Turtle(){

        initwindow (X_WINDOW,Y_WINDOW);
        avance = 0;
        grados = 0;
        pencolor = 15;
        pensize=1;
        x = X_WINDOW/2;
        y = Y_WINDOW/2;
        x2 = x;
        y2 = y;
        pen = true;
        tortuga();
        //bar(x-5,y-5,x+5,y+5);
    }

    void leerInstruccion(string cmd)
    {
        gurdarComando(cmd);
        //dibujarLista();
    }
private:

    int avance;
    int grados;
    int x,x2;
    int y,y2;
    int pensize;
    int pencolor;
    static int numDeInstrucciones;
    bool pen;
   //Instrucciones instruccion;

    LinkedList<Instrucciones> ListaInstrucciones;
        // se guardan las instrucciones
    LinkedList<string> ListaDatos;
        // se guardan los datos de cada instruccion...
    LinkedList<string> ListaHistorial;

    LinkedList<Instrucciones> ListaInstruccionestemp;
    LinkedList<string> ListaDatostemp;

    Instrucciones toInstruction(string cmd){return  mapString[cmd];}
    bool is_number(const string& s){

       for(int i = 0; i < s.length(); i++){//for each char in string,
          if(isdigit(s[i]))
            {
             return false;
            }
        }return true;
    }

    bool casoEsp(string str){
        Instrucciones instruction = toInstruction(str);
        switch(instruction)
        {

            case Instrucciones::pos:
            {
                cout<<"La tortuga se encuentra en X="<<x<<", Y="<<y<<endl;
                return true;

            }
            case Instrucciones::xcor:

            {
                cout<<"La tortuga se encuentra en X="<<x<<endl;
                return true;
            }
            case Instrucciones::ycor:
            {
                cout<<"La tortuga se encuentra en Y="<<y<<endl;
                return true;
            }
            case Instrucciones::heading:
            {
                grados = grados*-1;
                if (grados < 0){
                    grados+=360;
                }
                cout<<"La tortuga se encuentra con rumbo de "<<grados<<" grados"<<endl;
                return true;
            }

            case Instrucciones::pen:
            {
                string lapiz= "arriba";
                if (pen)
                    lapiz="abajo";
                string pcolor = "";
                pcolor = mapColorString[pencolor];
                if (pcolor==""){
                        ostringstream convert;   // stream used for the conversion

                    convert << pencolor;
                    pcolor = convert.str();
                }
                cout<<"El lapiz se encuentra "<<lapiz<<", con grosor "<<pensize<<" y color "<<pcolor<<endl;
                return true;
            }
            case Instrucciones::loadfile:
            {

                break;
            }
            case Instrucciones::exec:
            {

                break;
            }
            case Instrucciones::clearhistory:
            {
                ListaHistorial.clear();
                break;
            }
            case Instrucciones::clear:
            {
                cleardevice();
                ListaDatos.clear();
                ListaInstrucciones.clear();
                tortuga();
                return true;
            }
            case Instrucciones::reset:
            {
                cleardevice();
                ListaDatos.clear();
                ListaInstrucciones.clear();
                avance = 0;
                grados = 0;
                pencolor = 15;
                pensize=1;
                x = X_WINDOW/2;
                y = Y_WINDOW/2;
                x2 = y2 = 0;
                pen = true;
                tortuga();
                return true;
            }

            case Instrucciones::history:
            {
                ListaHistorial.goToStart();
                cout<<endl;
                cout<<"-------- Historial ---------"<<endl;
                for(int ind = 0; ind < ListaHistorial.getSize();ListaHistorial.next(),ind++){
                    cout<<ListaHistorial.getElement()<<endl;
                }
                cout<<endl;

                return true;
            }
        }
        return false;
    }
    void tortuga(){
        setlinestyle(0,0,1);
        setcolor(10);
        setfillstyle(SOLID_FILL, 2);
        int grad = grados;
        fillellipse(x,y,10,10);
        //circle(x,y,10);
        int nuevaDistanciaX = 13 * cos(grad*PI/180);
        int nuevaDistanciaY = 13 * sin(grad*PI/180);
        int xtemp = nuevaDistanciaX+x;
        int ytemp = nuevaDistanciaY+y;
        int patas = 4;
        setfillstyle(SOLID_FILL, 2);
        fillellipse(xtemp,ytemp,3,3);
        //circle(xtemp,ytemp,4);
        grad-=45;
        while (patas >0){
            int nuevaDistanciaX = 12 * cos(grad*PI/180);
            int nuevaDistanciaY = 12 * sin(grad*PI/180);
            int xtemp = nuevaDistanciaX+x;
            int ytemp = nuevaDistanciaY+y;
            fillellipse(xtemp,ytemp,2,2);
            grad-=90;
            patas--;
        }
        grad=grados+180;
        nuevaDistanciaX = 11.5 * cos(grad*PI/180);
        nuevaDistanciaY = 11.5 * sin(grad*PI/180);
        xtemp = nuevaDistanciaX+x;
        ytemp = nuevaDistanciaY+y;
        fillellipse(xtemp,ytemp,1.5,1.5);
        //circle(xtemp,ytemp,1);
        setlinestyle(0,0,pensize);
        setcolor(pencolor);


    }

    int gurdarComando(string cmd)
    {
        size_t pos = 0;
        string delimitador = " ";
        string part1;
        string part2;
        string token;
        ListaHistorial.append(cmd);


        while ((pos = cmd.find(delimitador)) != string::npos) {
            token = cmd.substr(0, pos);
            part1 = string(token);
            int temp = pos+1;
            char let = cmd[temp];
            cmd.erase(0, pos + delimitador.length());
            if (token == "write"||token =="repeat"||token=="color"){
                break;
            }
            //if (let=='"')
                //break;

        }
        part2 = string(cmd);
        /*cout<<"Parte1 = "<<part1<<endl;
        cout<<"Parte2 = "<<part2<<endl;*/

            if(strcmp(string("").c_str(),part1.c_str())==0){
                part1 = part2;
                part2 = "next ";
                //cout<<"Parte1 = "<<part1<<endl;
                //cout<<"Parte2 = "<<part2<<endl;
                Instrucciones nuevaInstruccion = toInstruction(part1);//*****

                if(casoEsp(part1)){
                    return 0;
                }

            }
        Instrucciones nuevaInstruccion = toInstruction(part1);
        ListaInstrucciones.append(nuevaInstruccion);//**********
        //**********

        if(strcmp(string("").c_str(),part2.c_str()) == 0)
            ListaDatos.append("nextLine");
        else
            ListaDatos.append(part2);
            dibujarLista();
        return 0;
    }  // le cuarda nextLine en la lista de datos! pero cuando lee
    // nada pasa..

    void dibujarLinea(){
        //cout << "info:       -+DIBUJANDO+-- -> "  <<endl;
        //cout  <<"info:      " << avance<< endl;
        int nuevaDistanciaX = avance * cos(grados*PI/180);
        int nuevaDistanciaY = avance * sin(grados*PI/180);
        x2 = x +  nuevaDistanciaX;
        y2 = y +  nuevaDistanciaY;
        if (pen){
            line (x, y, x2, y2);
        }
        delay(10);
        x = x2;
        y = y2;
    }



    void dibujarLista()
    {
        x = X_WINDOW/2;
        y = Y_WINDOW/2;
       // cout << "---Recorrer-lista-----<" << "size< "  <<ListaInstrucciones.getSize()<<" >"<< endl;
        pensize=1;
        setlinestyle(0, 0, pensize);
        pencolor = 15;
        setcolor(pencolor);
        pen = true;

        if(ListaInstrucciones.getSize() == 0)
            cout << "Lista vacia" << endl;
        else
        {
            cleardevice();
            grados = 0;
            ListaInstrucciones.goToStart();
            ListaDatos.goToStart();
            int sizeList = ListaDatos.getSize();
            //cout << "el Tamaño de la lista es de: " << sizeList << endl;

            for(int i = 0; i!=sizeList; i++)
            {
                //cout << " Estoy en el  for con pos = " << i << endl;

                string valor = ListaDatos.getElement();
               // Instrucciones instruccion = ListaInstrucciones.getElement();
                //cout << "   Instruccion actual: "<< int(instruccion) <<". Con el dato: " << valor <<endl;
               ejecutarInstruccion(ListaInstrucciones.getElement(),ListaDatos.getElement());
               ListaDatos.next();
               ListaInstrucciones.next();
               sizeList = ListaDatos.getSize();
            }
            tortuga();
             kbhit();

        }
    }
    void dibujarListatemp()
    {
       // cout << "---Recorrer-lista-----<" << "size< "  <<ListaInstrucciones.getSize()<<" >"<< endl;

        pen = true;

        if(ListaInstruccionestemp.getSize() == 0)
            cout << "Lista vacia" << endl;
        else
        {
            ListaInstruccionestemp.goToStart();
            ListaDatostemp.goToStart();
            int sizeList = ListaDatostemp.getSize();
            //cout << "el Tamaño de la lista es de: " << sizeList << endl;

            for(int i = 0; i!=sizeList; i++)
            {
                //cout << " Estoy en el  for con pos = " << i << endl;

                string valor = ListaDatostemp.getElement();
               // Instrucciones instruccion = ListaInstrucciones.getElement();
                //cout << "   Instruccion actual: "<< int(instruccion) <<". Con el dato: " << valor <<endl;
               ejecutarInstruccion(ListaInstruccionestemp.getElement(),ListaDatostemp.getElement());
               ListaDatostemp.next();
               ListaInstruccionestemp.next();
               sizeList = ListaDatostemp.getSize();
            }

        }
    }
    int gurdarComandotemp(string cmd)
    {
        size_t pos = 0;
        string delimitador = " ";
        string part1;
        string part2;
        string token;
        while ((pos = cmd.find(delimitador)) != string::npos) {
            token = cmd.substr(0, pos);
            part1 = string(token);
            int temp = pos+1;
            char let = cmd[temp];
            cmd.erase(0, pos + delimitador.length());
            if (token == "write"){
                break;
            }
            //if (let=='"')
                //break;

        }
        part2 = string(cmd);
        if (part1=="repeat"){
            cout<<"No repeats in a repeat plz"<<endl;
            return 0;
        }

            if(strcmp(string("").c_str(),part1.c_str())==0){
                part1 = part2;
                part2 = "next ";
                Instrucciones nuevaInstruccion = toInstruction(part1);//*****
                if(casoEsp(part1)){

                }

            }
        Instrucciones nuevaInstruccion = toInstruction(part1);
        ListaInstruccionestemp.append(nuevaInstruccion);//**********
        //**********

        if(strcmp(string("").c_str(),part2.c_str()) == 0)
            ListaDatostemp.append("nextLine");
        else
            ListaDatostemp.append(part2);
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
                size_t pos = 0;
                string delimitador = ",";
                string part1;
                string part2;
                string token;
                while ((pos = valor.find(delimitador)) != string::npos) {
                    token = valor.substr(0, pos);
                    part1 = string(token);
                    valor.erase(0, pos + delimitador.length());
                }
                part2=  string(valor);
                x = atoi(part1.c_str());
                y = atoi(part2.c_str());
                break;
            }
            case Instrucciones::setx:
            {
                x2 = atoi(valor.c_str());
                if(pen==true){
                    line(x, y, x2, y2);
                }
                x = x2;
                y = y2;
                break;
            }
            case Instrucciones::sety:
            {
                y2 = atoi(valor.c_str());
                if(pen==true){
                    line(x, y, x2, y2);
                }
                x = x2;
                y = y2;
                break;
            }
            case Instrucciones::setheading:
            {
                int grado = atoi(valor.c_str());
                grados = grados - grado;
                break;
            }
            case Instrucciones::home:
            {
                grados = 0;
                x = X_WINDOW/2;
                y = Y_WINDOW/2;
                break;
            }
            case Instrucciones::circle:
            {
                int grad=grados;
                int radio = atoi(valor.c_str());
                if (radio > 0){
                    grad -= 90;
                    int nuevaDistanciaX = radio * cos(grad*PI/180);
                    int nuevaDistanciaY = radio * sin(grad*PI/180);
                    int x2temp = x +  nuevaDistanciaX;
                    int y2temp = y +  nuevaDistanciaY;
                    circle(x2temp,y2temp,radio);
                    delay(10);
                    break;

                }
                if (radio > 0){
                    grad += 90;
                    int nuevaDistanciaX = radio * cos(grad*PI/180);
                    int nuevaDistanciaY = radio * sin(grad*PI/180);
                    int x2temp = x +  nuevaDistanciaX;
                    int y2temp = y +  nuevaDistanciaY;
                    circle(x2temp,y2temp,radio);
                    delay(10);
                    break;

                }

                break;
            }

            case Instrucciones::pendown:
            {
                pen=true;
                break;
            }
            case Instrucciones::penup:
            {
                pen=false;
                break;
            }
            case Instrucciones::pensize:
            {
                pensize = atoi(valor.c_str());
                setlinestyle(0, 0, pensize);
                break;
            }
            case Instrucciones::color:
            {
                pencolor = mapColor[valor];
                setcolor(pencolor);
                if (is_number(valor)==false){
                    int ind = 0;
                    int colorR;
                    int colorG;
                    int colorB;
                    int num = 1;
                    string token;
                    string part1;
                    valor += " 4r1s";
                    while(valor!="4r1s"){
                        if (valor[ind]==' '){
                            token = valor.substr(0,ind);
                            part1 = string(token);
                            valor.erase(0, ind+1);
                            if (num==1){
                                colorR = atoi(part1.c_str());
                            }
                            if (num==2){
                                colorG = atoi(part1.c_str());
                            }
                            if (num==3){
                                colorB = atoi(part1.c_str());
                            }
                            num++;
                            ind = 0;
                            continue;
                            //cout<<"Parte1= "<<part1<<endl;
                            //cout<<"Parte2= "<<part2<<endl;
                            }
                            ind++;
                    }
                    pencolor = COLOR(colorR,colorG,colorB);
                    setcolor(pencolor);
                }

                break;
            }
            case Instrucciones::write:
            {

                size_t pos = 0;
                string delimitador = " ";
                string part1;
                string part2;
                string token;
                while ((pos = valor.find(delimitador)) != string::npos) {

                    token = valor.substr(0, pos);
                    part1 = string(token);
                    valor.erase(0, pos + delimitador.length());
                    char let=valor[pos+1];
                    if (let==' ')
                        cout<<endl;
                        break;
                }
                part2=  string(valor);
                /*cout<<"Parte1 = "<<part1<<endl;
                cout<<"Parte2 = "<<part2<<endl;
                cout<<part2[0]<<endl;
                cout<<part2[part2.length()-1]<<endl;*/
                if ((part2[0]!='"') || (part2[part2.length()-1]!='"')){
                    break;
                }
                part2.erase(0, 1);
                part2.erase(part2.length()-1, part2.length());


                int textsize = atoi(part1.c_str());;
                settextstyle(0,0,textsize);
                moveto(x,y+20);
                outtext(part2.c_str());
                delay(10);
                break;
            }

            case Instrucciones::repeat:
            {
                size_t pos = 0;
                string delimitador = " ";
                string part1;
                string part2;
                string token;
                string token2="";
                while ((pos = valor.find(delimitador)) != string::npos) {
                    token = valor.substr(0, pos);
                    part1 = string(token);
                    valor.erase(0, pos + delimitador.length());
                    char let=valor[pos+1];
                    if (let==' ')
                        cout<<endl;
                        break;
                }
                part2 =  string(valor);

                if ((part2[0]!='[') || (part2[part2.length()-1]!=']')){
                    break;
                }
                part2.erase(0, 1);
                part2.erase(part2.length()-1, part2.length());
                int veces = atoi(part1.c_str());
               // cout<<part1<<endl;
                //cout<<part2<<endl;


                pos = 0;
                string delimitadortemp = ",";
                string delimitadortemp2 = ".";
                part2 += ",4r1s";
                int ind =0;
                cout<<part1<<endl;
                cout<<part2<<endl;
                while(part2!="4r1s"){
                    if (part2[ind]==','){
                        token = part2.substr(0,ind);
                        part1 = string(token);
                        part2.erase(0, ind+1);
                        gurdarComandotemp(part1);
                        ind = 0;
                        continue;
                        //cout<<"Parte1= "<<part1<<endl;
                        //cout<<"Parte2= "<<part2<<endl;
                    }
                    ind++;
                }
                    /*while ((pos = part2.find(delimitadortemp)) != string::npos) {
                            token2 = part2.substr(0, pos);
                            part1 = string(token2);
                            part2.erase(0, pos + delimitadortemp.length());
                            cout<<part1<<endl;
                            gurdarComandotemp(part1);
                            gurdarComandotemp(part2);
                    }*/
                //cout<<"se cayo aqui"<<endl;
                if (token==""){
                    token=part2;
                    gurdarComandotemp(token2);
                }
                for(veces;veces > 0;veces--){
                    dibujarListatemp();
                }

                ListaDatostemp.clear();
                ListaInstruccionestemp.clear();
                break;
            }
        }

    }



    virtual ~Turtle() {}
protected:
};

#endif // TURTLE_H
