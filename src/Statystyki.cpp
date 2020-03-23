#include "Statystyki.hh"
#include <iostream>



int StatProc(Statystyka& St)
{
    St.procent=((St.poprawne/(St.bledne+St.poprawne))*100);
    return St.procent;
}

void zerowanie(Statystyka & St)
{
    St.poprawne = 0;
    St.bledne = 0;
}

