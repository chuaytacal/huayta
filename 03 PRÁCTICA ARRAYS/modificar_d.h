#ifndef _MODIFICAR_D
#define _MODIFICAR_D

#include <iostream>
#include <string>
#include "alumno.h"

using namespace std;

void modificar_d(Alumno *x, int n, int dato);

void modificar_d(Alumno *x, int n, int dato)
{
    int op3, op4 = 0, dato1;
    string nombre;
    if (n > -1)
    {
        cout << "\t\tDesea modificar:" << endl;
        cout << "\t\t1. Codigo" << endl;
        cout << "\t\t2. Apellidos y Nombres" << endl;
        cout << "\t\t3. Nota 1" << endl;
        cout << "\t\t4. Nota 2" << endl;
        cout << "\t\t\t OPCION: "; cin >> op3;
        system("cls");
        int i = 0, cen = 0;
        if (op3 == 1)
        {
            cout << "\t\tIngrese el codigo del alumno actualizado: "; cin >> dato1;
            for (int j = 0; j <= n; j++)
            {
                if (x[j].codigo == dato1)
                {
                    op4 = 1;
                }
            }
            if (op4 != 1)
            {
                while ((i <= n+1) && (cen == 0))
                {
                    if (x[i].codigo == dato)
                    {
                        cen = 1;
                        x[i].codigo = dato1;
                    }
                    else
                    {
                        i++;
                    }
                }
            }
            else
            {
                cout << "\t\tEl codigo del alumno que ha ingresado ya esta registrado, INGRESE OTRO" << endl;
            } 
            if (cen == 0)
            {
                cout << "\t\tEl dato a modificar no existe en el arreglo" << endl;
            }
        }
        else if (op3 == 2)
        {
            cout << "\t\tIngrese el nombre del alumno actualizado: ";
            cin.ignore();
            getline(cin, nombre);
            while ((i <= n+1) && (cen == 0))
            {
                if (x[i].codigo == dato)
                {
                    cen = 1;
                    x[i].nombre = nombre;
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
        }
        else if (op3 == 3)
        {
            cout << "\t\tIngrese la primera nota del alumno actualizado: "; cin >> dato1;
            while ((i <= n+1) && (cen == 0))
            {
                if (x[i].codigo == dato)
                {
                    cen = 1;
                    x[i].nota[0] = dato1;
                    x[i].prom = (x[i].nota[0] + x[i].nota[1])/2;
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
        }
        else if (op3 == 4)
        {
            cout << "\t\tIngrese la segunda nota del alumno actualizado: "; cin >> dato1;
            while ((i <= n+1) && (cen == 0))
            {
                if (x[i].codigo == dato)
                {
                    cen = 1;
                    x[i].nota[1] = dato1;
                    x[i].prom = (x[i].nota[0] + x[i].nota[1])/2;
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
        }
    }
    else
    {
        cout << "\t\tEl arreglo esta vacio" << endl;
    }
    
}

#endif