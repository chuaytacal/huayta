#include <iostream>
#include <cstdlib>
#include <string>
#include<time.h>

using namespace std;

struct soldado
{
    int cod;
    string nombre;
};

struct nodo
{
    soldado inf;
    nodo *sig;
};


int main()
{
    int x, random, num, cen = 0;
    nodo *p, *q, *r, *s;
    cout << "Ingrese el numero de soldados: ";
    cin >> x;
    p = NULL;
    for (int i = 0; i < x; i++)
    {
        q = new(nodo);
        cout << "Ingrese el nombre del soldado " << i + 1 << ": ";
        fflush(stdin);
        getline(cin, q->inf.nombre);
        q->inf.cod = i + 1;
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
    }
    srand(time(NULL));
    random = 1 + rand()%(5 - 1);
    cout << "\nEl numero escogido al azar es: " << random << endl;
    num = 1 + rand()%(x - 1);
    
    q = p;
    while (q->inf.cod != num)
    {
        r = q;
        q = q->sig;
    }

    cout << "El soldado escogido al azar es: " << q->inf.nombre << endl << endl;
    
    while (q->sig != q)
    {
        for (int i = 1; i <= random; i++)
        {
            if (i == random)
            {
                cout << "El soldado que es retirado del circulo es: " << q->inf.nombre << endl;
                s = q;
                if (q == p)
                {
                    p = p->sig;
                }
                q = q->sig;
                r->sig = s->sig;
                delete(s);
            }
            else
            {
                r = q;
                q = q->sig;
            }
        }
    }
    cout << "\nEl soldado que va a escapar es: " << q->inf.nombre << endl << endl;
    system("pause");
    return 0;
}