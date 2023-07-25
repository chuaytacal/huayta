#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>

using namespace std;

const int N = 5;
int cont = 0;

class buffer
{
public:
    void insertar(int elemento);
    void sacar(int elemento);

private:
    mutex mtxMonitor;
    condition_variable nolleno, novacio;
    void informa(string mens);
    int recurso[N];
    int tam = 0, frente = 0, cola = 0;
} b;

void buffer::insertar(int elemento)
{
    unique_lock<mutex> lck(mtxMonitor);
    if (tam >= N)
    {
        nolleno.wait(lck);
    }
    recurso[cola] = elemento;
    tam = tam + 1;
    cola = (cola + 1) % N;
    novacio.notify_all();
}

void buffer::sacar(int elemento)
{
    unique_lock<mutex> lck(mtxMonitor);
    if(tam == 0)
    {
        novacio.wait(lck);
    }
    elemento = recurso[frente];
    tam = tam - 1;
    frente = (frente + 1) % N;
    nolleno.notify_all();
}


void productor()
{
    while(true)
    {
        cont = cont + 1;
        b.insertar(cont);
        cout << "Se produce el elemento " << cont << endl;
    }
}

void consumidor()
{
    while(true)
    {
        b.sacar(cont);
        cout << "Se consume el elemento " << cont << endl;
    }
}

int main()
{
    thread producerThreads(productor);
    thread consumerThreads(consumidor);

    producerThreads.join();
    consumerThreads.join();
    return 0;
}