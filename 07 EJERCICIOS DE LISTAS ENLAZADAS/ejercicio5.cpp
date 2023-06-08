#include <iostream>

using namespace std;

struct nodo
{
    int inf;
    nodo *sig;
};

int main()
{
    int cont = 0;
    char op;
    nodo *p, *q, *r, *s, *t, *u;
    p = NULL;
    do
    {
        q = new(nodo);
        cout << "INGRESE EL DATO DEL NODO: ";
        cin >> q->inf;
        q->sig = NULL;
        if (p == NULL)
        {
            p = q;
        }
        else
        {
            u = p;
            while (u->sig != NULL)
            {
                u = u->sig;
            }
            u->sig = q;
        }
        cont++;
        cout << "MAS DATOS (S/N): ";
        cin >> op;
    } while (op == 'S' || op == 's');
    
    q = p;
    cout << "\n\nLA LISTA INICIAL ES: " << endl;
    while (q != NULL)
    {
        cout << q->inf << "\t";
        q = q->sig;
    }
    q = p;
    r = NULL;
    s = NULL;
    int cen = 0;
    while (q != NULL)
    {
        if (cen == 0)
        {
            t = new(nodo);
            t->inf = q->inf;
            t->sig = NULL;
            if (r == NULL)
            {
                r = t;
            }
            else
            {
                u = r;
                while (u->sig != NULL)
                {
                    u = u->sig;
                }
                u->sig = t;
            }
            cen = 1;
        }
        else
        {
            t = new(nodo);
            t->inf = q->inf;
            t->sig = NULL;
            if (s == NULL)
            {
                s = t;
            }
            else
            {
                u = s;
                while (u->sig != NULL)
                {
                    u = u->sig;
                }
                u->sig = t;
            }
            cen = 0;
        }
        q = q->sig;
    }
    t = r;
    u = s;
    cout << "\n\nLA PRIMERA LISTA ENLAZADA ES: " << endl;
    while (t != NULL)
    {
        cout << t->inf << "\t";
        t = t->sig;
    }
    cout << "\n\nLA SEGUNDA LISTA ENLAZADA ES: " << endl;
    while (u != NULL)
    {
        cout << u->inf << "\t";
        u = u->sig;
    }

    return 0;
}