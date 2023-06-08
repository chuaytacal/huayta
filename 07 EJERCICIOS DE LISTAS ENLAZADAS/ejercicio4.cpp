#include <iostream>

using namespace std;

struct nodo
{
    int inf;
    nodo *sig;
};


int main()
{
    char op;
    nodo *p, *q, *r, *s, *o;
    p = NULL;
    do
    {
        q = new(nodo);
        cout << "\nINGRESE EL DATO DEL NODO: ";
        cin >> q->inf;
        q->sig = p;
        p = q;
        cout << "\nMAS DATOS (S/N): ";
        cin >> op;
    }while (op == 'S' || op == 's');
    cout << "LISTA ENLAZADA INICIAL: ";
    q = p;
    while (q != NULL)
    {
        cout << q->inf << ",  ";
        q = q->sig;
    }
    cout << endl;

    o = p;
    q = p;
    s = p->sig;
    if (s != NULL)
    {
        while (s->sig != NULL)
        {
            r = q;
            q = s;
            s = s->sig;
            q->sig = r;
        }
        s->sig = q;
        p = s;
        o->sig = NULL;
    }

    cout << "LISTA ENLAZADA FINAL: ";
    q = p;
    while (q != NULL)
    {
        cout << q->inf << ",  ";
        q = q->sig;
    }
    cout << endl;

    return 0;
}