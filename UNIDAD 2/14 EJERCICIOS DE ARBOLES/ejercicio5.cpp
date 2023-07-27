#include <iostream>
#include <string>

using namespace std;

struct ABB
{
    int inf;
    ABB *der;
    ABB *izq;
};

void insertar(ABB *&raiz, int dato);
void mayor(ABB *&raiz, int &ma);
void menor(ABB *&raiz, int &me);
void preorden(ABB *raiz, int &i);

int main()
{
    ABB *raiz;
    raiz = NULL;
    int op, dato, ma, me, i;
    do
    {
        system("cls");
        cout << "\n\n\t\tMENU" << endl << endl;
        cout << "1. INSERTAR" << endl;
        cout << "2. PROMEDIO ENTRE LA CLAVE MENOR Y MAYOR" << endl;
        cout << "3. RECORRIDO" << endl;
        cout << "4. SALIR" << endl;
        cout << "\n\t\tOPCION: ";
        cin >> op;
        switch (op)
        {
        case 1:
            system("cls");
            cout << "INGRESE EL DATO: ";
            cin >> dato;
            insertar(raiz, dato);
            cout << endl << endl;
            system("pause");
            break;
        
        case 2:
            system("cls");
            ma = 0;
            mayor(raiz, ma);
            me = ma;
            menor(raiz, me);
            cout << "\n\nEL PROMEDIO ENTRE LA CLAVE MENOR Y MAYOR ES: " << (ma + me) / 2 << endl << endl;
            system("pause");
            break;

        case 3:
            i = 0;
            system("cls");
            preorden(raiz, i);
            cout <<  endl << endl;
            system("pause");
            break;

        default:
            cout << "\n\t\tCERRANDO PROGRAMA" << endl << endl;
            system("pause");
            system("cls");
            break;
        }
    } while ((op > 0) && (op < 4));
    return 0;
}

void insertar(ABB *&raiz, int dato)
{
    ABB *q;
    if (raiz != NULL)
    {
        if (dato < raiz->inf)
        {
            insertar(raiz->izq, dato);
        }
        else
        {
            if (dato > raiz->inf)
            {
                insertar(raiz->der, dato);
            }
            else
            {
                cout << "\n\n\tDATO REPETIDO" << endl;
            }
        }
    }
    else
    {
        q = new(ABB);
        q->inf = dato;
        q->izq = NULL;
        q->der = NULL;
        raiz = q;
    }
}

void mayor(ABB *&raiz, int &ma)
{
    if (raiz != NULL)
    {
        if (raiz->inf > ma)
        {
            ma = raiz->inf;
        }
        mayor(raiz->izq, ma);
        mayor(raiz->der, ma);
    }
}

void menor(ABB *&raiz, int &me)
{
    if (raiz != NULL)
    {
        if (raiz->inf < me)
        {
            me = raiz->inf;
        }
        menor(raiz->izq, me);
        menor(raiz->der, me);
    }
}

void preorden(ABB *raiz, int &i)
{
    if(raiz != NULL)
    {
        i++;
        cout << "NODO " << i << ": " << raiz->inf << "\t";
        preorden(raiz->izq, i);
        preorden(raiz->der, i);
    }
}