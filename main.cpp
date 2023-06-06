#include <iostream>
#include <cstdlib> ///rand()
#include <ctime>   ///time()
#include "ListaDupla.h"

using namespace std;

int numAleatorio(int a, int b)
{
    return a + rand()%(b - a + 1); /// retorna um numero inteiro aleat—rio entre a e b
}

int main()
{
    ListaDupla l; /// cria lista vazia
    int NumNos = 10;

    srand(time(NULL));

    /// ATENCAO: os valores inseridos na lista sao gerados
    /// aleatoriamente e mudam em cada execucao do programa!!!
    cout << "Inserindo valores: ";
    for(int i = 1; i <= NumNos; i++)
    {
        int val =  numAleatorio(0, 50); /// cria um valor aleat—rio entre 0 e 50
        cout << val << ", ";
        l.insereInicio(val);
    }
    cout << endl;

    bool existe = l.busca(20);
    cout << "O valor 20 esta na lista? ";
    if(existe)
        cout << "Sim" << endl;
    else
        cout << "Nao" << endl;

    cout << "Impressao normal" << endl;
    l.imprime();

    cout << "Impressao reversa" << endl;
    l.imprimeReverso();

    cout << endl;
    l.removeFinal();
    l.imprime();

    l.insereFinal(99);
    l.imprime();
    l.imprimeReverso();

    ListaDupla l2;
    cout << endl;

    l2.insereInicio(102);
    l2.insereInicio(103);
    l2.insereInicio(104);

    ListaDupla *l3 = l.concatena(&l2);
    l3->imprime();

    cout << "===========================================" << endl;
    ListaDupla *l4 = l.partir(3);
    l4->imprime();

    l.imprime();
    l.insereFinal(99);
    cout << "===========================================" << endl;
    l.imprime();
    //l.removeOcorrencias(99);
    //l.imprime();
    return 0;
};

