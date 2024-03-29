#include <iostream>
#include <cstdlib>
#include "ListaDupla.h"

using namespace std;

ListaDupla::ListaDupla()
{
    cout << "Criando uma ListaDupla" << endl;
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

ListaDupla::~ListaDupla()
{
    cout << "Destruindo ListaDupla" << endl;
    NoDuplo *p = primeiro;
    while(p != NULL)
    {
        NoDuplo *t = p->getProx();
        delete p;
        p = t;
    }
}

bool ListaDupla::busca(int val)
{
    NoDuplo *p;
    for(p = primeiro; p != NULL; p = p->getProx())
        if(p->getInfo() == val)
            return true;
    return false;
}

int ListaDupla::get(int k)
{
    NoDuplo *p = primeiro;
    for(int i = 0; i < k; i++)
    {
        if(p == NULL)
            break;
        p = p->getProx();
    }
    if(p == NULL)
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
    else
        return p->getInfo();
}

void ListaDupla::set(int k, int val)
{
    NoDuplo *p = primeiro;
    for(int i = 0; i < k; i++)
    {
        if(p == NULL)
            break;
        p = p->getProx();
    }
    if(p == NULL)
        cout << "ERRO: Indice invalido!" << endl;
    else
        p->setInfo(val);
}

void ListaDupla::insereInicio(int val)
{
	NoDuplo *p = new NoDuplo();
	p->setInfo(val);
	p->setProx(primeiro);
	p->setAnt(NULL);

	if(n == 0) ultimo = p;
	else primeiro->setAnt(p);

	primeiro = p;
	n = n + 1;
}

void ListaDupla::insereFinal(int val)
{
    NoDuplo *p = new NoDuplo();
    p->setInfo(val);
    p->setProx(NULL);
    p->setAnt(ultimo);

    if(n == 0) ultimo = p;
    else ultimo->setProx(p);

    ultimo = p;
    n = n + 1;

}

void ListaDupla::removeFinal()
{
    NoDuplo *p;
    if(primeiro != NULL)
    {
        p = ultimo;
        ultimo = p->getAnt();
        delete p;
        n = n - 1;

        if(n == 0) ultimo = NULL;
        else ultimo->setProx(NULL);
    }
    else
    {
        cout << "ERRO: lista vazia" << endl;
    }
}

void ListaDupla::removeInicio()
{
	NoDuplo *p;
	if(primeiro != NULL)
	{
		p = primeiro;
		primeiro = p->getProx();
		delete p;
		n = n - 1;

		if(n == 0) 	ultimo = NULL;
		else primeiro->setAnt(NULL);
	}
	else
        cout << "ERRO: lista vazia" << endl;
}

void ListaDupla::imprime()
{
    NoDuplo *p;

    for(p = primeiro; p != NULL; p = p->getProx())
    {
        cout << p->getInfo() << " ";
    }

    cout << endl;
}

void ListaDupla::imprimeReverso()
{
    NoDuplo *p;

    for(p = ultimo; p != NULL; p = p->getAnt())
    {
        cout << p->getInfo() << " ";
    }
    cout << endl;
}

ListaDupla* ListaDupla::concatena(ListaDupla *l2)
{
    NoDuplo *p;
    ListaDupla* novaLista = new ListaDupla();


    for(p = primeiro; p!=NULL; p = p->getProx())
    {
        l2->insereFinal(p->getInfo());
    }

    novaLista = l2;

    return novaLista;

}

ListaDupla* ListaDupla::partir(int x)
{
    NoDuplo *p = ultimo;
    ListaDupla* novaLista = new ListaDupla();

    while(n != x)
    {
        novaLista->insereInicio(p->getInfo());
        p = p->getAnt();
        removeFinal();
    }

    return novaLista;
}

void ListaDupla::removeOcorrencias(int val)
{
    NoDuplo *p;
    for(p = primeiro; p != NULL; p = p->getProx())
    {
        if(p->getInfo() == val)
        {
            cout << "Ocorreu" << endl;
            p->setProx(NULL);
            p->setAnt(NULL);
            delete p;
        }
    }
}
