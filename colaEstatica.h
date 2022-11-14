#ifndef COLAESTATICA_H_INCLUDED
#define COLAESTATICA_H_INCLUDED
#define CMAX 15

typedef int tDato;

typedef struct tCola{
    int fin;
    tDato elem[CMAX];
}tCola;

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
    printf("\nImprimiendo cola...");
    int i;
    for (i = 0; i<=c->fin; i++){
        printf("\n%d", c->elem[i]);
    }
}

#endif // COLAESTATICA_H_INCLUDED
