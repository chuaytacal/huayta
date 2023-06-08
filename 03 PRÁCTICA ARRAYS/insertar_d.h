#ifndef _INSERTAR_D
#define _INSERTAR_D

#include <iostream>
#include "alumno.h"

using namespace std;

void inserta_d(Alumno *x, int &n, int max, Alumno dato);

void inserta_d(Alumno *x, int &n, int max, Alumno dato)
{
    if (n < max-1)
    {
        n++;
        x[n] = dato;
    }
    else
    {
        cout << "\t\tNo hay espacio en el arreglo" << endl;  
    }
}

#endif