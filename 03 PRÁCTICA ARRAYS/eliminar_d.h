#ifndef _ELIMINAR_D
#define _ELIMINAR_D

#include <iostream>
#include "alumno.h"

using namespace std;

void eliminar_d(Alumno *x, int &n, int dato);

void eliminar_d(Alumno *x, int &n, int dato)
{
    if (n > -1)
    {
        int i = 0, cen = 0;
        while ((i <= n+1) && (cen == 0))
        {
            if (x[i].codigo == dato)
            {
                cen = 1;
                for (int j = i; j <= n-1; j++)
                {
                    x[j] = x[j+1];
                }
            }
            else
            {
                i++;
            }
        }
        if (cen == 0)
        {
            cout << "\t\tEl dato a modificar no existe en el arreglo" << endl;
        }
        else
        {
            n--;
        }
    }
    else
    {
        cout << "\t\tEl arreglo esta vacio" << endl;
    }
    
}

#endif