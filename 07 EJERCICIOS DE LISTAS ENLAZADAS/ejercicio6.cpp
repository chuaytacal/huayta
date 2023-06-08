#include <iostream>

using namespace std;

struct nodo
{
    int inf;
    nodo *sig;
};

void entrelazado(nodo *p, nodo *q);

int main()
{
    nodo *p, *q, *r, *t;
    char op;
    p = NULL;
    q = NULL;
    do
    {
        r = new(nodo);
        cout << "INGRESE EL DATO PARA LA PRIMERA LISTA: ";
        cin >> r->inf;
        r->sig = NULL;
        if (p == NULL)
        {
            p = r;
        }
        else
        {
            t = p;
            while (t->sig != NULL)
            {
                t = t->sig;
            }
            t->sig = r;
        }
        cout << "MAS DATOS (S/N): ";
        cin >> op;
    } while (op == 's' || op == 'S');
    system("cls");
    do
    {
        r = new(nodo);
        cout << "INGRESE EL DATO PARA LA SEGUNDA LISTA: ";
        cin >> r->inf;
        r->sig = NULL;
        if (q == NULL)
        {
            q = r;
        }
        else
        {
            t = q;
            while (t->sig != NULL)
            {
                t = t->sig;
            }
            t->sig = r;
        }
        cout << "MAS DATOS (S/N): ";
        cin >> op;
    } while (op == 's' || op == 'S');
    system("cls");
    r = p;
    t = q;
    cout << "\nLISTA 1 INICIAL: " << endl;
    while (r != NULL)
    {
        cout << r->inf << "\t";
        r = r->sig;
    }
    cout << "\nLISTA 2 INICIAL: " << endl;
    while (t != NULL)
    {
        cout << t->inf << "\t";
        t = t->sig;
    }
    entrelazado(p, q);
    return 0;
}

void entrelazado(nodo *p, nodo *q)
{
    nodo *r, *t, *o;
    r = p;
    t = q;
    while ((r->sig != NULL) || (t->sig != NULL))
    {
        if ((r->sig != NULL) && (t->sig != NULL))
        {
            if (r == p)
            {
                p = t;
                q = r;
            }
            else
            {
                o = r->sig;
                r->sig = t->sig;
                t->sig = o;
                r = r->sig;
                t = t->sig;
            }
        }
        else if (r->sig == NULL)
        {
            r->sig = t->sig;
            t->sig = NULL;
            while (r->sig != NULL)
            {
                r = r->sig;
            }
        }
        else if (t->sig == NULL)
        {
            t->sig = r->sig;
            r->sig = NULL;
            while (t->sig != NULL)
            {
                t = t->sig;
            }
        }
    }
    r = p;
    t = q;
    cout << "\nLISTA 1 FINAL: " << endl;
    while (r != NULL)
    {
        cout << r->inf << "\t";
        r = r->sig;
    }
    cout << "\nLISTA 2 FINAL: " << endl;
    while (t != NULL)
    {
        cout << t->inf << "\t";
        t = t->sig;
    }
}