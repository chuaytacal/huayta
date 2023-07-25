#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>

using namespace std;

class LELectura
{
public:
    void abrir_lectura();
    void cerrar_lectura();
    void abrir_escritura();
    void cerrar_escritura();

private:
    mutex mtxMonitor;
    condition_variable lector, escritor;
    void informa(string mens);
    int n1;
    bool escribiendo;
} pl;

void LELectura::abrir_lectura()
{
    unique_lock<mutex> lck(mtxMonitor);
    if (escribiendo)
    {
        lector.wait(lck);
    }
    n1++;
    lector.notify_all();
}

void LELectura::cerrar_lectura()
{
    unique_lock<mutex> lck(mtxMonitor);
    n1--;
    if (n1 == 0)
    {
        escritor.notify_all();
    }
}

void LELectura::abrir_escritura()
{
    unique_lock<mutex> lck(mtxMonitor);
    if (n1 != 0 || escribiendo)
    {
        escritor.wait(lck);
    }
    escribiendo = true;
}

void LELectura::cerrar_escritura()
{
    unique_lock<mutex> lck(mtxMonitor);
    escribiendo = false;
    escritor.notify_all();
    lector.notify_all();
}

void lector()
{
    while (true)
    {
        pl.abrir_lectura();
        cout << "Leer el recurso" << endl;
        pl.cerrar_lectura();
    }
}

void escritor()
{
    while (true)
    {
        pl.abrir_escritura();
        cout << "Escribir en el recurso" << endl;
        pl.cerrar_escritura();
    }
}

int main()
{
    thread lectorThreads[4];
    thread escritorThreads[4];

    for (int i = 0; i < 4; i++)
    {
        lectorThreads[i] = thread(lector);
        escritorThreads[i] = thread(escritor);
    }

    for (int i = 0; i < 4; i++)
    {
        lectorThreads[i].join();
        escritorThreads[i].join();
    }

    return 0;
}