#include <iostream>
#include <string>
#include "eliminar_d.h"
#include "insertar_d.h"
#include "modificar_d.h"
#include "eliminar_o.h"
#include "insertar_o.h"
#include "modificar_o.h"
#include "buscar_o.h"
#include "ordenar.h"
#include "mostrar.h"
#include "alumno.h"

using namespace std;

int main(){
    system("cls");
    int op, op1, op2, dato, dato1, n = -1, m = -1;
    Alumno aO[10], aD[10], aux;
    do
    {
        cout << "\t\tM E N U  P R I N C I P A L" << endl;
        cout << "\t\t--------------------------" << endl;
        cout << "\t\t--------------------------" << endl << endl;
        cout << "\t\t1. Arreglos Ordenados" << endl;
        cout << "\t\t2. Arreglos Desordenados" << endl;
        cout << "\t\t3. Salir" << endl << endl;
        cout << "\t\t\t OPCION: "; cin >> op;
        system("cls");
        switch (op)
        {
        case 1:
            do
            {
                cout << "\t\tARREGLOS ORDENADOS" << endl;
                cout << "\t\t\t1. Insertar" << endl;
                cout << "\t\t\t2. Eliminar" << endl;
                cout << "\t\t\t3. Modificar" << endl;
                cout << "\t\t\t4. Mostrar" << endl;
                cout << "\t\t\t5. Salir" << endl;
                cout << "\t\t\t OPCION: "; cin >> op1;
                system("cls");
                switch (op1)
                {
                case 1:
                    cout << "\t\tIngrese el codigo del alumno: "; cin >> aux.codigo;
                    cout << "\t\tIngrese el nombre del alumno: ";
                    cin.ignore();
                    getline(cin, aux.nombre);
                    for (int i = 0; i < 2; i++)
                    {
                        cout << "\t\tIngrese la nota " << i+1 << " del alumno: "; cin >> aux.nota[i];
                    }
                    aux.prom = (aux.nota[0] + aux.nota[1])/2;
                    //cout << "\t\tIngrese el dato a insertar: "; cin >> dato;
                    inserta_o(aO, n, 10, aux);
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    cout << "\t\tIngrese el codigo del alumno a eliminar: "; cin >> dato;
                    //cout << "\t\tIngrese el dato a eliminar: "; cin >> dato;
                    eliminar_o(aO, n, dato);
                    system("pause");
                    system("cls");
                    break;
                case 3:
                    cout << "\t\tIngrese el codigo del alumno a modificar: "; cin >> dato;
                    system("cls");
                    //cout << "\t\tIngrese cual dato del array que desea modificar: "; cin >> dato;
                    //cout << "\t\tIngrese cual sera el nuevo dato: "; cin >> dato1;
                    modificar_o(aO, n, dato);
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    mostrar(aO, n);
                    system("pause");
                    system("cls");
                    break;
                default:
                    break;
                }
            } while (op1 != 5);
            break;
        case 2:
            do
            {
                cout << "\t\tARREGLOS DESORDENADOS" << endl;
                cout << "\t\t\t1. Insertar" << endl;
                cout << "\t\t\t2. Eliminar" << endl;
                cout << "\t\t\t3. Modificar" << endl;
                cout << "\t\t\t4. Mostrar" << endl;
                cout << "\t\t\t5. Salir" << endl;
                cout << "\t\t\t OPCION: "; cin >> op2;
                system("cls");
                switch (op2)
                {
                case 1:
                    cout << "\t\tIngrese el codigo del alumno: "; cin >> aux.codigo;
                    cout << "\t\tIngrese el nombre del alumno: ";
                    cin.ignore();
                    getline(cin, aux.nombre);
                    for (int i = 0; i < 2; i++)
                    {
                        cout << "\t\tIngrese la nota " << i+1 << " del alumno: "; cin >> aux.nota[i];
                    }
                    aux.prom = (aux.nota[0] + aux.nota[1])/2;
                    //cout << "\t\tIngrese el dato a insertar: "; cin >> dato;
                    inserta_d(aD, m, 3, aux);
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    cout << "\t\tIngrese el codigo del alumno a eliminar: "; cin >> dato;
                    //cout << "\t\tIngrese el dato a eliminar: "; cin >> dato;
                    eliminar_d(aD, m, dato);
                    system("pause");
                    system("cls");
                    break;
                case 3:
                    cout << "\t\tIngrese el codigo del alumno a modificar: "; cin >> dato;
                    system("cls");
                    //cout << "\t\tIngrese cual dato del array que desea modificar: "; cin >> dato;
                    //cout << "\t\tIngrese cual sera el nuevo dato: "; cin >> dato1;
                    modificar_d(aD, m, dato);
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    mostrar(aD, m);
                    system("pause");
                    system("cls");
                    break;
                default:
                    break;
                }
            } while (op2 != 5);
            break;
        default:
            cout << "\t\t------ CERRANDO EL PROGRAMA ------" << endl;
            system("pause");
            system("cls");
            break;
        }
    } while (op != 3);
    return 0;
}