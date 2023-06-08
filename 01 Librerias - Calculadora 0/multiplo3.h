#ifndef _MULTIPLO3
#define _MULTIPLO3

#include <iostream>

using namespace std;

void multiplo3(int n);

void multiplo3(int n)
{
    for (int i = 0; i <= n; i++)
    {
        if ((i % 3) == 0)
        {
            cout << "El numero " << i << " es multiplo de 3" << endl;
        }
        else
        {
            cout << "El numero " << i << " no es multiplo de 3" << endl;
        }
    }
}

#endif