#include <iostream>
#include <string>
#include <iomanip>
#include "Alumno.h"

using namespace std;

struct nodo
{
    Alumno inf;
    nodo *sig;
    nodo *ant;
};

void cread_i(nodo *&p, nodo *&f){
    char op;
    nodo *q;
    do
    {
        system("cls");
        q = new(nodo);

        cout << "\nINGRESE EL CODIGO DEL ALUMNO: ";
        fflush(stdin);
        getline(cin, q->inf.codigo);
        cout << "\nINGRESE LOS APELLIDOS Y NOMBRES DEL ALUMNO: ";
        fflush(stdin);
        getline(cin, q->inf.nombre);
        cout << "\nINGRESE LA NOTA 1 DEL ALUMNO: ";
        cin >> q->inf.nota[0];
        cout << "\nINGRESE LA NOTA 2 DEL ALUMNO: ";
        cin >> q->inf.nota[1];
        q->inf.prom = (q->inf.nota[0] + q->inf.nota[1]) / 2;

        q->ant = NULL;
        q->sig = p;
        if (p == NULL)
        {
            f = q;
        }
        else
        {
            p->ant = q;
        }
        p = q;

        cout << "\n\n\t\t\tCREAR MAS NODOS (S/N): ";
        cin >> op;
    } while ((op == 's') || (op == 'S'));
}

void cread_f(nodo *&p, nodo *&f)
{
    char op;
    nodo *q;
    do
    {
        system("cls");
        q = new(nodo);

        cout << "\nINGRESE EL CODIGO DEL ALUMNO: ";
        fflush(stdin);
        getline(cin, q->inf.codigo);
        cout << "\nINGRESE LOS APELLIDOS Y NOMBRES DEL ALUMNO: ";
        fflush(stdin);
        getline(cin, q->inf.nombre);
        cout << "\nINGRESE LA NOTA 1 DEL ALUMNO: ";
        cin >> q->inf.nota[0];
        cout << "\nINGRESE LA NOTA 2 DEL ALUMNO: ";
        cin >> q->inf.nota[1];
        q->inf.prom = (q->inf.nota[0] + q->inf.nota[1]) / 2;

        q->sig = NULL;
        q->ant = f;
        if (p == NULL)
        {
            p = q;
        }
        else
        {
            f->sig = q;
        }
        f = q;
        cout << "\n\n\t\t\tCREAR MAS NODOS (S/N): ";
        cin >> op;
    } while ((op == 's') || (op == 'S'));
}

void insertad_i(nodo *&p, nodo *&f)
{
    system("cls");
    nodo *q;
    q = new(nodo);
    
    cout << "\nINGRESE EL CODIGO DEL ALUMNO: ";
    fflush(stdin);
    getline(cin, q->inf.codigo);
    cout << "\nINGRESE LOS APELLIDOS Y NOMBRES DEL ALUMNO: ";
    fflush(stdin);
    getline(cin, q->inf.nombre);
    cout << "\nINGRESE LA NOTA 1 DEL ALUMNO: ";
    cin >> q->inf.nota[0];
    cout << "\nINGRESE LA NOTA 2 DEL ALUMNO: ";
    cin >> q->inf.nota[1];
    q->inf.prom = (q->inf.nota[0] + q->inf.nota[1]) / 2;

    q->ant = NULL;
    q->sig = p;
    if (p == NULL)
    {
        f = q;
    }
    else
    {
        p->ant = q;
    }
    p = q;
}

void insertad_f(nodo *&p, nodo*&f)
{
    system("cls");
    nodo *q;
    q = new(nodo);

    cout << "\nINGRESE EL CODIGO DEL ALUMNO: ";
    fflush(stdin);
    getline(cin, q->inf.codigo);
    cout << "\nINGRESE LOS APELLIDOS Y NOMBRES DEL ALUMNO: ";
    fflush(stdin);
    getline(cin, q->inf.nombre);
    cout << "\nINGRESE LA NOTA 1 DEL ALUMNO: ";
    cin >> q->inf.nota[0];
    cout << "\nINGRESE LA NOTA 2 DEL ALUMNO: ";
    cin >> q->inf.nota[1];
    q->inf.prom = (q->inf.nota[0] + q->inf.nota[1]) / 2;

    q->sig = NULL;
    q->ant = f;
    if (p == NULL)
    {
        p = q;
    }
    else
    {
        f->sig = q;
    }
    f = q;
}

