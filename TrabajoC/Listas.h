#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED
typedef int actual;
typedef int lFin;
int x;
int l;
typedef int Tdato;

typedef struct{
    Tdato info;
    Puntero sig;
}Nodo;
typedef Nodo Puntero;
struct Tlista{
    Puntero cab;
    Puntero actual;
}Tlista;
typedef Tlista lista;


int LFin (){
    if (lista.actual == lista.cab){
        lFin = True;
    }
};

void LInsertarPpio (){
    Puntero t, nuevo;
    CrearNodo (nuevo, x);
        if (li.cab == NULL) {
            nuevo.sig = nuevo;
            li.cab = nuevo;
        }else{
            t = li.cab;
            while (&t.sig != li.cab){
                t = &t,sig;
            }
            &nuevo.sig = li.cab;
            &t.sig = nuevo;
            li.cab = nuevo;
        }
};
void lBorrarActual (){
    Puntero aux, t;
    if (li.cab = li.actual){
        if (li.&cab.sig = li.actual){
            t = li.cab;
            li.cab = NULL;
            li.actual = NULL;
            Disponer (t);
        }else{
            aux = li.actual;
            t = li.cab;
            while (t.*sig != li.cab){
                t = t.*sig;
            }
           li.actual = li.&actual.sig;
           li.cab = li.actual;
           &t.sig = li.actual;
           Disponer (aux);
        }
    }else{
        aux = li.actual;
        t=li.cab;
        while (&t.sig != li.actual){
            t = &t.sigl
        }
        li.actual = li.*actual.sig;
        t.sig = li.actual;
        Disponer (aux);
    }
}
#endif // LISTAS_H_INCLUDED
