#ifndef TURTLE_H
#define TURTLE_H

#include <winbgim.h>
#include <iostream>
#include <string.h>
#include <cmath>

#include <fstream>
#include <sstream>


#include  "LinkedList.h"
#include  "Archivo.h"
#include "Instrucciones.h"
#include "FileManager.h"

#define PI 3.14159265358979
#define X_WINDOW 600
#define Y_WINDOW 400


using namespace std;
class Turtle{


public:
    Turtle(){

        initwindow (X_WINDOW,Y_WINDOW);
        avance = 0;
        dibujarLinea();
        grados = 0;
        pencolor = 15;
        pensize=1;
        x = X_WINDOW/2;
        y = Y_WINDOW/2;
        tempX = X_WINDOW/2;
        tempY = Y_WINDOW/2;
        x2 = x;
        y2 = y;
        pen = true;
        tortuga();
        dibujar = true;
      //  rutaArchivo ="./ListaInstrucciones";
        //bar(x-5,y-5,x+5,y+5);
    }

    void leerInstruccion(string cmd)
    {
        gurdarComando(cmd);
        //dibujarLista();
    }


private:

//    string rutaArchivo;
    int avance;
    int grados;
    int x,x2;
    int y,y2;
    int pensize;
    int pencolor;
    int tempX;
    int tempY;
    static int numDeInstrucciones;
    bool pen;
    int colorR;
    int colorG;
    int colorB;
    bool dibujar;
   //Instrucciones instruccion;

    LinkedList<Instrucciones> ListaInstrucciones;
        // se guardan las instrucciones
    LinkedList<string> ListaDatos;
        // se guardan los datos de cada instruccion...
    LinkedList<string> ListaHistorial;

    LinkedList<Instrucciones> ListaInstruccionestemp;
    LinkedList<string> ListaDatostemp;

    LinkedList<Instrucciones> ListaInstruccionesLeidas;
    LinkedList<string> ListaDatosLeidas;

