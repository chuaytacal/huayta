#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Persona
{
    int edad;
    string nombre;
};

void insertar(Persona *p, int &frente, int &final, int max, Persona p1);
void eliminar_c(Persona *p, int &frente,  int &final, Persona &p1);
void mostrar_c(Persona *p, int frente, int final);

int main()
{
    Persona p[20], p18[20], pi[20], pc[20], p1;
    int op, op1, max = 19, frente[4], final[4], cen;
    for (int i = 0; i < 4; i++)
    {
        frente[i] = -1;
        final[i] = -1;
    }
    do
    {
        cout << "\n\t\t----------- MENU -----------" << endl;
        cout << "\n1. INGRESAR PERSONA" << endl;
        cout << "2. RETIRAR PERSONA" << endl;
        cout << "3. MOSTRAR" << endl;
        cout << "4. CERRAR PROGRAMA" << endl;
        cout << "\n\t\tOPCION: ";
        cin >> op;
        system("cls");
        switch (op)
        {
            case 1:
                cout << "INGRESE EL NOMBRE DE LA PERSONA: ";
                fflush(stdin);
                getline(cin, p1.nombre);
                cout << "INGRESE LA EDAD DE LA PERSONA: ";
                cin >> p1.edad;

                if (p1.edad > 18)
                {
                    insertar(p18, frente[1], final[1], max, p1);
                }
                if ((p1.edad % 2) == 1)
                {
                    insertar(pi, frente[2], final[2], max, p1);
                }
                cen = 0;
                for (int i = frente[0]; i <= final[0]; i++)
                {
                    if ((frente[0] != -1) && (final[0] != -1))
                    {
                        if (p[i].edad == p1.edad)
                        {
                            int k = final[3];
                            for (int j = frente[3]; j <= k; j++)
                            {
                                if ((frente[3] != -1) && (final[3] != -1))
                                {
                                    if (cen == 0)
                                    {
                                        if ((pc[j].nombre == p[i].nombre) && (pc[j].edad == p[i].edad))
                                        {
                                            insertar(pc, frente[3], final[3], max, p1);
                                            cen = 1;
                                        }
                                        else if (((pc[j].nombre != p[i].nombre) && (pc[j].edad != p[i].edad)) && ((p1.nombre != pc[j].nombre) && (p1.edad != pc[j].edad)))
                                        {
                                            insertar(pc, frente[3], final[3], max, p[i]);
                                            insertar(pc, frente[3], final[3], max, p1);
                                            cen = 1;
                                        }
                                    }
                                }
                                else
                                {
                                    if (cen == 0)
                                    {
                                        insertar(pc, frente[3], final[3], max, p[i]);
                                        insertar(pc, frente[3], final[3], max, p1);
                                        cen = 1;
                                    }
                                }
                            }
                        }
                    }
                }
                insertar(p, frente[0], final[0], max, p1);
                cout << endl;
                system("pause");
                break;

            case 2:
                if ((p[frente[0]].nombre == p18[frente[1]].nombre) && (p[frente[0]].edad == p18[frente[1]].edad))
                {
                    eliminar_c(p18, frente[1], final[1], p1);
                }
                if ((p[frente[0]].nombre == pi[frente[2]].nombre) && (p[frente[0]].edad == pi[frente[2]].edad))
                {
                    eliminar_c(pi, frente[2], final[2], p1);
                }
                if ((p[frente[0]].nombre == pc[frente[3]].nombre) && (p[frente[0]].edad == pc[frente[3]].edad))
                {
                    eliminar_c(pc, frente[3], final[3], p1);
                }

                eliminar_c(p, frente[0], final[0], p1);
                cout << "\nSE ELIMINO A LA PERSONA: " << endl;
                cout << "NOMBRE: " << p1.nombre << endl;
                cout << "EDAD: " << p1.edad;
                cout << endl;
                system("pause");
                break;
            
            case 3:
                cout << "\n\t\t----------- MENU -----------" << endl;
                cout << "\n1. MOSTRAR TODAS LAS PERSONAS" << endl;
                cout << "2. MOSTRAR PERSONAS SOLO MAYORES DE 18 ANIOS" << endl;
                cout << "3. MOSTRAR PERSONAS CON EDADES IMPARES" << endl;
                cout << "4. MOSTRAR PERSONAS QUIENES EDADES COINCIDEN " << endl;
                cout << "\n\t\tOPCION: ";
                cin >> op1;
                switch (op1)
                {
                    case 1:
                        mostrar_c(p, frente[0], final[0]);
                        cout << endl;
                        system("pause");
                        break;
                    
                    case 2:
                        mostrar_c(p18, frente[1], final[1]);
                        cout << endl;
                        system("pause");
                        break;
                    
                    case 3:
                        mostrar_c(pi, frente[2], final[2]);
                        cout << endl;
                        system("pause");
                        break;
                    
                    case 4:
                        mostrar_c(pc, frente[3], final[3]);
                        cout << endl;
                        system("pause");
                        break;
                }
                break;

            case 4:
                cout << "----------- CERRANDO PROGRAMA -----------" << endl << endl;
                system("pause");
                break;
        }
        system("cls");
    } while (op != 4);
    
    return 0;
}

void insertar(Persona *p, int &frente, int &final, int max, Persona p1)
{
    if (final < max)
    {
        final++;
        p[final].nombre = p1.nombre;
        p[final].edad = p1.edad;
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

void eliminar_c(Persona *p, int &frente, int &final, Persona &p1)
{
    if (frente >= 0)
    {
        p1.nombre = p[frente].nombre;
        p1.edad = p[frente].edad;
        if (frente == final)
        {
            frente = -1;
            final = -1;
        }
        else
        {
            frente = frente + 1;
        }
    }
    else
    {
        p1.nombre = " ";
        p1.edad = 0;
        cout << "COLA VACIA" << endl;
    }
}

void mostrar_c(Persona *p, int frente, int final)
{
    cout << "LA COLA ES: " << endl;

    cout << "--------------------------------------------" << endl;
    cout << setw(23) << "PERSONAS" << endl;
    cout << "--------------------------------------------" << endl;
    cout << setw(25) << "NOMBRE";
    cout << setw(10) << "EDAD" << endl;
    for (int i = frente; i <= final; i++)
    {
        if ((frente != -1) && (final != -1))
        {
            cout << setw(25) << p[i].nombre;
            cout << setw(10) << p[i].edad;
            cout << endl;
        }
    }
    cout << "\n--------------------------------------------" << endl;
}
