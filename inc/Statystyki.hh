
#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH
#include <iostream>


struct Statystyka
{
    int poprawne;
    int bledne;
    double procent;
};

void zerowanie(Statystyka & St);


#endif
