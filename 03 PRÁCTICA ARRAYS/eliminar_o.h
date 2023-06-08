#ifndef _ELIMINAR_O
#define _ELIMINAR_O

#include <iostream>
#include "buscar_o.h"
#include "alumno.h"

using namespace std;

void eliminar_o(Alumno *x, int &n, int dato);

void eliminar_o(Alumno *x, int &n, int dato)
{
    int pos;
    if (n > -1)
    {
        pos = buscar_o(x, n, dato);
        
        if ((pos > 0) || (x[pos].codigo == dato))
        {
            for (int i = pos; i <= n-1; i++)
            {
                x[i] = x[i+1];
            }
            n--;
        }
        else
        {
            cout << "\t\tEl elemeno no existe en el arreglo" << endl;
        }
    }
    else
    {
        cout << "\t\tEl arreglo esta vacio" << endl;
    }
}

#endif