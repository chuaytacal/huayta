#include <iostream>
#include "ABB.h"

using namespace std;

void menu(ABB *p);

int main()
{
    ABB *raiz = NULL;
    menu(raiz);

    return 0;
}

void menu(ABB *raiz)
{
    int opc, opc1;
    Alumno alum;
    do
    {
        system("cls");
        cout << "\n\t\t\tM E N U";
        cout << "\n\t\t\t=======";
        cout << "\n\n1. INSERTAR";
        cout << "\n\n2. ELIMINAR";
        cout << "\n\n3. MOSTRAR";
        cout << "\n\n4. SALIR";

        cout << "\n\n\t\t\tOPCION:  ";
        cin >> opc;
        switch (opc)
        {
            case 1:
                system("cls");
                cout << "\n\t\t\tM E N U";
                cout << "\n\t\t\t=======";
                cout << "\n\n1. INSERTAR DE LA PRIMERA FORMA";
                cout << "\n\n2. INSERTAR DE LA SEGUNDA FORMA";
                cout << "\n\n\t\t\tOPCION:  ";
                cin >> opc1;
                system("cls");
                cout << "\n\nINGRESE EL CODIGO DEL ALUMNO: ";
                cin >> alum.cod;
                cout << "\n\nINGRESE EL NOMBRE DEL ALUMNO: ";
                fflush(stdin);
                getline(cin, alum.nombre);
                cout << "\n\nINGRESE LA PRIMERA NOTA DEL ALUMNO: ";
                cin >> alum.nota[0];
                cout << "\n\nINGRESE LA SEGUNDA NOTA DEL ALUMNO: ";
                cin >> alum.nota[1];
                alum.prom = (alum.nota[0] + alum.nota[1])/2;
                switch (opc1)
                {
                case 1:
                    insertar_abb(raiz, alum);
                    cout << endl;
                    system("pause");
                    break;
                
                case 2:
                    insertar1_abb(raiz, alum);
                    cout << endl;
                    system("pause");
                    break;
                }
                break;

            case 2:
                system("cls");
                cout << "\n\nINGRESE EL CODIGO DEL ALUMNO A ELIMINAR: ";
                cin >> alum.cod;
                eliminar_abb(raiz, alum);
                cout << endl << endl;
                system("pause");
                break;

            case 3:
                system("cls");
                cout << "\n\t\t\tM E N U";
                cout << "\n\t\t\t=======";
                cout << "\n\n1. BUSCAR DE LA PRIMERA FORMA";
                cout << "\n\n2. BUSCAR DE LA SEGUNDA FORMA";
                cout << "\n\n\t\t\tOPCION:  ";
                cin >> opc1;
                system("cls");
                cout << "\n\nINGRESE EL CODIGO DEL ALUMNO A BUSCAR: ";
                cin >> alum.cod;
                switch (opc1)
                {
                case 1:
                    buscar_abb(raiz, alum);
                    cout << endl;
                    system("pause");
                    break;
                
                case 2:
                    buscar_abb(raiz, alum);
                    cout << endl;
                    system("pause");
                    break;
                }
                break;
        }
    } while ((opc > 0) && (opc < 4));
}