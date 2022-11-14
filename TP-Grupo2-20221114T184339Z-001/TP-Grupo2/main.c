#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // esta libreria es para que funcionen los bools ¡IMPORTANTE!
#include "PilaDinamica.h"
#include "ColaEstatica.h"
#include "ListaDinamica.h"

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
        if (!lFin(&listaPila)){
            *error = true;
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
