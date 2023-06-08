#include <iostream>
#include <string>
#include <math.h>
#include "polinomios.h"

using namespace std;

struct Nodo
{
    Polinomio inf;
    Nodo *sig;
};

Nodo *Creacion(Nodo *p);
Nodo *Info();
Nodo *Suma(Nodo *p, Nodo *q);
Nodo *Resta(Nodo *p, Nodo *q);
Nodo *Multiplicacion(Nodo *p, Nodo *q);
void Division(Nodo *p, Nodo *q);
Nodo *Derivada(Nodo *p);
int Grado(Nodo *p);
float Evaluacion_p(Nodo *p, float x);
void Mostrar(Nodo *p);
Nodo *Eliminar0(Nodo *p);

Nodo *Creacion(Nodo *p)
{
    Nodo *x, *r, *s;
    x = new(Nodo);
    r = new(Nodo);
    s = new(Nodo);
    int cen;
    char op;
    do
    {
        x = Info();
        if ((p == NULL) || (x->inf.exponente > p->inf.exponente))
        {
            x->sig = p;
            p = x;
        }
        else
        {
            r = p;
            cen = 0;
            while ((x->inf.exponente < r->inf.exponente) && (cen == 0))
            {
                if (r->sig != NULL)
                {
                    s = r;
                    r = r->sig;
                }
                else
                {
                    cen = 1;
                }
            }
            if (cen == 0)
            {
                if (r->inf.exponente == x->inf.exponente)
                {
                    r->inf.coeficiente = r->inf.coeficiente + x->inf.coeficiente;
                    delete(x);
                }
                else
                {
                    x->sig = r;
                    s->sig = x;
                }
            }
            else
            {
                r->sig = x;
                x->sig = NULL;
            }
        }
        cout << "\n\n\t\t\tAGREGAR OTRO TERMINO (S/N): ";
        cin >> op;
    } while ((op == 'S') || (op == 's'));
    cout << "\n\n\t\t\tEL POLINOMIO ES: ";
    r = p;
    Mostrar(r);
    cout << endl << endl;
    system("pause");
    system("cls");
    return (p);
}

Nodo *Info(){
    Nodo *x;
    double verif;
    int verif1;

    do
    {
        x = new(Nodo);
        
        cout << "\nINGRESE EL COEFICIENTE DEL TERMINO: ";
        cin >> x->inf.coeficiente;
        if (x->inf.coeficiente < 0)
        {
            x->inf.signo = '-';
        }
        else if (x->inf.coeficiente == 0)
        {
            cout << "\n\n\t\t\tEL COEFICIENTE NO PUEDE SER 0, INGRESE OTRO NUMERO" << endl << endl;
            system("pause");
        }
        else
        {
            x->inf.signo = '+';
        }
    } while (x->inf.coeficiente == 0);
    do
    {
        cout << "\nINGRESE EL EXPONENTE DEL TERMINO: ";
        cin >> x->inf.exponente;
        verif1 = x->inf.exponente;
        verif = x->inf.exponente - verif1;
        if ((x->inf.exponente < 0) || (verif != 0))
        {
            cout << "\n\n\t\t\tEL EXPONENTE NO PUEDE SER MENOR A '0' O DECIMAL, INGRESE OTRO NUMERO" << endl << endl;
            system("pause");
        }
    } while ((x->inf.exponente < 0) || (verif != 0));
    x->sig = NULL;
    system("cls");
    return (x);
}

