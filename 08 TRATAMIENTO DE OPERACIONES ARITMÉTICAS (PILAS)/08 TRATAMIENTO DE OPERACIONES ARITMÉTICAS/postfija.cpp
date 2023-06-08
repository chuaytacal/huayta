#include <iostream>
#include <string.h>
#include <sstream>
#include <math.h>

using namespace std;

string operando(string x);
string operandoc(char x);
int prioridad(string x);
string resultado(string op1, string op2, string sig);

int main()
{
    int tope, n, j, i, p, cont = 0;
    char ei[100];
    cout << "\n\n\t\t\tEXPREION INFIJA: ";
    cin >> ei;
    n = strlen(ei);
    string aux, eif[n], epost[n], pila[n];

    for (int k = 0; k < n; k++)
    {
        aux = ei[k];
        p = 0;
        if ((operandoc(ei[k]) == "operando") && (k < n-1))
        {
            if (operandoc(ei[k+1]) == "operando")
            {
                p = 1;
                while ((operandoc(ei[k+p]) == "operando") && (k+p < n))
                {
                    aux = aux + ei[k+p];
                    p++;
                }
                p--;
            }
        }
        k = k + p;
        eif[cont] = aux;
        cont++;
    }
    
    tope = -1;
    i = 0;
    j = 0;
    
    while (i < cont)
    {
        if (eif[i] == "(")
        {
            tope++;
            pila[tope] = eif[i];
        }
        else
        {
            if (eif[i] == ")")
            {
                while (pila[tope] != "(")
                {
                    epost[j] = pila[tope];
                    tope--;
                    j++;
                }
                tope--;
            }
            else
            {
                if (operando(eif[i]) == "operando")
                {
                    epost[j] = eif[i];
                    j++;
                }
                else
                {
                    while ((tope > -1) && (prioridad(eif[i]) <= prioridad(pila[tope])))
                    {
                        epost[j] = pila[tope];
                        tope--;
                        j++;
                    }
                    tope++;
                    pila[tope] = eif[i];
                }
            }
        }
        i++;
    }
    while (tope > -1)
    {
        epost[j] = pila[tope];
        tope--;
        j++;
    }

    cout << "\n\n\t\t\tEXPRESION PREFIJA: ";
    for (int i = 0; i < j; i++)
    {
        cout << epost[i];
    }

    j--;
    i = 0;
    p = 0;
    string pilaf[n];
    while (i <= j)
    {
        pilaf[p] = epost[i];
        if (operando(pilaf[p]) == "operador")
        {
            pilaf[p-2] = resultado(pilaf[p-2], pilaf[p-1], pilaf[p]);
            p = p - 2;
        }
        p++;
        i++;
    }
    
    cout << "\n\n\t\t\tEL RESULTADO DE LA EXPRESION ES: " << pilaf[0] << endl;
    return 0;
}

string operando(string x)
{
    if ((x == "+") || (x == "-") || (x == "*") || (x == "/") || (x == "(") || (x == ")") || (x == "^"))
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
    case '(':
        return "operador";
        break;
    case ')':
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