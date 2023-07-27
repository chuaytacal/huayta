#include <iostream>
#include <string>
#include "AVL.hpp"

using namespace std;

void menu(AVL *p);

int main()
{
    AVL *raiz = NULL;
    menu(raiz);

    return 0;
}

void menu(AVL *raiz)
{
    int opc, cod, cen = 0;
    do
    {
        system("cls");
        cout << "\n\t\t\tM E N U";
        cout << "\n\t\t\t=======";
        cout << "\n\n1. INSERTAR";
        cout << "\n\n2. ELIMINAR";
        cout << "\n\n3. MOSTRAR";
        cout << "\n\n4. RECORRIDO";
        cout << "\n\n5. SALIR";

        cout << "\n\n\t\t\tOPCION:  ";
        cin >> opc;
        switch (opc)
        {
            case 1:
                system("cls");
                cout << "\n\nINGRESE EL CODIGO A INSERTAR: ";
                cin >> cod;
                insertar_avl(raiz, cod, cen);
                cout << "\n\nSE INSERTO EL CODIGO: " << cod << endl;
                cout << endl << endl;
                system("pause");
                break;

            case 2:
                system("cls");
                cout << "\n\nINGRESE EL CODIGO A ELIMINAR: ";
                cin >> cod;
                eliminar_avl(raiz, cod, cen);
                cout << "\n\nSE ELIMINO EL CODIGO: " << cod << endl;
                cout << endl << endl;
                system("pause");
                break;

            case 3:
                system("cls");
                cout << "\n\nINGRESE EL CODIGO A BUSCAR: ";
                cin >> cod;
                buscar_avl(raiz, cod);
                cout << endl << endl;
                system("pause");
                break;
            case 4:
                system("cls");
                preorden(raiz);
                cout << endl << endl;
                system("pause");
                break;
        }
    } while ((opc > 0) && (opc < 5));
}