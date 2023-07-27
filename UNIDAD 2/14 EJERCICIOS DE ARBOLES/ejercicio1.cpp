#include <iostream>
#include <string>

using namespace std;

struct ABB
{
    int inf;
    ABB *der;
    ABB *izq;
};

void insertar(ABB *&raiz, int &cont, int dato);

int main()
{
    ABB *raiz;
    raiz = NULL;
    int cont = 0, op, dato;
    do
    {
        system("cls");
        cout << "\n\n\t\tMENU" << endl << endl;
        cout << "1. INSERTAR" << endl;
        cout << "2. CONTAR NUMERO DE NODOS" << endl;
        cout << "3. SALIR" << endl;
        cout << "\n\t\tOPCION: ";
        cin >> op;
        switch (op)
        {
        case 1:
            system("cls");
            cout << "INGRESE EL DATO: ";
            cin >> dato;
            insertar(raiz, cont, dato);
            cout << endl << endl;
            system("pause");
            break;
        
        case 2:
            system("cls");
            cout << "EL NUMERO TOTAL DE NODOS QUE TIENE EL ARBOL ES: " << cont << endl << endl;
            system("pause");
            break;

        default:
            cout << "\n\t\tCERRANDO PROGRAMA" << endl << endl;
            system("pause");
            system("cls");
            break;
        }
    } while ((op > 0) && (op < 3));
    return 0;
}

void insertar(ABB *&raiz, int &cont, int dato)
{
    ABB *q;
    if (raiz != NULL)
    {
        if (dato < raiz->inf)
        {
            insertar(raiz->izq, cont, dato);
        }
        else
        {
            if (dato > raiz->inf)
            {
                insertar(raiz->der, cont, dato);
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
        cont++;
    }
}