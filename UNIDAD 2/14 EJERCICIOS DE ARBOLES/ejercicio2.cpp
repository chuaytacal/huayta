#include <iostream>
#include <string>

using namespace std;

struct ABB
{
    int inf;
    int altura;
    ABB *der;
    ABB *izq;
};

void insertar(ABB *&raiz, int altura, int dato);
int altura_a(ABB *&raiz, int &altura);
void hojas(ABB *&raiz, int &hoja);
void nodos_interiores(ABB *&raiz, int &ni);

int main()
{
    ABB *raiz;
    raiz = NULL;
    int altura = 0, altura1 = 0, hoja = 0, ni = 0, op, dato;
    do
    {
        system("cls");
        cout << "\n\n\t\tMENU" << endl << endl;
        cout << "1. INSERTAR" << endl;
        cout << "2. ALTURA DE UN ARBOL" << endl;
        cout << "3. DIFERENCIA DE ALTURAS ENTRE RAMA IZQUIERDA Y DERECHA" << endl;
        cout << "4. NODOS HOJAS" << endl;
        cout << "5. NODOS INTERIORES" << endl;
        cout << "6. SALIR" << endl;
        cout << "\n\t\tOPCION: ";
        cin >> op;
        switch (op)
        {
        case 1:
            system("cls");
            cout << "INGRESE EL DATO: ";
            cin >> dato;
            insertar(raiz, 0, dato);
            cout << endl << endl;
            system("pause");
            break;
        
        case 2:
            system("cls");
            cout << "LA ALTURA DEL ARBOL ES: " << altura_a(raiz, altura) << endl << endl;
            system("pause");
            break;

        case 3:
            system("cls");
            altura = 0; 
            altura1 = 0;
            cout << "LA DIFERENCIA DE ALTURAS ENTRE LA RAMA IZQUIERDA Y LA RAMA DERECHA ES: ";
            cout << altura_a(raiz->izq, altura) - altura_a(raiz->der, altura1) << endl << endl;
            cout << endl << endl;
            system("pause");
            break;

        case 4:
            system("cls");
            cout << endl;
            hojas(raiz, hoja);
            cout << "\nEL NUMERO TOTAL DE HOJAS DEL ARBOL ES: " << hoja << endl << endl;
            system("pause");
            break;
        
        case 5:
            system("cls");
            cout << endl;
            nodos_interiores(raiz, ni);
            cout << "\nEL NUMERO TOTAL DE NODOS INTERIORES DEL ARBOL ES: " << ni << endl << endl;
            system("pause");
            break;

        default:
            cout << "\n\t\tCERRANDO PROGRAMA" << endl << endl;
            system("pause");
            system("cls");
            break;
        }
    } while ((op > 0) && (op < 6));
    return 0;
}

void insertar(ABB *&raiz, int altura, int dato)
{
    ABB *q;
    if (raiz != NULL)
    {
        if (dato < raiz->inf)
        {
            insertar(raiz->izq, raiz->altura, dato);
        }
        else
        {
            if (dato > raiz->inf)
            {
                insertar(raiz->der, raiz->altura, dato);
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
        q->altura = altura + 1;
        q->inf = dato;
        q->izq = NULL;
        q->der = NULL;
        raiz = q;
    }
}

int altura_a(ABB *& raiz, int &altura)
{
    if(raiz != NULL)
    {
        if ((raiz->izq == NULL) && (raiz->der == NULL))
        {
            int altura1 = raiz->altura;
            if (altura1 >= altura)
            {
                altura = altura1;
            }
        }
        altura_a(raiz->izq, altura);
        altura_a(raiz->der, altura);
    }
    return altura;
}

void hojas(ABB *&raiz, int &hoja)
{
    if(raiz != NULL)
    {
        if ((raiz->izq == NULL) && (raiz->der == NULL))
        {
            hoja++;
            cout << "LA HOJA NUMERO " << hoja << " ES: " << raiz->inf << endl;
        }
        hojas(raiz->izq, hoja);
        hojas(raiz->der, hoja);
    }
}

void nodos_interiores(ABB *&raiz, int &ni)
{
    if(raiz != NULL)
    {
        if ((raiz->izq != NULL) || (raiz->der != NULL))
        {
            ni++;
            cout << "EL NODO INTERIOR NUMERO " << ni << " ES: " << raiz->inf << endl;
        }
        nodos_interiores(raiz->izq, ni);
        nodos_interiores(raiz->der, ni);
    }
}