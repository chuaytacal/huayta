#ifndef _INSERTAR_O
#define _INSERTAR_O

#include <iostream>
#include "buscar_o.h"
#include "alumno.h"

using namespace std;

void inserta_o(Alumno *x, int &n, int max, Alumno dato);

void inserta_o(Alumno *x, int &n, int max, Alumno dato)
{
    int pos;
    if (n < max-1)
    {
        pos = buscar_o(x, n, dato.codigo);
        if (pos <= 0)
        {
            pos = -pos;
            for (int i = n+1; i >= pos+1 ; i--)
            {
                x[i] = x[i-1];
            }
            n++;
            x[pos] = dato;
        }
        else
        {
            cout << "\t\tEl dato ya existe" << endl;
        }
    }
    else
    {
        cout << "\t\tEl arreglo esta lleno" << endl;
    }
}

#endif