Nodo *Suma(Nodo *p, Nodo *q)
{
    Nodo *r, *s, *t, *o, *u;
    r = p;
    s = q;
    o = new(Nodo);
    o = NULL;
    while ((r != NULL) || (s != NULL))
    {
        if ((r != NULL) && (s != NULL))
        {
            t = new(Nodo);
            if (r->inf.exponente > s->inf.exponente)
            {
                t->inf.coeficiente = r->inf.coeficiente;
                t->inf.exponente = r->inf.exponente;
                if (t->inf.coeficiente < 0)
                {
                    t->inf.signo = '-';
                }
                else
                {
                    t->inf.signo = '+';
                }
                r = r->sig;
            }
            else if (r->inf.exponente < s->inf.exponente)
            {
                t->inf.coeficiente = s->inf.coeficiente;
                t->inf.exponente = s->inf.exponente;
                if (t->inf.coeficiente < 0)
                {
                    t->inf.signo = '-';
                }
                else
                {
                    t->inf.signo = '+';
                }
                s = s->sig;
            }
            else
            {
                t->inf.coeficiente = r->inf.coeficiente + s->inf.coeficiente;
                t->inf.exponente = r->inf.exponente;
                if (t->inf.coeficiente < 0)
                {
                    t->inf.signo = '-';
                }
                else
                {
                    t->inf.signo = '+';
                }
                s = s->sig;
                r = r->sig;
            }
        }
        else if (r == NULL)
        {
            t = new(Nodo);
            t->inf.coeficiente = s->inf.coeficiente;
            t->inf.exponente = s->inf.exponente;
            if (t->inf.coeficiente < 0)
            {
                t->inf.signo = '-';
            }
            else
            {
                t->inf.signo = '+';
            }
            s = s->sig;
        }
        else if (s == NULL)
        {
            t = new(Nodo);
            t->inf.coeficiente = r->inf.coeficiente;
            t->inf.exponente = r->inf.exponente;
            if (t->inf.coeficiente < 0)
            {
                t->inf.signo = '-';
            }
            else
            {
                t->inf.signo = '+';
            }
            r = r->sig;
        }
        
        t->sig = NULL;
        if (o == NULL)
        {
            o = t;
        }
        else
        {
            u = o;
            while (u->sig != NULL)
            {
                u = u->sig;
            }
            u->sig = t;
        }
    }
    r = o;
    while (r != NULL)
    {
        o = Eliminar0(o);
        r = r->sig;
    }
    return (o);
}

Nodo *Resta(Nodo *p, Nodo *q)
{
    Nodo *r, *s, *t, *o, *u;
    r = p;
    s = q;
    o = new(Nodo);
    o = NULL;
    while ((r != NULL) || (s != NULL))
    {
        if ((r != NULL) && (s != NULL))
        {
            t = new(Nodo);
            if (r->inf.exponente > s->inf.exponente)
            {
                t->inf.coeficiente = r->inf.coeficiente;
                t->inf.exponente = r->inf.exponente;
                if (t->inf.coeficiente < 0)
                {
                    t->inf.signo = '-';
                }
                else
                {
                    t->inf.signo = '+';
                }
                r = r->sig;
            }
            else if (r->inf.exponente < s->inf.exponente)
            {
                t->inf.coeficiente = s->inf.coeficiente;
                t->inf.exponente = s->inf.exponente;
                if (t->inf.coeficiente < 0)
                {
                    t->inf.signo = '-';
                }
                else
                {
                    t->inf.signo = '+';
                }
                s = s->sig;
            }
            else
            {
                t->inf.coeficiente = r->inf.coeficiente - s->inf.coeficiente;
                t->inf.exponente = r->inf.exponente;
                if (t->inf.coeficiente < 0)
                {
                    t->inf.signo = '-';
                }
                else
                {
                    t->inf.signo = '+';
                }
                s = s->sig;
                r = r->sig;
            }
        }
        else if (r == NULL)
        {
            t = new(Nodo);
            t->inf.coeficiente = s->inf.coeficiente;
            t->inf.exponente = s->inf.exponente;
            if (t->inf.coeficiente < 0)
            {
                t->inf.signo = '-';
            }
            else
            {
                t->inf.signo = '+';
            }
            s = s->sig;
        }
        else if (s == NULL)
        {
            t = new(Nodo);
            t->inf.coeficiente = r->inf.coeficiente;
            t->inf.exponente = r->inf.exponente;
            if (t->inf.coeficiente < 0)
            {
                t->inf.signo = '-';
            }
            else
            {
                t->inf.signo = '+';
            }
            r = r->sig;
        }
        
        t->sig = NULL;
        if (o == NULL)
        {
            o = t;
        }
        else
        {
            u = o;
            while (u->sig != NULL)
            {
                u = u->sig;
            }
            u->sig = t;
        }
    }
    o = Eliminar0(o);
    r = o;
    while (r != NULL)
    {
        o = Eliminar0(o);
        r = r->sig;
    }
    return (o);
}

Nodo *Multiplicacion(Nodo *p, Nodo *q)
{
    Nodo *r, *s, *t, *o, *u, *suma;
    r = p;
    suma = new(Nodo);
    suma->inf.coeficiente = 0;
    suma->inf.exponente = 0;
    while (r != NULL)
    {
        s = q;
        o = NULL;
        while (s != NULL)
        {
            t = new(Nodo);
            t->inf.coeficiente = r->inf.coeficiente * s->inf.coeficiente;
            t->inf.exponente = r->inf.exponente + s->inf.exponente;
            if (t->inf.coeficiente < 0)
            {
                t->inf.signo = '-';
            }
            else
            {
                t->inf.signo = '+';
            }
            t->sig = NULL;
            if (o == NULL)
            {
                o = t;
            }
            else
            {
                u = o;
                while (u->sig != NULL)
                {
                    u = u->sig;
                }
                u->sig = t;
            }
            s = s->sig;
        }
        suma = Suma(suma, o);
        r = r->sig;
    }
    r = suma;
    while (r != NULL)
    {
        suma = Eliminar0(suma);
        r = r->sig;
    }
    return (suma);
}

