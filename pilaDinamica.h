#ifndef PILA_DINAMICA_ENTEROS_H
#define PILA_DINAMICA_ENTEROS_H

typedef int tDato;

typedef struct nodo
{
    tDato info;
    struct nodo* sig;
}Nodo;

typedef Nodo* tPila;

void pCrear(tPila* p)
{
    *p = NULL;
}

int pVacia (tPila* p)
{
    return *p == NULL;
}

int pLlena(tPila* p)
{
    return 0;
}

void pPoner(tPila* p, tDato dato)
{
    Nodo* nodo;
    nodo=(Nodo*)malloc(sizeof(Nodo));
    nodo->info=dato;
    nodo->sig = *p;
    *p = nodo;
}

void pSacar(tPila* p, tDato* dato)
{
    Nodo* aux;
    *dato = (*p)->info;
    aux = (*p);
    *p = (*p)->sig;
    free(aux);
}


#endif
