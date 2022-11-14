#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // esta libreria es para que funcionen los bools ¡IMPORTANTE!
#include "PilaDinamica.h"
#include "ColaEstatica.h"
#include "ListaDinamica.h"
/*#define CMAX 15 //Como usamos un arreglo dentro de la cola estatica necesitamos un MAX

// definimos tipos de datos de listas/pilas/colas
/*typedef int tDato; //tDato universal

typedef struct NodoP{
    tDato info;
    struct NodoP* sig;
}NodoP;

typedef NodoP* tPila;

typedef struct tCola{
    int fin;
    tDato elem[CMAX];
}tCola;

typedef struct NodoL{
    tDato info;
    struct NodoL* sig;
}NodoL;

typedef NodoL* puntero;

struct tLista{
    puntero cab;
    puntero actual;
}tLista;

NodoL* crearNodo (tDato dato);

NodoL* crearNodo(tDato dato){
    NodoL* nuevo = malloc(sizeof(NodoL));
    nuevo->info = dato;
    nuevo->sig = NULL;
    return nuevo;
}

//funciones de Pila dinamica
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
  printf("Imprimiendo pila...\n");
  NodoP* aux = *p;
  while (aux != NULL) {
    printf("%d\n", aux->info);
    aux = aux->sig;
  }
}
//fin funciones Pila dinamica

//funciones Cola estatica
void cCrear(tCola* c){
    c->fin = -1;
}

int cVacia (tCola* c){
    return c->fin == -1;
}

int cLlena(tCola* c){
    return c->fin == CMAX - 1;
}

void cPoner(tCola* c, tDato dato){
    c->fin++;
    c->elem[c->fin] = dato;
}

void cSacar(tCola* c, tDato* dato){
    int i;
    *dato = c->elem[0];

    for (i = 0; i<=c->fin-1; i++)
    {
        c->elem[i] = c->elem[i+1];
    }

    c->fin--;
}
void imprimirCola(tCola* c){
    printf("Imprimiendo cola...\n");
    int i;
    for (i = 0; i<=c->fin; i++){
        printf("%d\n", c->elem[i]);
    }
}
//fin funciones de Cola estatica

//funciones de lista dinamica simplemente enlazada circular, no estan todas
void lCrear(struct tLista* l){
    l->cab = NULL;
}

bool lVacia(struct tLista* l){
    return l->cab == NULL;
}

bool lLlena(struct tLista* l){
    return false;
}

void lPpio(struct tLista* l){
    l->actual = l->cab;
}

bool lFin(struct tLista* l){
    return l->actual == l->cab;
}

void lInfo(struct tLista* l, tDato* dato){
    *dato = l->actual->info;
}

void lModificar(struct tLista* l, tDato dato){
    l->actual->info = dato;
}

void lSig(struct tLista* l){
    l->actual = l->actual->sig;
}

void lInsertarPpio(struct tLista* l, tDato dato){
    puntero nuevo;
    puntero t;
    nuevo = crearNodo(dato);
    if (l->cab == NULL){
        nuevo->sig = nuevo;
        l->cab = nuevo;
    }else{
        t = l->cab;
        while(t->sig != l->cab){
            t = t->sig;
        }
        nuevo->sig = l->cab;
        t->sig = nuevo;
        l->cab = nuevo;
    }
}

void lInsertarFin(struct tLista* l, tDato dato){
    puntero nuevo;
    puntero t;
    nuevo = crearNodo(dato);
    if (l->cab == NULL){
        nuevo->sig = nuevo;
        l->cab = nuevo;
    }else{
        t = l->cab;
        while(t->sig != l->cab){
            t = t->sig;
        }
        nuevo->sig = l->cab;
        t->sig = nuevo;
    }
}

void lInsertarOrdenado(struct tLista* l, tDato dato, char orden){
    puntero nuevo;
    puntero t;
    nuevo = crearNodo(dato);
    if (l->cab == NULL){
        nuevo->sig = nuevo;
        l->cab = nuevo;
    }else{
        if ((dato > l->cab->info && orden == 'D') || (dato < l->cab->info && orden == 'A')){
            t = l->cab;
            while(t->sig != l->cab){
                t = t->sig;
            }
            nuevo->sig = l->cab;
            t->sig = nuevo;
            l->cab = nuevo;
        }else{
            t = l->cab;
            while(t->sig != l->cab && ((dato > t->sig->info && orden == 'A') || (dato < t->sig->info && orden == 'D'))){
                t = t->sig;
            }
            nuevo->sig = t->sig;
            t->sig = nuevo;
        }
    }
}

void lBuscarOrdenado(struct tLista *l, tDato dato, bool* existe){
    puntero t;
    t = l->cab;
    *existe = false;
    if (l->cab != NULL){
        if (l->cab->info == dato){
            *existe = true;
            l->actual = l->cab;
        }else{
            t = l->cab->sig;
            while ((t != l->cab) && (t->info == l->cab->info)){
                t = t->sig;
            }
            if (t != l->cab){
                if (t->info < l->cab->info){
                    while ((t != l->cab)&&(t->info > dato)){
                        t = t->sig;
                    }
                }else{
                    while ((t != l->cab)&&(t->info < dato)){
                        t = t->sig;
                    }
                }
            }
            if ((t != l->cab) && (t->info == dato)){
                *existe = true;
                l->actual = t;
            }
        }
    }
}
//funciones de lista dinamica simplemente enlazada circular, no estan todas


//estos procedimientos no funcionan, no son de importancia ahora
/*
void cargarPila(struct tLista* l, tPila* p){
    lPpio(&l);
    tDato dato = 0;
    int primero = 0;
    while (!lFin(&l) || primero == 0){
        if (primero == 0){
            primero = 1;
        }
        lInfo(&l, &dato);
        pPoner(&*p, dato);
        lSig(&l);
    }
}

void cargarCola(struct tLista* l, tCola* c, bool* error){
    lPpio(&l);
    int primero = 0;
    tDato dato = 0;
    while (!cLlena(&*c) && (!lFin(&l) || primero == 0)){
        if (primero == 0){
            primero = 1;
        }
        lInfo(&l, &dato);
        cPoner(&*c, dato);
        lSig(&l);
    }
    if (!lFin(&l)){
        *error = true;
    }
}*/

