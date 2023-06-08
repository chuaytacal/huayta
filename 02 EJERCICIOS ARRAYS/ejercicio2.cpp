#include <iostream>

using namespace std;

void espiral(int n, int A[][101]);

int main()
{
    int n, A[101][101];
    do
    {
        cout << "Ingrese la dimension de la matriz cuadrada (Debe ser un numero impar): ";
        cin >> n;
        if (n % 2 == 0)
        {
            cout << "\n\n------------ El numero debe ser un numero impar ------------\n";
        }
    } while (n % 2 == 0);
    espiral(n, A);
    cout << "\n\nLa matriz en espiral quedaria como: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << "\t";
        }
        cout << endl; 
    }
    return 0;
}

void espiral(int n, int A[][101])
{
    int valor, x, y, i, max;
    x = n/2;
    y = n/2;
    i = 1;
    cout << "\n\nIngrese el numero central de la matriz: ";
    cin >> valor;
    max = valor + (n*n);
    while (valor <= max)
    {
        for (int j = 0; (j < i) && (valor <= max); j++)
        {
            A[x][y] = valor;
            valor++;
            y++;
        }
        for (int j = 0; (j < i) && (valor <= max); j++)
        {
            A[x][y] = valor;
            valor++;
            x++;
        }
        i++;
        for (int j = 0; (j < i) && (valor <= max); j++)
        {
            A[x][y] = valor;
            valor++;
            y--;
        }
        for (int j = 0; (j < i) && (valor <= max); j++)
        {
            A[x][y] = valor;
            valor++;
            x--;
        }
        i++;
    }
    
}