#include <iostream>
#include <string>
#include <iomanip>
#include "alumno.h"

using namespace std;

struct nodo
{
    Alumno inf;
    nodo *sig;
};
nodo *crea_i(nodo *p)
{
    nodo *q;
    char op;
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
        
        q->sig = p;
        p = q;
        cout << "\n\n\t\t\tMAS DATOS (S/N): ";
        cin >> op;
    } while ((op == 's') || (op == 'S'));
    return (p);
}

nodo *crea_f(nodo *p)
{
    nodo *q, *r;
    char op;
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
        if (p == NULL)
        {
            p = q;
        }
        else
        {
            r = p;
            while (r->sig != NULL)
                r = r->sig;
            r->sig = q;
        }
        cout << "\n\n\t\t\tMAS DATOS (S/N): ";
        cin >> op;
    } while ((op == 's') || (op == 'S'));
    return (p);
}

nodo *crear_a(nodo *p)
{
    nodo *r, *q, *o;
    char op;
    do
    {
        if (p != NULL)
        {
            system("cls");
            r = p;
            int cen = 0;
            string ref;
            cout << "\nINGRESE EL CODIGO DEL ALUMNO REFERENCIA: ";
            fflush(stdin);
            getline(cin, ref);
            while ((r->inf.codigo != ref) && (cen == 0))
            {
                if (r->sig != NULL)
                {
                    q = r;
                    r = r->sig;
                }
                else 
                {
                    cen = 1;
                }
            }
            if (cen == 0)
            {
                o = new(nodo);
                    cout << "\nINGRESE EL CODIGO DEL ALUMNO A INSERTAR: ";
                    fflush(stdin);
                    getline(cin, o->inf.codigo);
                    cout << "\nINGRESE LOS APELLIDOS Y NOMBRES DEL ALUMNO A INSERTAR: ";
                    fflush(stdin);
                    getline(cin, o->inf.nombre);
                    cout << "\nINGRESE LA NOTA 1 DEL ALUMNO A INSERTAR: ";
                    cin >> o->inf.nota[0];
                    cout << "\nINGRESE LA NOTA 2 DEL ALUMNO A INSERTAR: ";
                    cin >> o->inf.nota[1];
                    o->inf.prom = (o->inf.nota[0] + o->inf.nota[1]) / 2;
                if (r == p)
                {
                    p = o;
                }
                else
                {
                    q->sig = o;
                }
                o->sig = r;
            }
            else
            {
                cout << "\nEL DATO REFERENCIA NO EXISTE";
            }
            cout << "\n\n\t\t\tMAS DATOS (S/N): ";
            cin >> op;
        }
        else
        {
            cout << "\nLA LISTA ESTA VACIA" << endl;
            system("pause");
        }
    } while ((op == 's') || (op == 'S'));
    return (p);
}

nodo *crear_d(nodo *p)
{
    nodo *q, *x;
    char op;
    do
    {
        if (p != NULL)
        {
            system("cls");
            q = p;
            int cen = 0;
            string ref;
            cout << "\nINGRESE EL CODIGO DEL ALUMNO REFERENCIA: ";
            fflush(stdin);
            getline(cin, ref);
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
                    cout << "\nINGRESE EL CODIGO DEL ALUMNO A INSERTAR: ";
                    fflush(stdin);
                    getline(cin, x->inf.codigo);
                    cout << "\nINGRESE LOS APELLIDOS Y NOMBRES DEL ALUMNO A INSERTAR: ";
                    fflush(stdin);
                    getline(cin, x->inf.nombre);
                    cout << "\nINGRESE LA NOTA 1 DEL ALUMNO A INSERTAR: ";
                    cin >> x->inf.nota[0];
                    cout << "\nINGRESE LA NOTA 2 DEL ALUMNO A INSERTAR: ";
                    cin >> x->inf.nota[1];
                    x->inf.prom = (x->inf.nota[0] + x->inf.nota[1]) / 2;
                x->sig = q->sig;
                q->sig = x;
            }
            else
            {
                cout << "\nEL DATO REFERENCIA NO EXISTE";
            }
            cout << "\n\n\t\t\tMAS DATOS (S/N): ";
            cin >> op;
        }
        else
        {
            cout << "\nLA LISTA ESTA VACIA" << endl;
            system("pause");
        }
    } while ((op == 's') || (op == 'S'));
    return (p);
}

nodo *eliminar_p(nodo *p)
{
    nodo *q;
    char op;
    do
    {
        if (p != NULL)
        {
            system("cls");
            q = p;
            p = p->sig;
            delete(q);
            cout << "\n\n\t\t\tELIMINAR DENUEVO (S/N): ";
            cin >> op;
        }
        else
        {
            cout << "\nLA LISTA ESTA VACIA" << endl;
            system("pause");
        }
    } while ((op == 's') || (op == 'S'));
    return (p);
}

nodo *eliminar_u(nodo *p)
{
    nodo *q, *r;
    char op;
    do
    {
        if (p != NULL)
        {
            system("cls");
            q = p;
            while (q->sig != NULL)
            {
               r = q;
               q = q->sig; 
            }
            if (q == p)
            {
                p = NULL;
            }
            else
            {
                r->sig = NULL;
            }
            delete(q);
            cout << "\n\n\t\t\tELIMINAR DENUEVO (S/N): ";
            cin >> op;
        }
        else{
            cout << "\nLA LISTA ESTA VACIA" << endl;
            system("pause");
        }
    } while ((op == 's') || (op == 'S'));
    return (p);
}

