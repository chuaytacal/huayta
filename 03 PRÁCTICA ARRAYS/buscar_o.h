#ifndef _BUSCAR_O
#define _BUSCAR_O

#include <iostream>
#include "alumno.h"

using namespace std;

int buscar_o(Alumno *x, int n, int dato);

int buscar_o(Alumno *x, int n, int dato)
{
    int i = 0, pos = 0;
    while ((i <= n) && (x[i].codigo < dato))
    {
        i++;
    }
    if ((i > n) || (x[i].codigo > dato))
    {
        pos = -i;
    }
    else
    {
        pos = i;
    }
    return pos;
}

#endif