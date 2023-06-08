#include <iostream>
#include "cubo.h"

using namespace std;

int main(){
    double x;
    cout << "Ingrese la arista del cubo: "; cin >> x;
    cout << endl << "La area del cubo es: " << area(x) << endl;
    cout << "El volumen del cubo es: " << volumen(x);
    return 0;
}