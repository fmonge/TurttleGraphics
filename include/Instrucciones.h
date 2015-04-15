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
    pen
};

map<string , Instrucciones> mapString =
{
    {"forward", Instrucciones::forward},
    {"back", Instrucciones::back},
    {"right", Instrucciones::right},
    {"left", Instrucciones::left},
    {"setpos", Instrucciones::setpos},
    {"setx", Instrucciones::setx},
    {"sety", Instrucciones::sety},
    {"setheading", Instrucciones::setheading},
    {"home", Instrucciones::home},
    {"circle" , Instrucciones::circle},
    {"pos" , Instrucciones::pos},
    {"xcor" , Instrucciones::xcor},
    {"ycor" , Instrucciones::ycor},
    {"heanding" , Instrucciones::heanding},
    {"pendown" , Instrucciones::pendown},
    {"penup" , Instrucciones::penup},
    {"pensize" , Instrucciones::pensize},
    {"color" , Instrucciones::color},
    {"peninfo" , Instrucciones::peninfo},
    {"reset" , Instrucciones::reset},
    {"clear" , Instrucciones::clear},
    {"write" , Instrucciones::write},
    {"repeat" , Instrucciones::repeat},
    {"loadfile" , Instrucciones::loadfile},
    {"clearhistory" , Instrucciones::clearhistory},
    {"exec" , Instrucciones::exec},
    {"pen" , Instrucciones::pen}
};
map<int , Instrucciones> MapInt =
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
    {10 , Instrucciones::circle},
    {11 , Instrucciones::pos},
    {12 , Instrucciones::xcor},
    {13 , Instrucciones::ycor},
    {14 , Instrucciones::heanding},
    {15 , Instrucciones::pendown},
    {16 , Instrucciones::penup},
    {17 , Instrucciones::pensize},
    {18 , Instrucciones::color},
    {19 , Instrucciones::peninfo},
    {20 , Instrucciones::reset},
    {21 , Instrucciones::clear},
    {22 , Instrucciones::write},
    {23 , Instrucciones::repeat},
    {24 , Instrucciones::loadfile},
    {25 , Instrucciones::clearhistory},
    {26 , Instrucciones::exec},
    {27 , Instrucciones::pen}
};

#endif // INSTRUCCIONES_H

