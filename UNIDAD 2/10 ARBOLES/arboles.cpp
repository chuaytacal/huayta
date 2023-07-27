#include <iostream>

using namespace std;

struct nodo
{
    int inf;
    int nivel;
    nodo* der;
	nodo* izq;
};

int cont = 1;
int altura = 0;

void crear_a(nodo*&, int&);
void preorden(nodo*&);
void inorden(nodo *&);
void postorden(nodo *&);
void altura_a(nodo*&);

int main ()
{
    int op;
    nodo *raiz = NULL;
    
    do
    {
        system("cls");
        cout << "----------------------------------------- MENU -----------------------------------------------" << endl;
        cout << "1. Crear Arbol" << endl;
        cout << "2. Recorrer Preorden" << endl;
        cout << "3. Recorrer Inorden"<<endl;
        cout << "4. Recorrer Postorden"<< endl;
        cout << "5. Altura" << endl;
        cout << "6. Salir" << endl;	
        cout << "Ingrese opcion: "; cin >> op;
        system("cls");
        if(op == 1)
        {
            raiz = new(nodo);
            raiz->nivel = 1;
            crear_a(raiz, cont);
            system("pause");
            system("cls");
        }
        else if(op == 2)
        {
			preorden(raiz);
            system("pause");
            system("cls");
        }
		else if (op == 3)
		{
			inorden(raiz);
            system("pause");
            system("cls");
		}
		else if (op == 4)
		{
			postorden(raiz);
            system("pause");
            system("cls");
		}
        else if (op == 5)
        {
            altura_a(raiz);
            cout << "La altura de la raiz es: " << altura << endl;
            system("pause");
            system("cls");
        }
    } while (op != 6);   
    
    return 0;
}

void crear_a(nodo *&raiz, int &cont)
{
    int op;
	fflush(stdin);
	cout << "\n\nIngrese el dato del nodo " << cont << ": ";
    cin >> raiz->inf;
	cout << "\nEl nodo " << cont << " tiene rama izquierda?" << endl;
	cout << "1. Si" << endl;
	cout << "2. No" << endl;
	cout << "Ingrese su opcion: "; cin >> op;
    if(op == 1)
    {
        nodo* x = new(nodo);
        raiz->izq = x;
        raiz->izq->nivel = raiz->nivel + 1;
        cont++;
        crear_a(raiz->izq, cont);
        cont--;
    }
    else
    {
        raiz->izq = NULL;
    }
    cout << "\nEl nodo " << cont << " tiene rama derecha?" << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    cout << "Ingrese su opcion "; cin >> op;
    cout << endl;
    if(op == 1)
    {
        nodo* x = new(nodo);
        raiz->der = x;
        raiz->der->nivel = raiz->nivel + 1;
        cont++;
        crear_a(raiz->der, cont);
        cont--;
    }
    else
    {
        raiz->der = NULL;
    }
}

void preorden(nodo *&raiz)
{
    if(raiz != NULL)
    {
        cout << "Nombre: " << raiz->inf  << "\t\tNivel: " << raiz->nivel << endl;
        preorden(raiz->izq);
        preorden(raiz->der);
    }
}

void inorden(nodo *&raiz)
{
    if(raiz != NULL)
    {
        inorden(raiz->izq);
        cout << "Nombre: " << raiz->inf  << "\t\tNivel: " << raiz->nivel << endl;
        inorden(raiz->der);
    }
}

void postorden(nodo *&raiz)
{
    if(raiz != NULL)
    {
        postorden(raiz->izq);
        postorden(raiz->der);
        cout << "Nombre: " << raiz->inf  << "\t\tNivel: " << raiz->nivel << endl;
        
    }
}

void altura_a(nodo*& raiz)
{
    if(raiz != NULL)
    {
        if ((raiz->izq == NULL) && (raiz->der == NULL))
        {
            int altura1 = raiz->nivel;
            if (altura1 >= altura)
            {
                altura = altura1;
            }
        }
        altura_a(raiz->izq);
        altura_a(raiz->der);
    }
}