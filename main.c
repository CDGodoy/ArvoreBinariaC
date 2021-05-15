#include <stdio.h>
#include <stdlib.h>
#include "ABP.h"
#include "ABP.c"

int main(){

    int esc;
    ArvBin* raiz;
    do{

        cabecalho();
        menuPrincipal();
        scanf("%d", &esc);
        getchar();
        switch (esc){
            case 1:
                lerCSV();
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:
                return 0;
                break;
        }
        

    }while(1);

    return 0;

}