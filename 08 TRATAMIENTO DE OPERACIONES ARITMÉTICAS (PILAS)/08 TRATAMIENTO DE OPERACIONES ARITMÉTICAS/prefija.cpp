#include <iostream>
#include <string.h>
#include <sstream>
#include <math.h>
#include <string>

using namespace std;

string operando(string x);
string operandoc(char x);
int prioridad(string x);
string resultado(string op1, string op2, string sig);

int main()
{
    int n, j, tope, k, cont = 0;
    double result;
    char ei[100];
    cout << "\n\n\t\t\tEXPREION INFIJA: ";
    cin >> ei;
    n = strlen(ei);
    string aux, eif[n], epre[n], pila[n], epref[n];

    for (int i = 0; i < n; i++)
    {
        aux = ei[i];
        k = 0;
        if ((operandoc(ei[i]) == "operando") && (i < n-1))
        {
            if (operandoc(ei[i+1]) == "operando")
            {
                k = 1;
                while ((operandoc(ei[i+k]) == "operando") && (i+k < n))
                {
                    aux = aux + ei[i+k];
                    k++;
                }
                k--;
            }
        }
        i = i + k;
        eif[cont] = aux;
        cont++;
    }
    j = -1;
    tope = -1;
    while (cont != 0)
    {
        if (eif[cont-1] == ")")
        {
            tope++;
            pila[tope] = eif[cont-1];
        }
        else
        {
            if (eif[cont-1] == "(")
            {
                while (pila[tope] != ")")
                {
                    j++;
                    epre[j] = pila[tope];
                    tope--;
                }
                tope--;
            }
            else
            {
                if (operando(eif[cont-1]) == "operando")
                {
                    j++;
                    epre[j] = eif[cont-1];
                }
                else
                {
                    while ((tope > -1) && (prioridad(eif[cont-1]) < prioridad(pila[tope])))
                    {
                        j++;
                        epre[j] = pila[tope];
                        tope--;
                    }
                    tope++;
                    pila[tope] = eif[cont-1];
                }
            }
        }
        cont--;
    }
    while (tope > -1)
    {
        j++;
        epre[j] = pila[tope];
        tope--;
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

    string pilaf[j];
    k = 0;
    while (j >= 0)
    {
        pilaf[k] = epref[j];
        if (operando(pilaf[k]) == "operador")
        {
            pilaf[k-2] = resultado(pilaf[k-1], pilaf[k-2], pilaf[k]);
            k = k - 2;
        }
        
        k++;
        j--;
    }
    
    cout << "\n\n\t\t\tEL RESULTADO DE LA EXPRESION ES: " << pilaf[0] << endl;
    
    return 0;
}

string operando(string x)
{
    if ((x == "+") || (x == "-") || (x == "*") || (x == "/") || (x == "^"))
    {
        return "operador";
    }
    else
    {
        return "operando";
    }
}

string operandoc(char x)
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
        case '(':
            return "operador";
            break;
        case ')':
            return "operador";
            break;
        default:
            return "operando";
            break;
    }
}

int prioridad(string x)
{
    if ((x == "+") || (x == "-"))
    {
        return 1;
    }
    else if ((x == "*") || (x == "/"))
    {
        return 2;
    }
    else if (x == "^")
    {
        return 3;
    }
    else
    {
        return 0;
    }
}

string resultado(string op1, string op2, string sig)
{
    string r1;
    double result;
    double o1, o2;
    istringstream(op1) >> o1;
    istringstream(op2) >> o2;
    if (sig == "+")
    {
        result = o1 + o2;
    }
    else if (sig == "-")
    {
        result = o1 - o2;
    }
    else if (sig == "*")
    {
        result = o1 * o2;
    }
    else if (sig == "/")
    {
        result = o1 / o2;
    }
    else if (sig == "^")
    {
        result = pow(o1, o2);
    }
    r1 = to_string(result);

    return r1;
}