#ifndef _ORDENAR
#define _ORDENAR

#include <iostream>
#include "alumno.h"

using namespace std;

void ordenar(Alumno *x, int n);

void ordenar(Alumno *x, int n){
    int k;
	Alumno aux;
    for(int i = 1; i <= n; i++){
		aux = x[i];
		k = i - 1;
		while(k > -1 && aux.codigo < x[k].codigo){
			x[k+1] = x[k];
			k--;
		}
		x[k+1] = aux;
	}
}

#endif