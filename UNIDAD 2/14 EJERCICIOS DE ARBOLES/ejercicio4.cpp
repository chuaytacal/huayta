#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct AVL
{
    int inf;
    int fe;
    AVL *izq;
    AVL *der;
};

void insertar_avl(AVL *&raiz, int clave, int &cen);
void preorden(AVL *raiz, int &i);
void inorden(AVL *&raiz, int &i);
void eliminar_avl(AVL *&raiz, int clave, int &cen, int &cont);
void reestructurar1(AVL *&raiz, int &cen, int &cont);
void reestructurar2(AVL *&raiz, int &cen, int &cont);
void borra(AVL *&aux, AVL *&otro, int &cen, int &cont);

int main()
{
    int op, clave, cen = 0, cont, i;
    AVL *raiz;
    raiz = NULL;
    srand(time(NULL));
    for (int i = 0; i < 49; i++)
    {
        clave = 1 + rand()%(1000-1);
        insertar_avl(raiz, clave, cen);
    }
    do
    {
        system("cls");
        cout << "\n\n\t\tMENU" << endl << endl;
        cout << "1. INSERTAR" << endl;
        cout << "2. ELIMINAR" << endl;
        cout << "3. RECORRIDO" << endl;
        cout << "4. SALIR" << endl;
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
            i = 0;
            system("cls");
            cout << "\n\tESTAS SON LAS CLAVES EXISTENTES: " << endl << endl;
            preorden(raiz, i);
            cout << endl << endl;
            cont = 0;
            cout << "\nINGRESE EL DATO A ELIMINAR: ";
            cin >> clave;
            eliminar_avl(raiz, clave, cen, cont);
            cout << "\nEL NUMERO DE ROTACIONES EFECTUADAS AL ELIMINAR EL NODO " << clave << " ES: " << cont;
            cout << endl << endl;
            system("pause");
            break;

        case 3:
            i = 0;
            system("cls");
            preorden(raiz, i);
            cout << endl << endl;
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

void insertar_avl(AVL *&raiz, int clave, int &cen)
{
    if (raiz != NULL)
    {
        if (clave < raiz->inf)
        {
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

void eliminar_avl(AVL *&raiz, int clave, int &cen, int &cont)
{
    if (raiz != NULL)
    {
        if (clave < raiz->inf)
        {
            eliminar_avl(raiz->izq, clave, cen, cont);
            reestructurar1(raiz, cen, cont);
        }
        else
        {
            if (clave > raiz->inf)
            {
                eliminar_avl(raiz->der, clave, cen, cont);
                reestructurar2(raiz, cen, cont);
            }
            else
            {
                AVL *q;
                q = raiz;
                if (q->der == NULL)
                {
                    raiz = q->izq;
                    cen = 1;
                }
                else
                {
                    if (q->izq == NULL)
                    {
                        raiz = q->der;
                        cen = 1;
                    }
                    else
                    {
                        borra(q->izq, q, cen, cont);
                        reestructurar1(raiz, cen, cont);
                        delete (q);
                    }
                }
            }
        }
    }
    else
    {
        cout << "\nLA CLAVE NO EXISTE" << endl;
    }
    
}

void reestructurar1(AVL *&raiz, int &cen, int &cont)
{
    if (cen == 1)
    {
        switch (raiz->fe)
        {
        case -1:
            raiz->fe = 0;
            break;
        case 0:
            raiz->fe = 1;
            cen = 0;
            break;
        case 1:
            AVL *raiz1, *raiz2;
            raiz1 = raiz->der;
            cont++;
            if (raiz1->fe >= 0)
            {
                raiz->der = raiz1->izq;
                raiz1->izq = raiz;
                switch (raiz1->fe)
                {
                case 0:
                    raiz->fe = 1;
                    raiz1->fe = -1;
                    cen = 0;
                    break;
                case 1:
                    raiz->fe = 0;
                    raiz1->fe = 0;
                    break;
                }
                raiz = raiz1;
            }
            else
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
                raiz2->fe = 0;
                raiz = raiz2;
            }
            break;
        }
    }
}

void reestructurar2(AVL *&raiz, int &cen, int &cont)
{
    if (cen == 1)
    {
        switch (raiz->fe)
        {
        case 1:
            raiz->fe = 0;
            break;
        case 0:
            raiz->fe = 1;
            cen = 0;
            break;
        case -1:
            AVL *raiz1, *raiz2;
            raiz1 = raiz->izq;
            cont++;
            if (raiz1->fe <= 0)
            {
                raiz->izq = raiz1->der;
                raiz1->der = raiz;
                switch (raiz1->fe)
                {
                case 0:
                    raiz->fe = -1;
                    raiz1->fe = 1;
                    cen = 0;
                    break;
                case -1:
                    raiz->fe = 0;
                    raiz1->fe = 0;
                    break;
                }
                raiz = raiz1;
            }
            else
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
                raiz2->fe = 0;
                raiz = raiz2;
            }
            break;
        }
    }
}

void borra(AVL *&aux, AVL *&otro, int &cen, int &cont)
{
    if (aux->der != NULL)
    {
        borra(aux->der, otro, cen, cont);
        reestructurar2(aux, cen, cont);
    }
    else
    {
        otro->inf = aux->inf;
        otro = aux;
        aux = aux->izq;
        cen = 1;
    }
}

void preorden(AVL *raiz, int &i)
{
    if(raiz != NULL)
    {
        i++;
        if ((i % 10) == 0)
        {
            cout << "NODO "  << i << ": "<< raiz->inf << "\n";
        }
        else
        {
            cout << "NODO "  << i << ": "<< raiz->inf << "\t";
        }
        preorden(raiz->izq, i);
        preorden(raiz->der, i);
    }
}

void inorden(AVL *&raiz, int &i)
{
    if(raiz != NULL)
    {
        inorden(raiz->izq, i);
        i++;
        if ((i % 10) == 0)
        {
            cout << "NODO "  << i << ": "<< raiz->inf << "\n";
        }
        else
        {
            cout << "NODO "  << i << ": "<< raiz->inf << "\t";
        }
        inorden(raiz->der, i);
    }
}