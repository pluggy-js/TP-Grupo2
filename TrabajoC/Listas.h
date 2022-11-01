#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef int Tdato;

int fin;

Tdato x;

typedef struct Nodo{
    Tdato info;
    struct Nodo *sig;
}NodoL;

NodoL* CrearNodo (Tdato x);

typedef NodoL* puntero;

struct Tlista{
    puntero cab;
    puntero actual;
}Tlista;



///ACA EMPIEZA EL CODIGO

NodoL* CrearNodo(struct Tlista *l,Tdato x){
    NodoL* nodo= Tlista.cab;
    nodo = malloc(sizeof(NodoL));
    nodo->info=x;
    nodo->sig = Tlista.cab;
    return nodo;
}

int LFin (struct Tlista *l, int fin){
    if (Tlista.actual == Tlista.cab){
        fin = (1);
    }
    return (fin);
};

void LInsertarPpio (struct Tlista *l, Tdato x){
    Tlista t, nuevo;
    Tdato n;
    CrearNodo (nuevo, t);
        if (Tlista.cab == NULL) {
            nuevo->sig = nuevo;
            Tlista.cab = nuevo;
        }else{
            t = Tlista.cab;
            while (t->sig != Tlista.cab){
                t = t->sig;
            }
            nuevo->sig = Tlista.cab;
            t->sig = nuevo;
            Tlista.cab = nuevo;
        }
};
void lBorrarActual (struct Tlista *l){
    puntero aux, t;
    if (Tlista.cab = Tlista.actual){
        if (Tlista.cab->sig = Tlista.actual){
            t = Tlista.cab;
            Tlista.cab = NULL;
            Tlista.actual = NULL;
            free (t);
        }else{
            aux = Tlista.actual;
            t = Tlista.cab;
            while (t->sig != Tlista.cab){
                t = t->sig;
            }
           Tlista.actual = Tlista.actual->sig;
           Tlista.cab = Tlista.actual;
           t->sig = Tlista.actual;
           free (aux);
        }
    }else{
        aux = Tlista.actual;
        t= Tlista.cab;
        while (t->sig != Tlista.actual){
            t = t->sig;
        }
        Tlista.actual = Tlista.actual->sig;
        t->sig = Tlista.actual;
        free (aux);
    }
}

#endif // LISTAS_H_INCLUDED
