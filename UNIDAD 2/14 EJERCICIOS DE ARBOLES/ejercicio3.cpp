#include <iostream>
#include <string>

using namespace std;

struct AVL
{
    int inf;
    int fe;
    AVL *izq;
    AVL *der;
};

void insertar_avl(AVL *&raiz, int clave, int &cen);
void preorden(AVL *raiz);

int main()
{
    int op, clave, cen = 0;
    AVL *raiz;
    raiz = NULL;
    do
    {
        system("cls");
        cout << "\n\n\t\tMENU" << endl << endl;
        cout << "1. INSERTAR" << endl;
        cout << "2. RECORRIDO" << endl;
        cout << "3. SALIR" << endl;
        cout << "\n\t\tOPCION: ";
        cin >> op;
        switch (op)
        {
        case 1:
            system("cls");
            cout << "\nINGRESE EL DATO: ";
            cin >> clave;
            insertar_avl(raiz, clave, cen);
            cout << endl << endl;
            system("pause");
            break;
        
        case 2:
            system("cls");
            preorden(raiz);
            cout << endl << endl;
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

void insertar_avl(AVL *&raiz, int clave, int &cen)
{
    if (raiz != NULL)
    {
        if (clave < raiz->inf)
        {
            cout << "\nNODO: " << raiz->inf << endl; 
            insertar_avl(raiz->izq, clave, cen);
            if (cen == 1)
            {
                switch (raiz->fe)
                {
                case 1:
                    raiz->fe = 0;
                    cen = 0;
                    break;
                case 0:
                    raiz->fe = -1;
                    break;
                case -1:
                    AVL *raiz1, *raiz2;
                    raiz1 = raiz->izq;
                    if (raiz1->fe >= 0)
                    {
                        raiz2 = raiz1->der;
                        raiz->izq = raiz2->der;
                        raiz2->der = raiz;
                        raiz1->der = raiz2->izq;
                        raiz2->izq = raiz1;
                        if (raiz2->fe == -1)
                        {
                            raiz->fe = 1;
                        }
                        else
                        {
                            raiz->fe = 0;
                        }
                        if (raiz2->fe == 1)
                        {
                            raiz1->fe = -1;
                        }
                        else
                        {
                            raiz1->fe = 0;
                        }
                        raiz = raiz2;
                    }
                    else
                    {
                        raiz->izq = raiz1->der;
                        raiz1->der = raiz;
                        raiz->fe = 0;
                        raiz = raiz1;
                    }
                    raiz->fe = 0;
                    cen = 0;
                    break;
                }
            }
            
        }
        else
        {
            if (clave > raiz->inf)
            {
                cout << "\nNODO: " << raiz->inf << endl; 
                insertar_avl(raiz->der, clave, cen);
                if (cen == 1)
                {
                    switch (raiz->fe)
                    {
                    case -1:
                        raiz->fe = 0; 
                        cen = 0;
                        break;
                    case 0:
                        raiz->fe = 1;
                        break;
                    case 1:
                        AVL *raiz1, *raiz2;
                        raiz1 = raiz->der;
                        if (raiz1->fe < 0)
                        {
                            raiz2 = raiz1->izq;
                            raiz->der = raiz2->izq;
                            raiz2->izq = raiz;
                            raiz1->izq = raiz2->der;
                            raiz2->der = raiz1;
                            if (raiz2->fe == 1)
                            {
                                raiz->fe = -1;
                            }
                            else
                            {
                                raiz->fe = 0;
                            }
                            if (raiz2->fe == -1)
                            {
                                raiz1->fe = 1;
                            }
                            else
                            {
                                raiz1->fe = 0;
                            }
                            raiz = raiz2;
                        }
                        else
                        {
                            raiz->der = raiz1->izq;
                            raiz1->izq = raiz;
                            raiz->fe = 0;
                            raiz = raiz1;
                        }
                        raiz->fe = 0;
                        cen = 0;
                        break;
                    }
                }
                
            }
            else
            {
                cout << "\nLA CLAVE YA EXISTE" << endl;
            }
        }
    }
    else
    {
        AVL *q;
        q = new(AVL);
        q->inf = clave;
        q->fe = 0;
        raiz = q;
        q->izq = NULL;
        q->der = NULL;
        cen = 1;
    }
}

void preorden(AVL *raiz)
{
    if(raiz != NULL)
    {
        cout << raiz->inf << "\t";
        preorden(raiz->izq);
        preorden(raiz->der);
    }
}