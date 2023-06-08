#include <iostream>
#include <string.h>

using namespace std;

struct nodo
{
    char inf;
    nodo *sig;
};

char operando(char x);
int prioridad(char x);
nodo *insertar(nodo *pila, char inf);
nodo *eliminar(nodo *pila);

int main()
{
    int n, j, tope;
    char ei[100], op;
    cout << "\n\n\t\t\tEXPREION INFIJA: ";
    cin >> ei;
    n = strlen(ei);
    for (int i = 0; i < n; i++)
    {
        if ((ei[i] != ('(' || ')' || '+' || '-' || '*' || '/' || '^')))
        {
            /* code */
        }
        
    }
    
    
    return 0;
}

char operando(char x)
{
    switch (x)
    {
        case '+':
            return 'n';
            break;
        case '-':
            return 'n';
            break;
        case '*':
            return 'n';
            break;
        case '/':
            return 'n';
            break;
        case '^':
            return 'n';
            break;
        default:
            return x;
            break;
    }
}

int prioridad(char x)
{
    switch (x)
    {
        case '+':
            return (1);
            break;
        case '-':
            return (1);
            break;
        case '*':
            return (2);
            break;
        case '/':
            return (2);
            break;
        case '^':
            return (3);
            break;
        default:
            return (0);
    }
}

nodo *insertar(nodo *pila, char inf)
{
    nodo *q, *r;
    q = new(nodo);
    q->inf = inf;
    q->sig = NULL;
    if (pila == NULL)
    {
        pila = q;
    }
    else
    {
        r = pila;
        while (r->sig != NULL)
        {
            r = r->sig;
        }
        r->sig = q;
    }
    return (pila);
}

nodo *eliminar(nodo *pila)
{
    nodo *q, *r;
    q = pila;
    if (pila != NULL)
    {
        while (q->sig != NULL)
        {
            r = q;
            q = q->sig;
        }
        r->sig = NULL;
        delete (q);
    }
    return (pila);
}