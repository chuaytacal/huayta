#include <iostream>
#include <string>
#include <iomanip>
#include "Alumno.h"

using namespace std;

struct pila
{
    Alumno inf;
    pila *sig;
};

pila *insertar(pila *p){
    pila *q;
    q = new(pila);

    cout << "\nINGRESE EL CODIGO DEL ALUMNO: ";
    fflush(stdin);
    getline(cin, q->inf.codigo);
    cout << "\nINGRESE LOS APELLIDOS Y NOMBRES DEL ALUMNO: ";
    fflush(stdin);
    getline(cin, q->inf.nombre);
    cout << "\nINGRESE LA NOTA 1 DEL ALUMNO: ";
    cin >> q->inf.nota[0];
    cout << "\nINGRESE LA NOTA 2 DEL ALUMNO: ";
    cin >> q->inf.nota[1];
    q->inf.prom = (q->inf.nota[0] + q->inf.nota[1]) / 2;

    q->sig = p;
    p = q;
    return (p);
}

void soltar(pila *&p)
{
    Alumno dato;
    pila *q;
    if (p != NULL)
    {
        dato = p->inf;
        q = p;
        p = q->sig;
        cout << "\n\n\t\tSE ELIMINO AL ALUMNO: " << endl;
        cout << "\n\t\tCODIGO: "<< dato.codigo << " "<< endl;
        cout << "\t\tNOMBRE: " << dato.nombre << endl;
        cout << "\t\tNOTA 1:" << dato.nota[0] << endl;
        cout << "\t\tNOTA 2:" << dato.nota[1] << endl;
        cout << "\t\tPROMEDIO:" << dato.prom << endl;
        delete (q);
    }
    else
    {
        cout << "\n\n\t\tLA PILA ESTA VACIA" << endl;
    }
}

void mostrar(pila *p)
{
    pila *q;
    q = p;
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << setw(40) << "ALUMNOS" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << setw(11) << "CODIGO";
    cout << setw(35) << "APELLIDOS Y NOMBRES";
    cout << setw(10) << "NOTA 1";
    cout << setw(10) << "NOTA 2";
    cout << setw(12) << "PROMEDIO" << endl;
    while (q != NULL)
    {
        cout << setw(11) << q->inf.codigo;
        cout << setw(35) << q->inf.nombre;
        cout << setw(10) << q->inf.nota[0];
        cout << setw(10) << q->inf.nota[1];
        cout << setw(12) << q->inf.prom;
        cout << endl;
        q = q->sig;
    }
    cout << "------------------------------------------------------------------------------------" << endl;
}