#include <iostream>
#include <string>

using namespace std;

void inicializa_c(string *c, int &fr, int &fi, string d);
void inserta_c(string *c, int &fr,  string d, int &fi, int max);
void eliminar_c(string *c, int &fr,  int &fi,  string &d);
void mostrar_c(string *c, int fr, int fi);

int main()
{
    int fr = -1, fi = -1, opcion;
    string c[30], d;
    for (;;)
    {
        cout << "OPERACIONES CON TDAs COLA" << endl;
        cout << "1. CREAR " << endl;
        cout << "2. INSERTAR" << endl;
        cout << "3. ELIMINAR" << endl;
        cout << "4. MOSTRAR" << endl;
        cout << "5. SALIR" << endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            inicializa_c(c, fr, fi, d);
            cout << endl;
            system("pause");
            break;
        case 2:
            cout << "INGRESE UN DATO ->"; cin >> d;
            inserta_c(c, fr, d, fi, 30);
            cout << endl;
            system("pause");
            break;
        case 3:
            eliminar_c(c, fr, fi, d);
            cout << "SE ELIMINO EL ->" << d;
            cout << endl;
            system("pause");
            break;
        case 4:
            mostrar_c(c, fr, fi);
            cout << endl;
            system("pause");
            break;
        case 5:
            cout << "Fin del programa!!!";
            exit(0);
        }
        system("cls");
    }
    
    return 0;
}

void inicializa_c(string *c, int &fr, int &fi, string d)
{
    fr = 0;
    fi = 0;
    cout << "INGRESE UN DATO ->";
    cin >> d;
    c[fr] = d;
}

void inserta_c(string *c, int &fr,  string d, int &fi, int max)
{
    if (fi < max)
    {
        fi++;
        c[fi] = d;
        if (fi == 0)
        {
            fr = 0;
        }
    }
    else
    {
        cout << "LA COLA SE ESTA DESBORDANDO" << endl;
    }
}

void eliminar_c(string *c, int &fr,  int &fi,  string &d)
{
    if (fr >= 0)
    {
        d = c[fr];
        if (fr == fi)
        {
            fr = -1;
            fi = -1;
        }
        else
        {
            fr = fr + 1;
        }
    }
    else
    {
        d = " ";
        cout << "COLA VACIA" << endl;
    }
}

void mostrar_c(string *c, int fr, int fi)
{
    cout << "LA COLA ES: " << endl;
    for (int i = fr; i <= fi; i++)
    {
        if ((fr != -1) && (fi != -1))
        {
            cout << c[i] << "\t";
        }
    }
}