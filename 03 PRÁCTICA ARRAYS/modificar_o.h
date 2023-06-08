#ifndef _MODIFICAR_O
#define _MODIFICAR_O

#include <iostream>
#include <string>
#include "buscar_o.h"
#include "ordenar.h"
#include "alumno.h"

using namespace std;

void modificar_o(Alumno *x, int n, int dato);

void modificar_o(Alumno *x, int n, int dato)
{
    int pos, pos2, op3, dato1;
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
        if (op3 == 1)
        {
            cout << "\t\tIngrese el codigo del alumno actualizado: "; cin >> dato1;
            pos2 = buscar_o(x, n, dato1);
            if ((pos2 > 0) || (x[pos2].codigo == dato))
            {
                cout << "\t\tEl codigo del alumno que ha ingresado ya esta registrado, INGRESE OTRO" << endl;
            }
            else
            {
                pos = buscar_o(x, n, dato);
                if ((pos > 0) || (x[pos].codigo == dato))
                {
                    x[pos].codigo = dato1;
                    ordenar(x, n);
                }
                else
                {
                    cout << "\t\tEl elemento no existe" << endl;
                }
                
            }
        }
        else if (op3 == 2)
        {
            cout << "\t\tIngrese el nombre completo del alumno actualizado: ";
            cin.ignore();
            getline(cin, nombre);
            pos = buscar_o(x, n, dato);
            if ((pos > 0) || (x[pos].codigo == dato))
            {
                x[pos].nombre = nombre;
            }
            else
            {
                cout << "\t\tEl elemento no existe" << endl;
            }
        }
        else if (op3 == 3)
        {
            cout << "\t\tIngrese la primera nota del alumno actualizado: "; cin >> dato1;
            pos = buscar_o(x, n, dato);
            if ((pos > 0) || (x[pos].codigo == dato))
            {
                x[pos].nota[0] = dato1;
                x[pos].prom = (x[pos].nota[0] + x[pos].nota[1])/2;
            }
            else
            {
                cout << "\t\tEl elemento no existe" << endl;
            }
        }
        else if (op3 == 4)
        {
            cout << "\t\tIngrese la segunda nota del alumno actualizado: "; cin >> dato1;
            pos = buscar_o(x, n, dato);
            if ((pos > 0) || (x[pos].codigo == dato))
            {
                x[pos].nota[1] = dato1;
                x[pos].prom = (x[pos].nota[0] + x[pos].nota[1])/2;
            }
            else
            {
                cout << "\t\tEl elemento no existe" << endl;
            }
        }
    }
    else
    {
        cout << "\t\tEl arreglo esta vacio" << endl;
    }
}

#endif