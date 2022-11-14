#ifndef PILADINAMICA_H_INCLUDED
#define PILADINAMICA_H_INCLUDED

typedef int tDato;

typedef struct NodoP{
    tDato info;
    struct NodoP* sig;
}NodoP;

typedef NodoP* tPila;

void pCrear(tPila* p){
    *p = NULL;
}

int pVacia (tPila* p){
    return *p == NULL;
}

int pLlena(tPila* p){
    return 0;
}

void pPoner(tPila* p, tDato dato){
    NodoP* nuevo;
    nuevo = (NodoP*)malloc(sizeof(NodoP));
    nuevo->info = dato;
    nuevo->sig = *p;
    *p = nuevo;
}

void pSacar(tPila* p, tDato* dato){
    NodoP* aux;
    *dato = (*p)->info;
    aux = (*p);
    *p = (*p)->sig;
    free(aux);
}
void imprimirPila(tPila* p) {
  printf("\nImprimiendo pila...");
  NodoP* aux = *p;
  while (aux != NULL) {
    printf("\n%d", aux->info);
    aux = aux->sig;
  }
}

#endif // PILADINAMICA_H_INCLUDED
