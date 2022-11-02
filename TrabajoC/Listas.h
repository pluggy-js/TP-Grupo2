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


typedef NodoL* puntero;

struct Tlista{
    puntero cab;
    puntero actual;
}Tlista;

NodoL* CrearNodo (struct Tlista *l,Tdato x);


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
    puntero t, nuevo;
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

void LInsertarOrdenado (struct Tlista *l, Tdato x, char ord){
    puntero aux, nuevo;
    CrearNodo(nuevo,x);
    if (Tlista.cab == Tlista.actual){
        Tlista.cab = nuevo;
    }else{
        if ((x > Tlista.cab->info && ord == 'D') || (x < Tlista.cab->info && ord =='A')) {
            nuevo->sig = Tlista.cab;
            Tlista.cab = nuevo; ///HAY QUE REVISAR ACA, SI HAY QUE HACER ALGUN CAMBIO O AGREGAR PARA LAS LISTAS CIRCULARES
        }else{
            aux = Tlista.cab;
            while ((aux->sig != Tlista.actual && (x > aux->sig->info && ord == 'A')) || (x < aux->sig->info && ord == 'D')){
                aux = aux->sig;
            }
            nuevo->sig = aux->sig;
            aux->sig = nuevo;
        }
    }
};

#endif // LISTAS_H_INCLUDED
