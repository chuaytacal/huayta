#include <iostream>
#include "Pilas.h"

using namespace std;

void menu(pila *p);

int main()
{
    pila *p = NULL;
    menu(p);

    return 0;
}

void menu(pila *p)
{
    int opc;
    string ref;
    do
    {
        system("cls");
        cout << "\n\t\t\tM E N U";
        cout << "\n\t\t\t=======";
        cout << "\n\n1. INSERTAR DATO A LA PILA";
        cout << "\n\n2. ELIMINAR DATO DE LA PILA";
        cout << "\n\n3. MOSTRAR PILA";
        cout << "\n\n4. SALIR";

        cout << "\n\n\t\t\tOPCION:  ";
        cin >> opc;
        switch (opc)
        {
            case 1:
                system("cls");
                p = insertar(p);
                break;
            case 2:
                system("cls");
                soltar(p);
                cout << endl << endl;
                system("pause");
                break;
            case 3:
                system("cls");
                mostrar(p);
                cout << endl << endl;
                system("pause");
                system("cls");
                break;
        }
    } while ((opc > 0) && (opc < 4));
}