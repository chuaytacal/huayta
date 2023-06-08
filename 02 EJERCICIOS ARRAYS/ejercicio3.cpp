#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "INGRESE LA DIMENSION DEL CUADRADO MAGICO: "; cin >> n;
    int A[n][n];
    int x = 0;
    int y = 0;
    int vx = 0;
    int vy = 0;
    int limite = n*n;
    int limitex = n - 1;
    int limitey = n - 1;
    for(x = 0; x < n; x++)
    {
        for(y = 0; y < n; y++)
        {
            A[x][y] = 0;
        }
    }
    x = n / 2;
    y = 0;
    for(int i = 1; i <= limite; i++)
    {
        A[y][x] = i;
        vx = x;
        vy = y;
        x++;
        if(x > limitex)
        {
            x = 0;
        }
        y--;
        if(y < 0)
        {
            y = limitey;
        }
        if(A[y][x] > 0)
        {
            x = vx;
            y = vy +1;
        }
    }
    cout << "\nCUADRADO MAGICO\n";
    for(x = 0; x < n; x++)
    {
        for(y = 0; y < n; y++)
        {
            cout << A[x][y] << "\t";
        }
        cout << endl;
    }
  return 0;
}