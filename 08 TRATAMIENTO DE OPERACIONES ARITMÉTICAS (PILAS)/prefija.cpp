#include <iostream>
#include <string.h>
#include <sstream>
#include <math.h>

using namespace std;

string operando(char x);
int prioridad(char x);
double resultado(char op1, char op2, char sig);

int main()
{
    int n, j, tope;
    double resultado;
    char ei[100], op;
    cout << "\n\n\t\t\tEXPREION INFIJA: ";
    cin >> ei;
    n = strlen(ei);
    char epre[n], pila[n], epref[n];
    
    j = -1;
    tope = -1;
    while (n != 0)
    {
        if (ei[n-1] == ')')
        {
            tope = tope + 1;
            pila[tope] = ei[n-1];
        }
        else
        {
            if (ei[n-1] == '(')
            {
                while (pila[tope] != ')')
                {
                    j = j + 1;
                    epre[j] = pila[tope];
                    tope = tope - 1;
                }
                tope = tope - 1;
            }
            else
            {
                if (operando(ei[n-1]) == "operando")
                {
                    j = j + 1;
                    epre[j] = ei[n-1];
                }
                else
                {
                    while ((tope > -1) && (prioridad(ei[n-1]) < prioridad(pila[tope])))
                    {
                        j = j + 1;
                        epre[j] = pila[tope];
                        tope = tope - 1;
                    }
                    tope = tope + 1;
                    pila[tope] = ei[n-1];
                }
            }
        }
        n = n - 1;
    }
    while (tope > -1)
    {
        j = j + 1;
        epre[j] = pila[tope];
        tope = tope - 1;
    }
    for (int i = 0; i <= j; i++)
    {
        epref[i] = epre[j-i];
    }
    
    cout << "\n\n\t\t\tEXPRESION PREFIJA: ";
    for (int i = 0; i <= j; i++)
    {
        cout << epref[i];
    }
    int suma = 0;
    while (j > -1)
    {
        if (operando(epref[j]) == "operador")
        {
            epref[j] = resultado(epref[j+1], epref[j+2], epref[j]);
        }
        j--;
    }
    
    cout << "\n\n\t\t\tEL RESULTADO ES: " << epref[0] << endl << endl;
    return 0;
}

string operando(char x)
{
    switch (x)
    {
        case '+':
            return "operador";
            break;
        case '-':
            return "operador";
            break;
        case '*':
            return "operador";
            break;
        case '/':
            return "operador";
            break;
        case '^':
            return "operador";
            break;
        default:
            return "operando";
            break;
    }
}

int prioridad(char x)
{
    switch (x)
    {
        case '+':
            return (1);
            break;
        case '-':
            return (1);
            break;
        case '*':
            return (2);
            break;
        case '/':
            return (2);
            break;
        case '^':
            return (3);
            break;
        default:
            return (0);
    }
}

double resultado(char op1, char op2, char sig)
{
    double result;
    int oo1, oo2;
    /*string o1, o2;
    o1 = op1;
    o2 = op2;
    stringstream(o1) >> oo1;
    stringstream(o2) >> oo2;*/
    oo1 = op1 - '0';
    oo2 = op2 - '0';
    switch (sig)
    {
        case '+':
            result = oo1 + oo2;
            break;
        case '-':
            result = oo1 - oo2;
            break;
        case '*':
            result = oo1 * oo2;
            break;
        case '/':
            result = oo1 / oo2;
            break;
        case '^':
            result = pow(oo1, oo2);
            break;
        default:
            break;
    }
    return result;
}