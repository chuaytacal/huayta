#ifndef _MOSTRAR
#define _MOSTRAR

#include <iostream>
#include "alumno.h"

using namespace std;

void mostrar(Alumno *x, int n);

void mostrar(Alumno *x, int n)
{
    for (int i = 0; i <= n; i++)
    {
        cout << "\t\tAlumno " << i + 1 << ": " << endl;
        cout << "\t\t" << x[i].codigo << "\t" << x[i].nombre << "\t" << x[i].nota[0] << "\t" << x[i].nota[1] << "\t" << x[i].prom;
        cout << endl << endl;
    }
}

#endif