#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>

using namespace std;

class LEEscritura
{
public:
    void abrirLectura();
    void cerrarLectura();
    void abrirEscritura();
    void cerrarEscritura();

private:
    mutex mtxMonitor;
    condition_variable lector, escritor;
    void informa(string mens);
    int nl = 0;
    bool escribiendo = false;
};

void LEEscritura::abrirLectura()
{
    unique_lock<mutex> lck(mtxMonitor);
    if (escribiendo || (nl != 0))
    {
        lector.wait(lck);
    }
    nl++;
}

void LEEscritura::cerrarLectura()
{
    unique_lock<mutex> lck(mtxMonitor);
    nl--;
    if (nl == 0)
    {
        escritor.notify_one();
    }
}

void LEEscritura::abrirEscritura()
{
    unique_lock<mutex> lck(mtxMonitor);
    if ((nl != 0) || escribiendo)
    {
        escritor.wait(lck);
    }
    escribiendo = true;
}

void LEEscritura::cerrarEscritura()
{
    unique_lock<mutex> lck(mtxMonitor);
    escribiendo = false;
    if (nl != 0)
    {
        lector.notify_one();
    }
    else
    {
        escritor.notify_one();
    }
}

LEEscritura le;

void lector()
{
    while (true)
    {
    
        le.abrirLectura();
        cout << "Leer" << endl;
        le.cerrarLectura();
    }
}

void escritor()
{
    while (true)
    {
        le.abrirEscritura();
        cout << "Escribir" << endl;
        le.cerrarEscritura();
    }
}

int main()
{
    thread l[3], e[3];

    for (int i = 0; i < 3; i++)
    {
        l[i] = thread(lector);
        e[i] = thread(escritor);
    }

    for (int i = 0; i < 3; i++)
    {
        l[i].join();
        e[i].join();
    }

    return 0;
}