void inserta_ad(nodo *&p, nodo *&f, string ref)
{
    system("cls");
    nodo *q, *x, *r;
    int cen;
    if (p != NULL)
    {
        q = p;
        cen = 0;
        while ((q->inf.codigo != ref) && (cen == 0))
        {
            if (q->sig != NULL)
            {
                q = q->sig;
            }
            else
            {
                cen = 1;
            }
        }
        if (cen == 0)
        {
            x = new(nodo);
            
            cout << "\nINGRESE EL CODIGO DEL ALUMNO: ";
            fflush(stdin);
            getline(cin, x->inf.codigo);
            cout << "\nINGRESE LOS APELLIDOS Y NOMBRES DEL ALUMNO: ";
            fflush(stdin);
            getline(cin, x->inf.nombre);
            cout << "\nINGRESE LA NOTA 1 DEL ALUMNO: ";
            cin >> x->inf.nota[0];
            cout << "\nINGRESE LA NOTA 2 DEL ALUMNO: ";
            cin >> x->inf.nota[1];
            x->inf.prom = (x->inf.nota[0] + x->inf.nota[1]) / 2;

            x->sig = q;
            r = q->ant;
            x->ant = r;
            q->ant = x;
            if (p != q)
            {
                r->sig = q;
            }
            else
            {
                p = x;
            }
        }
        else
        {
            cout << "NO EXISTE EL CODIGO DEL ALUMNO REFERENCIAL" << endl;
        }
    }
    else
    {
        cout << "LA LISTA ESTA VACIA" << endl;
    }
}

void insertard_dd(nodo *&p, nodo *&f, string ref)
{
    system("cls");
    nodo *q, *x, *r;
    int cen;
    if (p != NULL)
    {
        q = p;
        cen = 0;
        while ((q->inf.codigo != ref) && (cen == 0))
        {
            if (q->sig != NULL)
            {
                q = q->sig;
            }
            else
            {
                cen = 1;
            }
        }
        if (cen == 0)
        {
            x = new(nodo);

            cout << "\nINGRESE EL CODIGO DEL ALUMNO: ";
            fflush(stdin);
            getline(cin, x->inf.codigo);
            cout << "\nINGRESE LOS APELLIDOS Y NOMBRES DEL ALUMNO: ";
            fflush(stdin);
            getline(cin, x->inf.nombre);
            cout << "\nINGRESE LA NOTA 1 DEL ALUMNO: ";
            cin >> x->inf.nota[0];
            cout << "\nINGRESE LA NOTA 2 DEL ALUMNO: ";
            cin >> x->inf.nota[1];
            x->inf.prom = (x->inf.nota[0] + x->inf.nota[1]) / 2;

            r = q->sig;
            x->sig = r;
            x->ant = q;
            q->sig = x;
            if (q == f)
            {
                f = x;
            }
            else
            {
                r->ant = x;
            }
        }
        else
        {
            cout << "NO EXISTE EL CODIGO DEL ALUMNO REFERENCIAL" << endl;
        }
    }
    else
    {
        cout << "LA LISTA ESTA VACIA" << endl;
    }
}

void eliminard_i(nodo *&p, nodo *&f)
{
    system("cls");
    nodo *q;
    if (p != NULL)
    {
        q = p;
        p = p->sig;
        if (q == f)
        {
            f = p;
        }
        else
        {
            p->ant = NULL;
        }
        delete(q);
        cout << "SE ELIMINO AL PRIMER ESTUDIANTE" << endl << endl;
    }
    else
    {
        cout << "LA LISTA ESTA VACIA" << endl << endl;
    }
    system ("pause");
}

