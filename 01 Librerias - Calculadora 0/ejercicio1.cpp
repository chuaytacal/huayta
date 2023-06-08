#include <iostream>
#include "suma.h"

using namespace std;

int main(){
    double x, y;
    cout << "Ingrese el primer numero: "; cin >> x;
    cout << "Ingrese el segundo numero: "; cin >> y;
    cout << endl << "La suma de " << x << " y " << y << " es: " << suma(x, y) << endl;
    return 0;
}