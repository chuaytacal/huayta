#include <iostream>
#include "lista.h"

using namespace std;

void menu(nodo *p);

int main()
{
    nodo *p = NULL;
    menu(p);

    return 0;
}

void menu(nodo *p)
{
    int opc;
    do
    {
        system("cls");
        cout << "\n\t\t\tM E N U";
        cout << "\n\t\t\t=======";
        cout << "\n\n1. CREACION POR EL INICIO";
        cout << "\n\n2. CREACION POR EL FINAL";
        cout << "\n\n3. CREACION ANTES DE ...";
        cout << "\n\n4. CREACION DESPUES DE ...";
        cout << "\n\n5. ELIMINAR EL PRIMER DATO";
        cout << "\n\n6. ELIMINAR EL ULTIMO DATO";
        cout << "\n\n7. ELIMINACION";
        cout << "\n\n8. ELIMINAR ANTES DE ...";
        cout << "\n\n9. ELIMINAR DESPUES DE ...";
        cout << "\n\n10. MODIFICAR";
        cout << "\n\n11. BUSQUEDA";
        cout << "\n\n12. RECORRIDO";
        cout << "\n\n13. SALIR";

        cout << "\n\n\t\t\tOPCION:  ";
        cin >> opc;
        switch (opc)
        {
        case 1:
            system("cls");
            p = crea_i(p);
            break;
        case 2:
            system("cls");
            p = crea_f(p);
            break;
        case 3:
            system("cls");
            p = crear_a(p);
            break;
        case 4:
            system("cls");
            p = crear_d(p);
            break;
        case 5:
            system("cls");
            p = eliminar_p(p);
            break;
        case 6:
            system("cls");
            p = eliminar_u(p);
            break;
        case 7:
            system("cls");
            p = eliminar(p);
            break;
        case 8:
            system("cls");
            p = eliminar_ant(p);
            break;
        case 9:
            system("cls");
            p = eliminar_des(p);
            break;
        case 10:
            system("cls");
            p = modificar(p);
            break;
        case 11:
            system("cls");
            busqueda(p);
            break;
        case 12:
            system("cls");
            mostrar(p);
            system("pause");
            break;
        }
    } while ((opc > 0) && (opc < 13));
}