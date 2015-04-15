#ifndef INSTRUCCIONES_H
#define INSTRUCCIONES_H

#include <map>

enum class Instrucciones
{
    forward = 1,
    back,
    right,
    left,
    setpos,
    setx,
    sety,
    setheading,
    home,
    circle,
    pos,
    xcor,
    ycor,
    heanding,
    pendown,
    penup,
    pensize,
    color,
    peninfo,
    reset,
    clear,
    write,
    repeat,
    loadfile,
    clearhistory,
    exec,
    exit,
    pen
};


    map<int , Instrucciones> nameMap =
    {
        {1 , Instrucciones::forward},
        {2 , Instrucciones::back},
        {3 , Instrucciones::right},
        {4 , Instrucciones::left},
        {5 , Instrucciones::setpos},
        {6 , Instrucciones::setx},
        {7 , Instrucciones::sety},
        {8 , Instrucciones::setheading},
        {9 , Instrucciones::home},
        {0 , Instrucciones::circle},
        {1 , Instrucciones::pos},
        {2 , Instrucciones::xcor},
        {3 , Instrucciones::ycor},
        {4 , Instrucciones::heanding},
        {5 , Instrucciones::pendown},
        {6 , Instrucciones::penup},
        {7 , Instrucciones::pensize},
        {8 , Instrucciones::color},
        {9 , Instrucciones::peninfo},
        {0 , Instrucciones::reset},
        {1 , Instrucciones::clear},
        {2 , Instrucciones::write},
        {3 , Instrucciones::repeat},
        {4 , Instrucciones::loadfile},
        {5 , Instrucciones::clearhistory},
        {6 , Instrucciones::exec},
        {7 , Instrucciones::exit},
        {8 , Instrucciones::pen}
    };
#endif // INSTRUCCIONES_H

