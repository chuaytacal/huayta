#include <iostream>

using namespace std;

void insertar_c(char *cola, char x, int &final, int max, int &frente);
void eliminar(char *cola, int &frente, int &final);
int buscar_c(char *cola, int frente, int final, char x);

int main()
{
    int op, final = 5, frente = 0, max = 30, cen;
    char cola[30] = {'A', 'B', 'C', 'D', 'E', 'F'};
    cout << "INSERTAR LOS ELEMENTOS 'A, B, C':\n1. SI\n2. NO \n"; cin >> op;
    if (op == 1)
    {
        insertar_c(cola, 'A', final, max, frente);
        insertar_c(cola, 'B', final, max, frente);
        insertar_c(cola, 'C', final, max, frente);
    }

    cout << "ELIMINAR ELEMENTO 'A': \n1. SI\n2. NO \n"; cin >> op;
    if (op == 1)
    {
        cen = buscar_c(cola, frente, final, 'A');
        if (cen == 1)
        {
            eliminar(cola, frente, final);
        }
    }

    cout << "INSERTAR LOS ELEMENTOS 'D, E, F': \n1. SI\n2. NO \n"; cin >> op;
    if (op == 1)
    {
        insertar_c(cola, 'D', final, max, frente);
        insertar_c(cola, 'E', final, max, frente);
        insertar_c(cola, 'F', final, max, frente);
    }

    cout << "INSERTAR EL ELEMENTO 'G': \n1. SI\n2. NO \n"; cin >> op;
    if (op == 1)
    {
        insertar_c(cola, 'G', final, max, frente);
    }

    cout << "INSERTAR EL ELEMENTO 'H': \n1. SI\n2. NO \n"; cin >> op;
    if (op == 1)
    {
        insertar_c(cola, 'H', final, max, frente);
    }

    cout << "ELIMINAR LOS ELEMENTOS 'B, C': \n1. SI\n2. NO \n"; cin >> op;
    if (op == 1)
    {
        cen = buscar_c(cola, frente, final, 'B');
        if (cen == 1)
        {
            eliminar(cola, frente, final);
        }
        cen = buscar_c(cola, frente, final, 'C');
        if (cen == 1)
        {
            eliminar(cola, frente, final);
        }
    }

    cout << endl << "ELEMENTOS QUE QUEDARON EN LA COLA:" << endl;
    for (int i = frente; i <= final; i++)
    {
        cout << cola[i] << "\t";
    }
    cout << endl << "EN TOTAL QUEDAN " << final - frente + 1 << " ELEMENTOS EN LA COLA" << endl;
    if ((final - frente + 1) == 6)
    {
        cout << "LA COLA AUN TIENE 6 ELEMENTOS" << endl;
    }
    else
    {
        if ((final - frente + 1) < 6)
        {
            cout << "LA COLA HA DISMINUIDO " << 6 - (final - frente + 1) << " ELEMENTOS"<< endl;
        }
        else
        {
            cout << "LA COLA HA AUMENTADO " << (final - frente + 1) - 6 << " ELEMENTOS"<< endl;
        }
    }
    
    return 0;
}

void insertar_c(char *cola, char x, int &final, int max, int &frente)
{
    if (final < max)
    {
        final++;
        cola[final] = x;
        if (final == 0)
        {
            frente = 0;
        }
    }
    else
    {
        cout << "LA COLA SE ESTA DESBORDANDO" << endl;
    }
}

void eliminar(char *cola, int &frente, int &final)
{
    if (frente != -1)
    {
        if (frente == final)
        {
            frente = 0;
            final = 0;
        }
        else
        {
            frente = frente + 1;
        }
    }
    else
    {
        cout << "COLA VACIA" << endl;
    }
}

int buscar_c(char *cola, int frente, int final, char x)
{
    int a = 0;
    for (int i = frente; i <= final; i++)
    {
        if (cola[i] == x)
        {
            a = 1;
        }
    }
    return a;
}