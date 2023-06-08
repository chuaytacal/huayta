#ifndef _ALUMNO
#define _ALUMNO

#include <iostream>
#include <string>

using namespace std;

struct Alumno
{
    int codigo;
    string nombre;
    double nota[2];
    double prom;
};

#endif