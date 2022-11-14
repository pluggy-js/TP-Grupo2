#ifndef LISTADINAMICA_H_INCLUDED
#define LISTADINAMICA_H_INCLUDED

typedef int tDato;

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

void lBorrarPpio (struct tLista* l){
    puntero aux;
    puntero t;
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
}

void lBorrarFin (struct tLista* l){
    puntero aux;
    puntero t;
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

void lBorrarActual (struct tLista* l){
    puntero aux;
    puntero t;
    if (l->cab == l->actual){
        if (l->cab->sig == l->actual){
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
}

#endif // LISTADINAMICA_H_INCLUDED