//procedimiento moverYOrdenar, poner en el main?
void moverYOrdenar(tPila* p, tCola* c, bool* error){
    struct tLista listaOrd;
    struct tLista listaPila;
    tDato dato;
    bool existe;
    char orden = 'A';
    int primero = 0;
    *error = false;
    lCrear(&listaOrd);
    lCrear(&listaPila);

    while (!pVacia(&*p) && !*error){
        pSacar(&*p, &dato);
        if (!lLlena(&listaPila) && !lLlena(&listaOrd)){
            lInsertarPpio(&listaPila, dato);
            lBuscarOrdenado(&listaOrd, dato, &existe);
            if (!existe){
                lInsertarOrdenado(&listaOrd, dato, orden);
            }
        }else{
            *error = true;
        }
    }
    if (!lVacia(&listaPila) && !*error){
        lPpio(&listaPila);
        while (!lFin(&listaPila) || primero == 0){
            if (primero == 0){
                primero = 1;
            }
            lInfo(&listaPila, &dato);
            pPoner(&*p, dato);
            lSig(&listaPila);
        }
        lPpio(&listaOrd);
        primero = 0;
        while (!cLlena(&*c) && (!lFin(&listaOrd) || primero == 0)){
            if (primero == 0){
                primero = 1;
            }
            lInfo(&listaOrd, &dato);
            cPoner(&*c, dato);
            lSig(&listaOrd);
        }
        if (!lFin(&listaOrd)){
            *error = true;
        }
    }
}

//main
int main(){
    tPila pila;
    tCola cola;
    tDato datoPila;
    tDato datoCola;
    bool error;

    pCrear(&pila);
    cCrear(&cola);

    //ponemos numeros en la pila
    /*pPoner(&pila, 10);
    pPoner(&pila, 60);
    pPoner(&pila, 50);
    pPoner(&pila, 20);
    pPoner(&pila, 40);
    pPoner(&pila, 30);
    pPoner(&pila, 30);*/


    //Interfaz para pedirle datos al usuario cdo ya este terminado el tp

    int eleccion;
    tDato numero;
    while (eleccion != -1) {
        printf("\n--BIENVENIDO--\n1.- Agregar\n2.- Eliminar\n3.- Imprimir "
                "pila\n4.- Comprobar si esta vacia\n-1.- Salir\nElige: ");
        scanf("%d", &eleccion);
        switch (eleccion) {
            case 1:
                printf("Ingresa el numero entero que agregaremos:\n");
                scanf("%d", &numero);
                pPoner(&pila, numero);
                break;
            case 2:
                if (!pVacia(&pila)){
                    pSacar(&pila, &datoPila);
                    printf("Se ha eliminado el numero %d de la pila\n", datoPila);
                }
                break;
            case 3:
                imprimirPila(&pila);
                break;
            case 4:
                if (pVacia(&pila)) {
                    printf("La pila esta vacia\n");
                }else{
                    printf("La pila NO esta vacia\n");
                }
                break;
        }
    }

    imprimirPila(&pila);
    imprimirCola(&cola);

    //llamamos al procedimiento
    moverYOrdenar(&pila, &cola, &error);

    if (pVacia(&pila)){    //verificamos que no este vacia
        printf("\nLa pila ingresada estaba vacia.");
    }else{
        if(!error){   //verificamos que no haya error
            imprimirPila(&pila);
            imprimirCola(&cola);
        }else{
            printf("\nHa habido un error."); //mensaje de error
        }
    }
    return 0;
}