nodo *eliminar(nodo *p)
{
    nodo *q, *r;
    char op;
    do
    {
        if (p != NULL)
        {
            system("cls");
            q = p;
            int cen = 0;
            string ref;
            cout << "\nINGRESE EL CODIGO DEL ALUMNO A ELIMINAR: ";
            fflush(stdin);
            getline(cin, ref);
            while ((q->inf.codigo != ref) && (cen == 0))
            {
                if (q->sig != NULL)
                {
                    r = q;
                    q = q->sig;
                }
                else
                {
                    cen = 1;
                }
            }
            if (cen == 0)
            {
                if (q == p)
                {
                    p = q->sig;
                }
                else
                {
                    r->sig = q->sig;
                }
                delete(q);
            }
            else
            {
                cout << "\nEL DATO A ELIMINAR NO EXISTE";
            }
            cout << "\n\n\t\t\tELIMINAR MAS DATOS(S/N): ";
            cin >> op;
        }
        else
        {
            cout << "\nLA LISTA ESTA VACIA" << endl;
            system("pause");
        }
    } while ((op == 's') || (op == 'S'));   
    return (p);
}

nodo *eliminar_ant(nodo *p)
{
    nodo *q, *r, *s;
    char op;
    do
    {
        if (p != NULL)
        {
            system("cls");
            q = p;
            r = q;
            int cen = 0;
            string ref;
            cout << "\nINGRESE EL CODIGO DEL ALUMNO REFERENCIA: ";
            fflush(stdin);
            getline(cin, ref);
            while ((q->inf.codigo != ref) && (cen == 0))
            {
                if (q->sig != NULL)
                {
                    s = r;
                    r = q;
                    q = q->sig;
                }
                else
                {
                    cen = 1;
                }
            }
            if (cen == 0)
            {
                if (p != q)
                {
                    if (p = r)
                    {
                        p = q;
                    }
                    else
                    {
                        s->sig = q;
                    }
                    delete(r);
                }
                else
                {
                    cout << "\nNO EXISTE DATO ANTERIOR AL DATO REFERENCIAL";
                }
            }
            else
            {
                cout << "\nEL DATO REFERENCIAL NO EXISTE";
            }
            cout << "\n\n\t\t\tELIMINAR MAS DATOS(S/N): ";
            cin >> op;
        }
        else
        {
            cout << "\nLA LISTA ESTA VACIA" << endl;
            system("pause");
        }
    } while ((op == 's') || (op == 'S'));
    return (p);
}

nodo *eliminar_des(nodo *p)
{
    nodo *q, *r;
    char op;
    do
    {
        if (p != NULL)
        {
            system("cls");
            q = p;
            int cen = 0;
            string ref;
            cout << "\nINGRESE EL CODIGO DEL ALUMNO REFERENCIA: ";
            fflush(stdin);
            getline(cin, ref);
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
                r = q->sig;
                if (r != NULL)
                {
                    q->sig = r->sig;
                    delete(r);
                }
                else
                {
                    cout << "\nNO EXISTE DATO DESPUES DEL DATO REFERENCIAL";
                }
            }
            else
            {
                cout << "\nEL DATO REFERENCIAL NO EXISTE";
            }
            cout << "\n\n\t\t\tELIMINAR MAS DATOS(S/N): ";
            cin >> op;
        }
        else
        {
            cout << "\nLA LISTA ESTA VACIA" << endl;
            system("pause");
        }
    } while ((op == 's') || (op == 'S'));
    return (p);
}

nodo *modificar(nodo *p)
{
    nodo *q;
    char op;
    do
    {
        if (p != NULL)
        {
            system("cls");
            q = p;
            string ref;
            int cen = 0, opc;
            cout << "\nINGRESE EL CODIGO DEL ALUMNO A MODIFICAR: ";
            fflush(stdin);
            getline(cin, ref);
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
                do
                {
                    cout << "\nSELECCIONE EL DATO DEL ALUMNO A MODIFICAR:";
                    cout << "\n1. CODIGO";
                    cout << "\n2. APELLIDOS Y NOMBRES";
                    cout << "\n3. NOTA 1";
                    cout << "\n4. NOTA 2";
                    
                    cout << "\n\n\t\t\tOPCION:  ";
                    cin >> opc;
                    switch (opc)
                    {
                    case 1:
                        cout << "\nINGRESE EL CODIGO DEL ALUMNO MODIFICADO: ";
                        fflush(stdin);
                        getline(cin, q->inf.codigo);
                        break;
                    case 2:
                        cout << "\nINGRESE LOS APELLIDOS Y NOMBRES DEL ALUMNO MODIFICADO: ";
                        fflush(stdin);
                        getline(cin, q->inf.nombre);
                        break;
                    case 3:
                        cout << "\nINGRESE LA NOTA 1 DEL ALUMNO MODIFICADO: ";
                        cin >> q->inf.nota[0];
                        q->inf.prom = (q->inf.nota[0] + q->inf.nota[1]) / 2;
                        break;
                    case 4:
                        cout << "\nINGRESE LA NOTA 2 DEL ALUMNO MODIFICADO: ";
                        cin >> q->inf.nota[1];
                        q->inf.prom = (q->inf.nota[0] + q->inf.nota[1]) / 2;
                        break;
                    default:
                        cout << "\nINGRESE UNA DE LAS OPCIONES MOSTRADAS";
                        break;
                    }
                } while ((opc > 0) || (opc < 5));
            }
            else
            {
                cout << "\nEL DATO A MODIFICAR NO EXISTE";
            }
            cout << "\n\n\t\t\tMODIFICAR MAS DATOS(S/N): ";
            cin >> op;
        }
        else
        {
            cout << "\nLA LISTA ESTA VACIA" << endl;
            system("pause");
        }
    } while ((op == 's') || (op == 'S'));
    return (p);
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