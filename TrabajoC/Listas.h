#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef int Tdato;
Tdato x;
int existe;

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
    NodoL* nodo= l->cab;
    nodo = malloc(sizeof(NodoL));
    nodo->info=x;
    nodo->sig = l->cab;
    return nodo;
}

//1
int Lvacia (struct Tlista *l){
    return l->actual == NULL;
};

//2
void Lppio (struct Tlista *l){
    l->actual = l->cab;
};

//3
void Linfo (struct Tlista *l, Tdato x){
    x = l->actual->info;
};

//4
void Lsig (struct Tlista *l){
    l->actual = l->actual->sig;
};

//5
int LFin (struct Tlista *l, int fin){
    return l->actual == l->cab;
};

//6
int Lllena (struct Tlista *l){
    return 0;  //ESTO SE TIENE QUE RE CONTRA CHEQUEAAAAAAAAAAR
              //NO ENCUENTRO COMO HACER MEMDISPONIBLE < SIZEOF (NUEVO) XD

};

//7
void Lcrear (struct Tlista *l){
    l->cab = NULL;
};

//8
void Lmodificiar (struct Tlista *l){
    l->actual->info = x;
};

//9
void LInsertarPpio (struct Tlista *l, Tdato x){
    puntero t, nuevo;
    CrearNodo (nuevo, t);
        if (l->cab == NULL) {
            nuevo->sig = nuevo;
            l->cab = nuevo;
        }else{
            t = l->cab;
            while (t->sig != l->cab){
                t = t->sig;
            }
            nuevo->sig = l->cab;
            t->sig = nuevo;
            l->cab = nuevo;
        }
};

//10
void LInsertarFin (struct Tlista *l, Tdato x){
    puntero t, nuevo;
    CrearNodo (nuevo, x);
    if (l->cab == NULL){
        nuevo->sig = nuevo;
        l->cab = nuevo;
    }else{
        t = l->cab;
        while (t->sig != l->cab){
            t = t->sig;
        }
        nuevo->sig = l->cab;
        t->sig = nuevo;
        l->cab = nuevo;
    }
};

//11
void LBorrarPpio (struct Tlista *l){
    puntero aux, t;
    aux = l->cab;
    if (l->cab->sig == l->cab){
        l->cab = NULL;
    }else{
        t = l->cab;
        while (t->sig != l->cab){
            t = t->sig;
        }
        l->cab = l->cab->sig;
        t->sig = l->cab;
    }
};

//12
void LBorrarFin (struct Tlista *l){
    puntero aux, t;
    t = l->cab;
    if (l->cab->sig == l->cab){
        l->cab = NULL;
        free (t);
    }else{
        aux = l->cab;
        while (aux->sig->sig != l->cab){
            aux = aux->sig;
        }
        t = aux->sig;
        aux->sig = l->cab;
        free (t);
    }
}

//13
void lBorrarActual (struct Tlista *l){
    puntero aux, t;
    if (l->cab = l->actual){
        if (l->cab->sig = l->actual){
            t = l->cab;
            l->cab = NULL;
            l->actual = NULL;
            free (t);
        }else{
            aux = l->actual;
            t = l->cab;
            while (t->sig != l->cab){
                t = t->sig;
            }
           l->actual = l->actual->sig;
           l->cab = l->actual;
           t->sig = l->actual;
           free (aux);
        }
    }else{
        aux = l->actual;
        t= l->cab;
        while (t->sig != l->actual){
            t = t->sig;
        }
        l->actual = l->actual->sig;
        t->sig = l->actual;
        free (aux);
    }
};

//14
void LInsertarOrdenado (struct Tlista *l, Tdato x, char ord){
    puntero t, nuevo;
    CrearNodo(nuevo,x);
    if (l->cab == NULL){
        nuevo->sig = nuevo;
        l->cab = nuevo;
    }else{
        if ((x > l->cab->info && ord == 'D') || (x < l->cab->info && ord =='A')) {
            t = l->cab;
            while (t->sig != l->cab){
                t = t->sig;
            }
            nuevo->sig = l->cab;
            t->sig = nuevo;
            l->cab = nuevo;
        }else{
            t = l->cab;
            while (t->sig != l->cab && ((x < l->cab->info && ord == 'D') || (x > l->cab->info && ord =='A'))){
                t = t->sig;
            }
            nuevo->sig = t->sig;
            t->sig = nuevo;
        }
    }
};

//15
void LBuscarOrdenado (struct Tlista *l, Tdato x, int existe){
    puntero t;
    t = l->cab;
    existe = 0;
    if (l->cab != NULL){
        if (l->cab->info == x){
            existe = 1;
            l->actual = l->cab;
        }else{
            t = l->cab->sig;
            while ((t != l->cab) && (t->info == l->cab->info)){
                t = t->sig;
            }
            if (t != l->cab){
                if (t->info < l->cab->info){
                    while ((t != l->cab)&&(t->info > x)){
                        t = t->sig;
                    }
                }else{
                    while ((t != l->cab)&&(t->info < x)){
                        t = t->sig;
                    }
                }
            }
            if ((t != l->cab) && (t->info == x)){
                existe = 1;
                l->actual = t;
            }
        }
    }
}
#endif // LISTAS_H_INCLUDED
