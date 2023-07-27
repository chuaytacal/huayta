#include <iostream>
#include <string>

using namespace std;

struct Cliente
{
    long long int cbanco;
    string nombre;
    string contrasena;
    float monto;
};

void insertar(Cliente *c, int &frente, int &final, int max, Cliente c1);

int main()
{
    int op, op1, frente = -1, final = -1, max = 29, cen, cont;
    long long int ncb;
    float monto;
    string contrasena;
    Cliente c[30], c1;
    do
    {
        cout << "\n\t\t----------- MENU -----------" << endl;
        cout << "\n1. CREAR CLIENTES" << endl;
        cout << "2. OPERACIONES DE CLIENTES" << endl;
        cout << "3. SALIR" << endl;
        cout << "\n\t\tOPCION: ";
        cin >> op;
        system("cls");
        switch (op)
        {
            case 1:
                do
                {
                    cout << "INGRESE LA CUENTA BANCARIA (10 DIGITOS): ";
                    cin >> c1.cbanco;
                    if ((c1.cbanco <= 1000000000) || (c1.cbanco >= 10000000000))
                    {
                        cout << "\n\tLA CUENTA BANCARIA DEBE TENER 10 DIGITOS, INGRESE DENUEVO" << endl;
                    }
                } while ((c1.cbanco <= 1000000000) && (c1.cbanco >= 10000000000));
                cout << "INGRESE EL NOMBRE DEL CLIENTE: ";
                fflush(stdin);
                getline(cin, c1.nombre);
                cout << "INGRESE LA CONTRASENA DEL CLIENTE: ";
                fflush(stdin);
                getline(cin, c1.contrasena);
                c1.monto = 0;
                insertar(c, frente, final, max, c1);
                cout << endl;
                system("pause");
                break;
            
            case 2:
                cout << "INGRESE EL NUMERO DE CUENTA BANCARIA DEL CLIENTE: ";
                cin >> ncb;
                cout << "INGRESE LA CONTRASENA DE LA CUENTA BANCARIA DEL CLIENTE: ";
                fflush(stdin);
                getline(cin, contrasena);
                cen = 0;
                for (int i = frente; i <= final; i++)
                {
                    if ((c[i].cbanco == ncb) && (c[i].contrasena == contrasena))
                    {
                        cont = i;
                        cen = 1;
                    }
                }
                if (cen == 1)
                {
                    do
                    {
                        system("cls");
                        cout << "\n\t\t----------- BIENVENIDO [" << c[cont].nombre << "] -----------" << endl;
                        cout << "\n1. DEPOSITAR MONTO" << endl;
                        cout << "2. RETIRAR MONTO" << endl;
                        cout << "3. MOSTRAR MONTO ACTUAL" << endl;
                        cout << "4. VOLVER AL MENU PRINCIPAL" << endl;
                        cout << "\n\t\tOPCION: ";
                        cin >> op1;
                        system("cls");
                        switch (op1)
                        {
                            case 1:
                                cout << "INGRESE EL MONTO DE DINERO A DEPOSITAR: ";
                                cin >> monto;
                                c[cont].monto = c[cont].monto + monto;
                                cout << endl;
                                system("pause");
                                break;
                            
                            case 2:
                                if (c[cont].monto >= 0)
                                {
                                    do
                                    {
                                        cout << "INGRESE EL MONTO DE DINERO A RETIRAR: ";
                                        cin >> monto;
                                        if ((c[cont].monto - monto) < 0)
                                        {
                                            cout << "\tEL MONTO A RETIRAR INGRESADO SUPERA EL MONTO TOTAL DE LA CUENTA" << endl;
                                            cout << endl;
                                            system("pause");
                                            system("cls");
                                        }
                                    } while ((c[cont].monto - monto) < 0);
                                    c[cont].monto = c[cont].monto - monto;
                                    cout << endl;
                                    system("pause");
                                }
                                else
                                {
                                    cout << "\tUSTED NO PUEDE RETIRAR DINERO DEBIDO A QUE TIENE 0 SOLES" << endl << endl;
                                    system ("pause");
                                }
                                break;
                            case 3:
                                cout << "EL MONTO ACTUAL DE LA CUENTA BANCARIA ES DE: " << c[cont].monto << " SOLES" << endl;
                                system("pause"); 
                                break;
                            case 4:
                                cout << "----------- VOLVIENDO AL MENU PRINCIPAL -----------" << endl;
                                cout << endl;
                                system("pause");
                                break;
                        }
                    } while (op1 != 4);
                }
                else
                {
                    cout << "\n\tLA CUENTA NO HA SIDO REGISTRADA, REGISTRESE" << endl;
                    cout << endl;
                    system("pause");
                }
                break;

            case 3:
                cout << "----------- CERRANDO PROGRAMA -----------" << endl;
                system("pause");
                break;
        }
        system("cls");
    } while (op != 3);
    
    return 0;
}

void insertar(Cliente *c, int &frente, int &final, int max, Cliente c1)
{
    if (final < max)
    {
        final++;
        c[final].cbanco = c1.cbanco;
        c[final].nombre = c1.nombre;
        c[final].contrasena = c1.contrasena;
        c[final].monto = 0;
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