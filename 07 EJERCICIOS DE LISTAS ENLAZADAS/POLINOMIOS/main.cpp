#include <iostream>
#include <string>
#include "operaciones.h"

using namespace std;

void menu(Nodo *p, Nodo *q);

int main()
{
    Nodo *p;
    Nodo *q;
    p = NULL;
    q = NULL;
    menu(p, q);
    return 0;
}

void menu(Nodo *p, Nodo *q)
{
    int opc;
    string ref;
    Nodo *t;
    do
    {
        system("cls");
        cout << "\n\t\t\tM E N U";
        cout << "\n\t\t\t=======";
        cout << "\n\n1. CREACION DE POLINOMIOS";
        cout << "\n\n2. SUMA DE POLINOMIOS";
        cout << "\n\n3. RESTA DE POLINOMIOS";
        cout << "\n\n4. MULTIPLICACION DE POLINOMIOS";
        cout << "\n\n5. DIVISION DE POLINOMIOS";
        cout << "\n\n6. DERIVACION DE POLINOMIOS";
        cout << "\n\n7. GRADO DEL POLINOMIO";
        cout << "\n\n8. EVALUACION DEL POLINOMIO PARA UN VALOR CUALQUIERA";
        cout << "\n\n9. SALIR";

        cout << "\n\n\t\t\tOPCION:  ";
        cin >> opc;
        switch (opc)
        {
            case 1:
                system("cls");
                cout << "\n\t\t\t POLINOMIO P(X)" << endl;
                p = Creacion(p);
                cout << "\n\t\t\t POLINOMIO Q(X)" << endl;
                q = Creacion(q);
                break;
            case 2:
                system("cls");
                cout << "\n\t\t\tP(x): ";
                Mostrar(p);
                cout << "\n\t\t\tQ(x): ";
                Mostrar(q);
                t = Suma(p, q);
                cout << "\n\n\t\t\tP(x) + Q(x) = ";
                Mostrar(t);
                cout << endl << endl;
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                cout << "\n\t\t\tP(x): ";
                Mostrar(p);
                cout << "\n\t\t\tQ(x): ";
                Mostrar(q);
                t = Resta(p, q);
                cout << "\n\n\t\t\tP(x) - Q(x) = ";
                Mostrar(t);
                cout << endl << endl;
                system("pause");
                system("cls");
                break;
            case 4:
                system("cls"); 
                cout << "\n\t\t\tP(x): ";
                Mostrar(p);
                cout << "\n\t\t\tQ(x): ";
                Mostrar(q);
                t = Multiplicacion(p, q);
                cout << "\n\n\t\t\tP(x) * Q(x) = ";
                Mostrar(t);
                cout << endl << endl;
                system("pause");
                system("cls");
                break;
            case 5:
                system("cls"); 
                cout << "\n\t\t\tP(x): ";
                Mostrar(p);
                cout << "\n\t\t\tQ(x): ";
                Mostrar(q);
                Division(p, q);
                break;
            case 6:
                system("cls"); 
                cout << "\n\t\t\tP(x): ";
                Mostrar(p);
                t = Derivada(p);
                cout << "\n\n\t\t\tP'(x): ";
                Mostrar(t);
                cout << "\n\n\t\t\tQ(x): ";
                Mostrar(q);
                t = Derivada(q);
                cout << "\n\n\t\t\tP'(x): ";
                Mostrar(t);
                cout << endl << endl;
                system("pause");
                system("cls");
                break;
            case 7:
                system("cls"); 
                cout << "\n\t\t\tP(x): ";
                Mostrar(p);
                cout << "\n\n\t\t\tEl grado del polinomio P(x) es: " << Grado(p);
                cout << "\n\n\t\t\tQ(x): ";
                Mostrar(q);
                cout << "\n\n\t\t\tEl grado del polinomio P(x) es: " << Grado(q);
                cout << endl << endl;
                system("pause");
                system("cls");
                break;
            case 8:
                system("cls"); 
                float x;
                cout << "\n\t\t\tP(x): ";
                Mostrar(p);
                cout << "\n\t\t\t\tEVALUAR EL POLINOMIO P(x) EN X IGUAL A: ";
                cin >> x;
                cout << "\n\t\t\tEL RESULTADO DE EVALUAR EL POLINOMIO P(x) EN " << x << " ES: " << Evaluacion_p(p, x);
                cout << "\n\n\t\t\tQ(x): ";
                Mostrar(q);
                cout << "\n\n\t\t\tEVALUAR EL POLINOMIO G(x) EN X IGUAL A: ";
                cin >> x;
                cout << "\n\t\t\tEL RESULTADO DE EVALUAR EL POLINOMIO G(x) EN " << x << " ES: " << Evaluacion_p(q, x);
                cout << endl << endl;
                system("pause");
                system("cls");
                break;
        }
    } while ((opc > 0) && (opc < 9));
}