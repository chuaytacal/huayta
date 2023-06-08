#include <iostream>
#include "listas_d_e.h"

using namespace std;

void menu(nodo *p, nodo *f);

int main()
{
    nodo *p;
    nodo *f;
    p = NULL;
    f = NULL;
    menu(p, f);

    return 0;
}

void menu(nodo *p, nodo *f)
{
    int opc;
    string ref;
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
        cout << "\n\n9. ELIMINAR A ...";
        cout << "\n\n10. BUSQUEDA";
        cout << "\n\n11. RECORRIDO";
        cout << "\n\n12. SALIR";

        cout << "\n\n\t\t\tOPCION:  ";
        cin >> opc;
        switch (opc)
        {
        case 1:
            system("cls");
            cread_i(p, f);
            break;
        case 2:
            system("cls");
            cread_f(p, f);
            break;
        case 3:
            system("cls");
            insertad_i(p, f);
            break;
        case 4:
            system("cls");
            insertad_f(p, f);
            break;
        case 5:
            system("cls");
            cout << "\nINGRESE EL CODIGO DEL ALUMNO REFERENCIA: ";
            fflush(stdin);
            getline(cin, ref);
            inserta_ad(p, f, ref);
            break;
        case 6:
            system("cls");
            cout << "\nINGRESE EL CODIGO DEL ALUMNO REFERENCIA: ";
            fflush(stdin);
            getline(cin, ref);
            insertard_dd(p, f, ref);
            break;
        case 7:
            system("cls");
            eliminard_i(p, f);
            break;
        case 8:
            system("cls");
            eliminard_u(p, f);
            break;
        case 9:
            system("cls");
            cout << "\nINGRESE EL CODIGO DEL ALUMNO A ELIMINAR: ";
            fflush(stdin);
            getline(cin, ref);
            eliminard_x(p, f, ref);
            break;
        case 10:
            system("cls");
            busqueda(p);
            break;
        case 11:
            system("cls");
            mostrar(p);
            system("pause");
            break;
        }
    } while ((opc > 0) && (opc < 12));
}