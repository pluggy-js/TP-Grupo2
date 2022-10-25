#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED
typedef int actual;
typedef int lFin;
int x;
int l;
typedef struct reg {
    int *actual;
    int *cab;
}reg;
typedef struct nuevo{
    int *cab;
    int *sig;
};

int LFin (reg)){
    lFin = (reg.actual == reg.cab);
}

void LInsertarPpio (){
    int *t;
    int *nuevo;
    CrearNodo (nuevo, x);
        if (l.cab == NULL) {
            nuevo.sig = nuevo;
            l.cab = nuevo;
        }else{
            t = l.cab;
            while (&t.sig != l.cab){
                t = &t->sig;
            }
            nuevo.sig = l.cab;
            *t.sig = nuevo;
            l.cab = nuevo;
        }
}
void lBorrarActual (){
int aux*
int t*
if (l.cab*sig = l.cab){
	if (l.cab*sig = l.cab){
		t = l ->cab
		l.cab = null
		l.actual = null
		disponer(t) //???????
		}else{
			aux = l.actual
			t = l->cab
		while (&t.sig != l.cab){
			t = t*sig
			}
		l->actual = l->actual*sig
		l->cab = l->actual
		t*sig = l->actual
		Disponer (aux)
		}else{
			aux = l->actual
			t = l->cab
			while (t*sig != l->actual){
				t = t*sig
				}
			l->actual = l->actual*sig
			t*sig = l->actual
			Disponer (aux)
			}
}
};

#endif // LISTAS_H_INCLUDED
