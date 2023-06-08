#include <iostream>
#include "listas_c.h"

using namespace std;

void menu(nodo *p);

int main()
{
    nodo *p;
    p = NULL;
    menu(p);

    return 0;
}

void menu(nodo *p)
{
    int opc;
    int ref;
    do
    {
        system("cls");
        cout << "\n\t\t\tM E N U";
        cout << "\n\t\t\t=======";
        cout << "\n\n1. CREACION POR EL INICIO";
        cout << "\n\n2. CREACION POR EL FINAL";
        cout << "\n\n3. INSERTAR AL INICIO";
        cout << "\n\n4. INSERTAR AL FINAL";
        cout << "\n\n5. INSERTAR ANTES DE ....";
        cout << "\n\n6. INSERTAR DESPUES DE ...";
        cout << "\n\n7. ELIMINAR EL PRIMERO";
        cout << "\n\n8. ELIMINAR EL ULTIMO";
        cout << "\n\n9. ELIMINAR ANTES DE ...";
        cout << "\n\n10. BUSQUEDA";
        cout << "\n\n11. RECORRIDO";
        cout << "\n\n12. SALIR";

        cout << "\n\n\t\t\tOPCION:  ";
        cin >> opc;
        switch (opc)
        {
        case 1:
            system("cls");
            break;
        case 2:
            system("cls");
            break;
        case 3:
            system("cls");
            p = insertarc_i(p);
            break;
        case 4:
            system("cls");
            p = insertarc_f(p);
            break;
        case 5:
            system("cls");
            cout << "\nINGRESE EL CODIGO DEL ALUMNO REFERENCIA: ";
            cin >> ref;
            p = insertarc_ad(p, ref);
            break;
        case 6:
            system("cls");
            cout << "\nINGRESE EL CODIGO DEL ALUMNO REFERENCIA: ";
            cin >> ref;
            p = insertarc_dd(p, ref);
            break;
        case 7:
            system("cls");
            p = eliminarc_i(p);
            break;
        case 8:
            system("cls");
            p = eliminarc_f(p);
            break;
        case 9:
            system("cls");
            cout << "\nINGRESE EL CODIGO DEL ALUMNO REFERENCIA: ";
            cin >> ref;
            p = eliminarc_ad(p, ref);
            break;
        case 10:
            system("cls");
            break;
        case 11:
            system("cls");
            imprimir(p);
            system("pause");
            break;
        }
    } while ((opc > 0) && (opc < 12));
}