void Division(Nodo *p, Nodo *q)
{
    Nodo *r, *s, *t, *o, *u, *v, *cociente, *aux;
    r = p;
    o = NULL;
    while (r != NULL)
    {
        v = new(Nodo);
        v->inf.coeficiente = r->inf.coeficiente;
        v->inf.exponente = r->inf.exponente;
        v->inf.signo = r->inf.signo;
        v->sig = NULL;
        if (o == NULL)
        {
            o = v;
        }
        else
        {
            u = o;
            while (u->sig != NULL)
            {
                u = u->sig;
            }
            u->sig = v;
        }
        r = r->sig;
    }
    s = q;
    cociente = NULL;
    while (o->inf.exponente >= s->inf.exponente)
    {
        v = new(Nodo);
        t = new(Nodo);
        t->inf.coeficiente = o->inf.coeficiente / s->inf.coeficiente;
        t->inf.exponente = o->inf.exponente - s->inf.exponente;
        
        v->inf.coeficiente = o->inf.coeficiente / s->inf.coeficiente;
        v->inf.exponente = o->inf.exponente - s->inf.exponente;
        if (v->inf.coeficiente < 0)
        {
            v->inf.signo = "-";
        }
        else
        {
            v->inf.signo = "+";
        }

        t = Multiplicacion(t, s);
        aux = t;
        while (aux != NULL)
        {
            aux->inf.coeficiente = aux->inf.coeficiente * (-1);
            if (aux->inf.signo == "-")
            {
                aux->inf.signo = "+";
            }
            else if (aux->inf.signo == "+")
            {
                aux->inf.signo = "-";
            }
            aux = aux->sig;
        }
        o = Suma(o, t);
        v->sig = NULL;
        if (cociente == NULL)
        {
            cociente = v;
        }
        else
        {
            u = cociente;
            while (u->sig != NULL)
            {
                u = u->sig;
            }
            u->sig = v;
        }
    }
    cout << "\n\n\t\t\tP(x) / Q(x) = ";
    Mostrar(cociente);
    cout << "\n\n\t\t\tRESTO DE LA DIVISION = ";
    Mostrar(o);
    cout << endl << endl;
    system("pause");
    system("cls");
}

Nodo *Derivada(Nodo *p)
{
    Nodo *r, *s, *t, *u;
    r = p;
    t = NULL;
    while (r != NULL)
    {
        s = new(Nodo);
        s->inf.coeficiente = r->inf.coeficiente * r->inf.exponente;
        s->inf.exponente = r->inf.exponente-1;
        if (s->inf.coeficiente < 0)
        {
            s->inf.signo = '-';
        }
        else
        {
            s->inf.signo = '+';
        }
        s->sig = NULL;
        if (t == NULL)
        {
            t = s;
        }
        else
        {
            u = t;
            while (u->sig != NULL)
            {
                u = u->sig;
            }
            u->sig = s;
        }
        r = r->sig;
    }
    r = t;
    while (r != NULL)
    {
        t = Eliminar0(t);
        r = r->sig;
    }
    return (t);
}

int Grado(Nodo *p)
{
    return p->inf.exponente;
}

float Evaluacion_p(Nodo *p, float x)
{
    Nodo *r;
    float suma = 0;
    r = p;
    while (r != NULL)
    {
        suma = suma + (r->inf.coeficiente * (pow(x, r->inf.exponente)));
        r = r->sig;
    }
    return suma;
}

void Mostrar(Nodo *p)
{
    while (p != NULL)
    {
        cout << p->inf.signo << " ";
        if (p->inf.coeficiente < 0)
        {
            cout << p->inf.coeficiente * (-1);
        }
        else
        {
            cout << p->inf.coeficiente;
        }

        cout << "x^" << p->inf.exponente << " ";
        p = p->sig;
    }
}

Nodo *Eliminar0(Nodo *p)
{
    Nodo *q, *r;
    int cen = 0;
    q = p;
    while((q->inf.coeficiente != 0) && (cen == 0))
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
            p = p->sig;
        }
        else
        {
            r->sig = q->sig;
        }
          delete(q);
    }
    return (p);
}