void eliminard_u(nodo *&p, nodo *&f)
{
    system("cls");
    nodo *q;
    if (p != NULL)
    {
        q = f;
        f = f->ant;
        if (q == p)
        {
            p = f;
        }
        else
        {
            f->sig = NULL;
        }
        delete(q);
        cout << "SE ELIMINO AL ULTIMO ESTUDIANTE" << endl << endl;
    }
    else
    {
        cout << "LA LISTA ESTA VACIA" << endl << endl;
    }
    system("pause");
}

void eliminard_x(nodo *&p, nodo *&f, string x)
{
    system("cls");
    nodo *q, *r, *t;
    int cen = 0;
    if (p != NULL)
    {
        q = p;
        while ((q->inf.codigo != x) && (cen == 0))
        {
            if (q->sig != NULL)
            {
                q = q->sig;
            }
            else
            {
                cen = 1;
            }
        }
        if (cen == 0)
        {
            if (p == f)
            {
                p = NULL;
                f = NULL;
            }
            else
            {
                if (p == q)
                {
                    p = p->sig;
                    p->ant = NULL;
                }
                else
                {
                    if (q == f)
                    {
                        f = f->ant;
                        f->sig = NULL;
                    }
                    else
                    {
                        r = q->ant;
                        t = q->sig;
                        r->sig = t;
                        t->ant = r;
                    }
                }
            }
            delete(q);
            cout << "SE ELIMINO AL ESTUDIANTE CORRESPONDIENTE" << endl << endl;
        }
        else
        {
            cout << "EL DATO DEL ALUMNO REFERENCIAL NO EXISTE" << endl << endl;
        }
    }
    else
    {
        cout << "LA LISTA ESTA VACIA" << endl << endl;
    }
    system("pause");
}

void busqueda(nodo *p)
{
    nodo *q;
    char op;
    do
    {
        system("cls");
        q = p;
        string ref;
        int cen = 0, cont = 1;
        cout  << "\nINGRESE EL CODIGO DEL ALUMNO A BUSCAR: ";
        fflush(stdin);
        getline(cin, ref);
        while ((q->inf.codigo != ref) && (cen == 0))
        {
            cont++;
            if (q->sig != NULL)
            {
                q = q->sig;
            }
            else
            {
                cen = 1;
            }
        }
        if (cen == 0)
        {
            cout << "\nALUMNO ENCONTRADO: ";
            cout << "\n\nCODIGO: " << q->inf.codigo;
            cout << "\nAPELLIDOS Y NOMBRES: " << q->inf.nombre;
            cout << "\nNOTA 1: " << q->inf.nota[0];
            cout << "\nNOTA 2: " << q->inf.nota[1];
            cout << "\nPROMEDIO: " << q->inf.prom;
            cout << "\n\nEL ALUMNO SE ENCUENTRA EN LA POSICION " << cont << endl;
        }
        else
        {
            cout << "\nEL DATO NO EXISTE";
        }
        cout << "\n\n\t\t\tBUSCAR MAS DATOS(S/N): ";
        cin >> op;
    } while ((op == 's' || (op == 'S')));
}

void mostrar(nodo *p)
{
    nodo *q;
    q = p;
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << setw(40) << "ALUMNOS" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << setw(11) << "CODIGO";
    cout << setw(35) << "APELLIDOS Y NOMBRES";
    cout << setw(10) << "NOTA 1";
    cout << setw(10) << "NOTA 2";
    cout << setw(12) << "PROMEDIO" << endl;
    while (q != NULL)
    {
        cout << setw(11) << q->inf.codigo;
        cout << setw(35) << q->inf.nombre;
        cout << setw(10) << q->inf.nota[0];
        cout << setw(10) << q->inf.nota[1];
        cout << setw(12) << q->inf.prom;
        cout << endl;
        q = q->sig;
    }
    cout << "------------------------------------------------------------------------------------" << endl;
}