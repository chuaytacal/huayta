#include <iostream>
#include <string>
#include "Alumno.h"

using namespace std;

struct ABB
{
    Alumno inf;
    ABB *izq;
    ABB *der;
};

void buscar_abb(ABB *raiz, Alumno dato);
void buscar1_abb(ABB *raiz, Alumno dato);
void insertar_abb(ABB *&raiz, Alumno clave);
void insertar1_abb(ABB *&raiz, Alumno clave);
void eliminar_abb(ABB *&raiz, Alumno clave);

void buscar_abb(ABB *raiz, Alumno dato)
{
    if (raiz != NULL)
    {
        if (dato.cod < raiz->inf.cod)
        {
            if (raiz->izq != NULL)
            {
                buscar_abb(raiz->izq, dato);
            }
            else
            {
                cout << "\nEL DATO NO EXISTE" << endl;
            }
        }
        else
        {
            if (dato.cod > raiz->inf.cod)
            {
                if (raiz->der != NULL)
                {
                    buscar_abb(raiz->der, dato);
                }
                else
                {
                    cout << "\nEL DATO NO EXISTE" << endl;
                }
            }
            else
            {
                cout << "\nEL DATO ES LOCALIZADO" << endl << endl;
                cout << "\nCODIGO: " << raiz->inf.cod << endl;
                cout << "NOMBRE: " << raiz->inf.nombre << endl;
                cout << "NOTA 1: " << raiz->inf.nota[0] << endl;
                cout << "NOTA 2: " << raiz->inf.nota[1] << endl;
                cout << "PROMEDIO: " << raiz->inf.prom << endl;
            }
        }
    }
    else
    {
        cout << "\nEL DATO NO EXISTE" << endl;
    }
}

void buscar1_abb(ABB *raiz, Alumno dato)
{
    if (raiz != NULL)
    {
        if (dato.cod < raiz->inf.cod)
        {
            buscar1_abb(raiz->izq, dato);
        }
        else
        {
            if (dato.cod > raiz->inf.cod)
            {
                buscar1_abb(raiz->der, dato);
            }
            else
            {
                cout << "\nEL DATO ES LOCALIZADO" << endl << endl;
                cout << "CODIGO: " << raiz->inf.cod << endl;
                cout << "NOMBRE: " << raiz->inf.nombre << endl;
                cout << "NOTA 1: " << raiz->inf.nota[0] << endl;
                cout << "NOTA 2: " << raiz->inf.nota[1] << endl;
                cout << "PROMEDIO: " << raiz->inf.prom << endl;
            }
        }
    }
    else
    {
        cout << "\nEL DATO NO EXISTE" << endl;
    }
}

void insertar_abb(ABB *&raiz, Alumno clave)
{
    ABB *q;
    if (raiz != NULL)
    {
        if (clave.cod < raiz->inf.cod)
        {
            if (raiz->izq != NULL)
            {
                insertar_abb(raiz->izq, clave);
            }
            else
            {
                q = new(ABB);
                q->inf.cod = clave.cod;
                q->inf.nombre = clave.nombre;
                q->inf.nota[0] = clave.nota[0];
                q->inf.nota[1] = clave.nota[1];
                q->inf.prom = clave.prom;
                q->izq = NULL;
                q->der = NULL;
                raiz->izq = q;
            }   
        }
        else
        {
            if (clave.cod > raiz->inf.cod)
            {
                if (raiz->der != NULL)
                {
                    insertar_abb(raiz->der, clave);
                }
                else
                {
                    q = new(ABB);
                    q->inf.cod = clave.cod;
                    q->inf.nombre = clave.nombre;
                    q->inf.nota[0] = clave.nota[0];
                    q->inf.nota[1] = clave.nota[1];
                    q->inf.prom = clave.prom;
                    q->izq = NULL;
                    q->der = NULL;
                    raiz->der = q;
                }
            }
            else
            {
                cout << "\nEL DATO YA EXISTE" << endl;
            }
        }
    }
    else
    {
        q = new(ABB);
        q->inf.cod = clave.cod;
        q->inf.nombre = clave.nombre;
        q->inf.nota[0] = clave.nota[0];
        q->inf.nota[1] = clave.nota[1];
        q->inf.prom = clave.prom;
        q->izq = NULL;
        q->der = NULL;
        raiz = q;
    }
    
}

void insertar1_abb(ABB *&raiz, Alumno clave)
{
    ABB *q;
    if (raiz != NULL)
    {
        if (clave.cod < raiz->inf.cod)
        {
            insertar1_abb(raiz->izq, clave);
        }
        else
        {
            if (clave.cod > raiz->inf.cod)
            {
                insertar1_abb(raiz->der, clave);
            }
            else
            {
                cout << "\nEL DATO YA EXISTE" << endl;
            }
        }
    }
    else
    {
        q = new(ABB);
        q->inf.cod = clave.cod;
        q->inf.nombre = clave.nombre;
        q->inf.nota[0] = clave.nota[0];
        q->inf.nota[1] = clave.nota[1];
        q->inf.prom = clave.prom;
        q->izq = NULL;
        q->der = NULL;
        raiz = q;
    }
}

void eliminar_abb(ABB *&raiz, Alumno clave)
{
    ABB *q;
    if (raiz != NULL)
    {
        if (clave.cod < raiz->inf.cod)
        {
            eliminar_abb(raiz->izq, clave);
        }
        else
        {
            if (clave.cod > raiz->inf.cod)
            {
                eliminar_abb(raiz->der, clave);
            }
            else
            {
                q = raiz;
                if (q->der == NULL)
                {
                    raiz = q->izq;
                }
                else
                {
                    if (q->izq == NULL)
                    {
                        raiz = q->der;
                    }
                    else
                    {
                        ABB *aux, *aux1;
                        aux = new(ABB);
                        aux = q->izq;
                        int cen = 0;
                        while (aux->der != NULL)
                        {
                            aux1 = aux;
                            aux = aux->der;
                            cen = 1;
                        }
                        raiz->inf.cod = aux->inf.cod;
                        raiz->inf.nombre = aux->inf.nombre;
                        raiz->inf.nota[0] = aux->inf.nota[0];
                        raiz->inf.nota[1] = aux->inf.nota[1];
                        raiz->inf.prom = aux->inf.prom;
                        q = aux;
                        if (cen == 0)
                        {
                            raiz->izq = aux->izq;
                        }
                        else
                        {
                            aux1->der = aux->izq;
                        }
                    }
                }
                delete (q);
            }
        }
    }
    else
    {
        cout << "\nEL DATO NO EXISTE" << endl;
    }
}