    Instrucciones toInstruction(string cmd){return  mapString[cmd];}
            //convirte de string a tipo Instruccion

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
                    ostringstream convertR;   // stream used for the conversion
                    convertR << colorR;
                    string r = convertR.str() + " ";
                    ostringstream convertG;
                    convertG << colorG;
                    string g = convertG.str() + " ";
                    ostringstream convertB;
                    convertB << colorB;
                    string b = convertB.str() + "\"";
                    pcolor ="\""+r+g+b;
                }
                cout<<"El lapiz se encuentra "<<lapiz<<", con grosor "<<pensize<<" y color "<<pcolor<<endl;
                return true;
            }
            case Instrucciones::loadfile:
            {
                leerArchivo();
                return true;
            }
            case Instrucciones::exec:
            {
                AgregarLista();
                return true;
            }
            case Instrucciones::clearhistory:
            {
                ListaHistorial.clear();
                break;
            }
            case Instrucciones::clear:
            {
                /*tempX = x;
                tempY = y;*/
                cleardevice();
                ListaDatos.clear();
                ListaInstrucciones.clear();

                ostringstream xString;
                xString << x;
                ostringstream yString;
                yString << y;
                ostringstream gradosString;
                cout<<grados<<endl;
                gradosString << grados;
                gurdarComando("penup",false);
                cout<<"En string "<<gradosString.str()<<endl;
                gurdarComando("right "+gradosString.str(),false);
                gurdarComando("setpos "+xString.str()+","+yString.str(),false);//+atof(x)+","+y);
                gurdarComando("pendown",false);
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
        setfillstyle(XHATCH_FILL, 2);
        int grad = grados;
        fillellipse(x,y,8,8);
        //circle(x,y,10);
        int nuevaDistanciaX = 11 * cos(grad*PI/180);
        int nuevaDistanciaY = 11 * sin(grad*PI/180);
        int xtemp = nuevaDistanciaX+x;
        int ytemp = nuevaDistanciaY+y;
        int patas = 4;
        setfillstyle(SOLID_FILL, 2);
        fillellipse(xtemp,ytemp,3,3);
        //circle(xtemp,ytemp,4);
        grad-=45;
        while (patas >0){
            int nuevaDistanciaX = 10 * cos(grad*PI/180);
            int nuevaDistanciaY = 10 * sin(grad*PI/180);
            int xtemp = nuevaDistanciaX+x;
            int ytemp = nuevaDistanciaY+y;
            fillellipse(xtemp,ytemp,2,2);
            grad-=90;
            patas--;
        }
        grad=grados+180;
        nuevaDistanciaX = 9.5 * cos(grad*PI/180);
        nuevaDistanciaY = 9.5 * sin(grad*PI/180);
        xtemp = nuevaDistanciaX+x;
        ytemp = nuevaDistanciaY+y;
        fillellipse(xtemp,ytemp,1.5,1.5);
        //circle(xtemp,ytemp,1);
        setlinestyle(0,0,pensize);
        setcolor(pencolor);


    }
    // gurdarComando(line,false, true))
    int gurdarComando(string cmd,boolean guardarHistorial =true, boolean guardarEnTemporal = false)
    {
        size_t pos = 0;
        string delimitador = " ";
        string part1;
        string part2;
        string token;
        if (guardarHistorial)
            ListaHistorial.append(cmd);


        while ((pos = cmd.find(delimitador)) != string::npos)
        {
            token = cmd.substr(0, pos);
            part1 = string(token);
            int temp = pos+1;
            char let = cmd[temp];
            cmd.erase(0, pos + delimitador.length());
            if (token == "write"||token =="repeat"||token=="color"){
                break;
            }

        }
        part2 = string(cmd);
        // /*
        //cout<<"pParte1 = "<<part1<<endl;
        //cout<<"pParte2 = "<<part2<<endl;
        //  */
        if(strcmp(string("").c_str(),part1.c_str())==0)
        {
            part1 = part2;
            part2 = "next ";
          //  cout<<"nParte1 = "<<part1<<endl;
           //cout<<"nParte2 = "<<part2<<endl;
            Instrucciones nuevaInstruccion = toInstruction(part1);//*****

            if(casoEsp(part1))
                return 1;


        }
        //Instrucciones nuevaInstruccion;
        Instrucciones nuevaInstruccion = toInstruction(part1);
        string part;
         if(!guardarEnTemporal)
        {
            ListaInstrucciones.append(nuevaInstruccion);//**********
            if(strcmp(string("").c_str(),part2.c_str()) == 0)
                ListaDatos.append("nextLine");
            else
                ListaDatos.append(part2);
            dibujarLista();

         }else{
            ListaInstruccionesLeidas.append(nuevaInstruccion);//**********
            ListaDatosLeidas.append(part2);
         }

        return 0;
    }


    void dibujarLinea(){
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
        x =X_WINDOW/2;
        y =Y_WINDOW/2;

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

            for(int i = 0; i!=sizeList; i++)
            {
                string valor = ListaDatos.getElement();
                Instrucciones instruccion = ListaInstrucciones.getElement();
                cout << "   Instruccion actual: "<< int(instruccion) <<". Con el dato: " << valor <<endl;
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
        pen = true;
        if(ListaInstruccionestemp.getSize() == 0)
            cout << "Lista vacia" << endl;
        else
        {
            ListaInstruccionestemp.goToStart();
            ListaDatostemp.goToStart();
            int sizeList = ListaDatostemp.getSize();
            for(int i = 0; i!=sizeList; i++)
            {
                string valor = ListaDatostemp.getElement();
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
                   // return 0;
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
                if(pen==true){
                    line(x, y, atoi(part1.c_str()), atoi(part2.c_str()));
                }
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
                for(;veces > 0;veces--){

                    dibujarListatemp();
                }

                ListaDatostemp.clear();
                ListaInstruccionestemp.clear();
                break;
            }
        }
    }

    int leerArchivo(string ruta = "ListaInstrucciones.txt"){

        FileManager filer;
        ifstream file(ruta);
        string line;

        while(file.good()){
            getline(file,line);
            //cout <<"lectura: "<< line << endl;

            if( 1== gurdarComando(line,false, true))
                    cout << "" ;
            else
                    cout << "" ;
            //gurdarComando(string cmd,boolean guardarHistorial, boolean guardarEnTemporal)


            /*int tam = line.length();
            string* arraydeString; = filer.StringSplit('%', line, tam);
            for(int index = 0; index < tam; index++){
                //cout << arraydeString[index] << endl;

            }*/
        }
    }

    void AgregarLista(){

        ListaDatos = ListaDatosLeidas;
        ListaInstrucciones = ListaInstruccionesLeidas;
        //ListaDatos.addList(&ListaDatosLeidas);
        //ListaInstrucciones.addList(&ListaInstruccionesLeidas);

//        ListaDatos.printList();

        ListaDatos.goToStart();
        ListaInstrucciones.goToStart();

        //string dato = string(ListaDatos.getElement());

        dibujarLista();

    }

    virtual ~Turtle() {}
protected:
};

#endif // TURTLE_H

