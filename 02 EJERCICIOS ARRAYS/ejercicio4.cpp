#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Ingrese la dimension de la matriz: ";
    cin >> n;
    int A[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Ingrese el valor de A[" << i+1 << "][" << j+1 << "]: ";
            cin >> A[i][j];
        }
    }
    int m = (2 * n) - 1;
    int A1[m][m], x, y, pos, cont = 0, vueltas = n/2;
    x = m/2;
    y = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            A1[i][j] = 0;
        }
    }
    if (n % 2 == 1)
    {
        A1[x][x] = A[n/2][n/2];
    }
    
    while (cont < vueltas)
    {
        for (int i = cont; i < n-1; i++)
        {
            A1[x][y] = A[cont][i];
            x--;
            y++;
        }
            
        for (int i = cont; i < n-1; i++)
        {
            A1[x][y] = A[i][n-1];
            x++;
            y++;
        }
            
        for (int i = n-1; i > cont; i--)
        {
            A1[x][y] = A[n-1][i];
            x++;
            y--;
        }
        
        for (int i = n-1; i > cont; i--)
        {
            A1[x][y] = A[i][cont];
            x--;
            y--;
        }
        
        cont++;
        n--;
        y = y + 2;
    }

    cout << "\n\nLA MATRIZ RESULTANTE ES: \n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << A1[i][j] << "\t";
        }
        cout << endl;
    }
}