#include <iostream>

using namespace std;

struct AVL
{
    int inf;
    int fe;
    AVL *izq;
    AVL *der;
};

void insertar_avl(AVL *&raiz, int clave, int &cen);
void eliminar_avl(AVL *&raiz, int clave, int &cen);
void reestructurar1(AVL *&raiz, int &cen);
void reestructurar2(AVL *&raiz, int &cen);
void borra(AVL *&aux, AVL *&otro, int &cen);
void buscar_avl(AVL *raiz, int dato);
void preorden(AVL *raiz);

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

void eliminar_avl(AVL *&raiz, int clave, int &cen)
{
    if (raiz != NULL)
    {
        if (clave < raiz->inf)
        {
            eliminar_avl(raiz->izq, clave, cen);
            reestructurar1(raiz, cen);
        }
        else
        {
            if (clave > raiz->inf)
            {
                eliminar_avl(raiz->der, clave, cen);
                reestructurar2(raiz, cen);
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
                        borra(q->izq, q, cen);
                        reestructurar1(raiz, cen);
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

void reestructurar1(AVL *&raiz, int &cen)
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

void reestructurar2(AVL *&raiz, int &cen)
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

void borra(AVL *&aux, AVL *&otro, int &cen)
{
    if (aux->der != NULL)
    {
        borra(aux->der, otro, cen);
        reestructurar2(aux, cen);
    }
    else
    {
        otro->inf = aux->inf;
        otro = aux;
        aux = aux->izq;
        cen = 1;
    }
}

void buscar_avl(AVL *raiz, int dato)
{
    if (raiz != NULL)
    {
        if (dato < raiz->inf)
        {
            if (raiz->izq != NULL)
            {
                buscar_avl(raiz->izq, dato);
            }
            else
            {
                cout << "\nEL DATO NO EXISTE" << endl;
            }
        }
        else
        {
            if (dato > raiz->inf)
            {
                if (raiz->der != NULL)
                {
                    buscar_avl(raiz->der, dato);
                }
                else
                {
                    cout << "\nEL DATO NO EXISTE" << endl;
                }
            }
            else
            {
                cout << "\nEL DATO ES LOCALIZADO" << endl << endl;
                cout << "\nCODIGO: " << raiz->inf << endl;
            }
        }
    }
    else
    {
        cout << "\nEL DATO NO EXISTE" << endl;
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