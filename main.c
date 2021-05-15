#include <stdio.h>
#include <stdlib.h>
#include "ABP.h"
#include "ABP.c"

int main(){

    int esc, valor, y;
    ArvBin* raiz = criaABP();

    do{

        cabecalho();
        menuPrincipal();
        scanf("%d", &esc);
        getchar();
        switch (esc){
            case 1:
                printf("Insira o valor a ser colocado na arvore: ");
                scanf("%d", &valor);
                int x = insereArv(raiz, valor);
                break;
            case 2:
                percorreBalanceamento(raiz, *raiz);
                break;
            case 3:
                arvCrescente(raiz);
                printf("\nPressione qualquer tecla para limpar a tela e continuar.");
                getchar();
                break;
            case 4:
                liberaABP(raiz);
                return 0;
                break;
        }

    }while(1);

    return 0;

}