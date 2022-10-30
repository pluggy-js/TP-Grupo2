#include <stdio.h>
#include <stdlib.h>
#include "Listas.h"
#include "piladinamica.h"
#include "colaestatica.h"
int main(){
    int continua = 1;
    int dato=0;
    int cantNum =0;
    while continuar==1{
        Continuar(continua);
        if continua==1{
            IngresarDato(dato, cantNum);
            cantNum= cantNum+1;
        }
    }
    if cantNum = 0 {
        printf("No se ingresó ningún número ): \n");
    }else{
        moverYOrdenar();
    }

    return 0;

}

int Continuar(continua){
    printf("Desea ingresar un dato? S(1)/N(0) \n");
    scanf(continua);
return continua
}
void IngresarDato(dato, cantNum){
    scanf(dato);
    //checkear como se usan las pilas
    if cantNum =0{
        pCrear();
    }
    pPoner(tPila, dato);
}
void moverYOrdenar(){
    //crear lista
    lCrear();
    //crear cola
    cCrear();
    //mientras pilavacia sea distinto de falso
    while pVacia()!= 0{
        int aux =0;
        int mayor=0;
        int menor=0;
        //obtengo dato de la pila que dios sabra como
        //lo ingreso a la lista
        LInsertarPpio();
        if cVacia() ==1{
            cPoner(p[i]);
        }else{
            //le doy el valor de dato(de la pila) a aux para poder comparlo
            aux=p[i];
            do{
                if aux>=c[i]{
                    if EsIgual(c[i], aux)== 0{
                        mayor= aux;
                        menor= c[i];
                        cSacar(c[i]);
                        cPoner(mayor);
                        cPoner(menor);
                    }
                    //i vale sig.cola
                    aux= c[i];
                }else{
                    //i vale sig.cola
                }
            }while i>=CP;
        }
        while i<=cantNum{
            pPoner(l[i]);
            //i vale sig.pila
        }
    }
}
end
