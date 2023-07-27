#include <iostream>
#include <string>

using namespace std;

struct Persona
{
    string nombre;
    int codigo;
};


struct Nodo
{
    Persona inf;
    int prioridad;
    Nodo *sig;
};

Nodo *insertar(Nodo *cola, Persona inf, int prio);
Nodo *eliminar(Nodo *cola);
void mostrar(Nodo *cola);

int main()
{
    int op;
    Nodo *cola;
    cola = NULL;
    Persona inf;
    int prio;
    do
    {
        system("cls");
        cout << "\n\n\t\tMENU" << endl;
        cout << "\n1. INSERTAR PERSONA" << endl;
        cout << "2. ELIMINAR PERSONA" << endl;
        cout << "3. MOSTRAR" << endl;
        cout << "4. SALIR" << endl;
        cout << "\n\t\tOPCION: ";
        cin >> op;
        switch (op)
        {
        case 1:
            system("cls");
            cout << "Ingrese el nombre de la persona: ";
            fflush(stdin);
            getline(cin, inf.nombre);
            cout << "Ingrese el codigo de la persona: ";
            cin >> inf.codigo;
            cout << "Ingrese la prioridad de la persona: ";
            cin >> prio;
            cola = insertar(cola, inf, prio);
            cout << endl << endl;
            system("pause");
            break;
        case 2:
            system("cls");
            cola = eliminar(cola);
            cout << endl << endl;
            system("pause");
            break;
        case 3:
            system("cls");
            mostrar(cola);
            cout << endl << endl;
            system("pause");
            break;
        default:
            cout << "\nCERRANDO PROGRAMA" << endl;
            system("pause");
            system("cls");
            break;
        } 
    } while ((op > 0) && op < 4);
    
    return 0;
}

Nodo *insertar(Nodo *cola, Persona inf, int prio)
{
    Nodo *q;
    q = new(Nodo);
    q->inf.codigo = inf.codigo;
    q->inf.nombre = inf.nombre;
    q->prioridad = prio;
    if (cola == NULL)
    {
        q->sig = NULL;
        cola = q;
    }
    else
    {
        Nodo *r, *s;
        r = cola;
        s = r;
        while ((r->sig != NULL))
        {
            if (s->sig->prioridad <= prio)
            {
                s = r;
            }
            r = r->sig;
        }
        r = s->sig;
        if (s->sig == NULL)
        {
            q->sig = s->sig;
            s->sig = q;
        }
        else
        {
            if ((r->sig == NULL))
            {
                if ((r->prioridad <= prio) && (s->prioridad <= prio))
                {
                    r->sig = q;
                    q->sig = NULL;
                }
                else
                {
                    q->sig = s->sig;
                    s->sig = q;
                }
            }
            else
            {
                q->sig = s->sig;
                s->sig = q;
            }
        }
        
    }
    return (cola);
}

Nodo *eliminar(Nodo *cola)
{
    if (cola == NULL)
    {
        Nodo *q;
        q = cola;
        cola = cola->sig;
        delete(q);
    }
    else
    {
        cout << "\nCOLA VACIA" << endl;
    }    
    return (cola);
}

void mostrar(Nodo *cola)
{
    Nodo *q;
    int i = 1;
    q = cola;
    cout << endl << endl;
    while (q != NULL)
    {
        cout << "PERSONA " << i << endl;
        cout << "\tNOMBRE: " << q->inf.nombre << endl;
        cout << "\tCODIGO: " << q->inf.codigo << endl;
        cout << "\tPRIORIDAD: " << q->prioridad << endl;
        cout << endl;
        i++;
        q = q->sig;
    }
}