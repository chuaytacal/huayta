#include <iostream>

using namespace std;

struct nodo
{
    int inf;
    nodo *sig;
};

nodo *insertarc_i(nodo *p);
nodo *insertarc_f(nodo *p);
nodo *insertarc_ad(nodo *p, int ref);
nodo *insertarc_dd(nodo *p, int ref);
nodo *eliminarc_i(nodo *p);
nodo *eliminarc_f(nodo *p);
nodo *eliminarc_ad(nodo *p, int ref);
nodo *eliminarc_dd(nodo *p, int ref);
nodo *eliminarc_e(nodo *p, int ref);
nodo *imprimir(nodo *p);

nodo *insertarc_i(nodo *p)
{
    nodo *q, *r;
    q = new(nodo);
    cout << "Ingrese el dato: ";
    cin >> q->inf;
    q->sig = p;
    p = q;
    r = p;
    while (r->sig != p)
    {
        r = r->sig;
    }
    r->sig = p;
    return (p);
}
nodo *insertarc_f(nodo *p)
{
    nodo *q, *r;
    q = new(nodo);
    cout << "Ingrese el dato: ";
    cin >> q->inf;
    if (p == NULL)
    {
        p = q;
        p->sig = p;
    }
    else
    {
        r = p;
        while (r->sig != p)
        {
            r = r->sig;
        }
        r->sig = q;
        q->sig = p;
    }
    return (p);
}

nodo *insertarc_ad(nodo *p, int ref)
{
    nodo *q, *r, *x;
    int cen;
    if (p != NULL)
    {
        q = p;
        cen = 0;
        while ((q->inf != ref) && (cen == 0))
        {
            if (q->sig != p)
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
            x = new(nodo);
            cout << "Ingrese el dato a insertar: ";
            cin >> x->inf;
            x->sig = q;
            if (q == p)
            {
                p = x;
            }
            else
            {
                r->sig = x;
            }
        }
        else
        {
            cout << "El dato referencial no existe" << endl;
        }
    }
    else
    {
        cout << "\n\nLISTA VACIA" << endl;
    }
    return (p);
}

nodo *insertarc_dd(nodo *p, int ref)
{
    nodo *q, *r, *x;
    int cen;
    if (p != NULL)
    {
        q = p;
        cen = 0;
        while ((q->inf != ref) && (cen == 0))
        {
            if (q->sig != p)
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
            cout << "Ingrese el dato a ingresar: ";
            cin >> x->inf;
            x->sig = q->sig;
            q->sig = x;
        }
        else
        {
            cout << "El dato referencial no existe" << endl;
        }
    }
    else
    {
        cout << "La lista está vacia" << endl;
    }
    return (p);
}

nodo *eliminarc_i(nodo *p)
{
    nodo *q, *r;
    if (p != NULL)
    {
        q = p;
        r = p;
        while (r->sig != p)
        {
            r = r->sig;
        }
        p = p->sig;
        r->sig = p;
        delete(q);
    }
    else
    {
        cout << "La lista esta vacia" << endl;
    }
    return (p);
}

nodo *eliminarc_f(nodo *p)
{
    nodo *q, *r;
    if (p != NULL)
    {
        q = p;
        while (q->sig != p)
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
            r->sig = q->sig;
        }
        delete(q);
    }
    else
    {
        cout << "La lista esta vacia" << endl;
    }
    return (p);
}

nodo *eliminarc_ad(nodo *p, int ref)
{
    nodo *q, *r, *s, *u;
    int cen;
    if (p != NULL)
    {
        q = p;
        r = q;
        cen = 0;
        while ((q->inf != ref) && (cen == 0))
        {
            if (q->sig != p)
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
            if (q != p)
            {
                if (r == p)
                {
                    u = p;
                    while (u->sig != p)
                    {
                        u = u->sig;
                    }
                    p = q;
                    u->sig = q;
                }
                else
                {
                    s->sig = q;
                }
                delete(r);
            }
            else
            {
                u = p;
                while (u->sig != p)
                {
                    r  = u;
                    u = u->sig;
                }
                r->sig = p;
                delete(u);
            }
        }
        else
        {
            cout << "El dato referencial no existe" << endl;
        }
        
    }
    else
    {
        cout << "La lista esta vacia" << endl;
    }
}

nodo *eliminarc_dd(nodo *p, int ref)
{

}

nodo *eliminarc_e(nodo *p, int ref)
{

}

nodo *imprimir(nodo *p)
{
    nodo *q = p;
    do
    {
        cout << q->inf << " ";
        q = q->sig;
    } while (q != p);
    cout << endl;
}