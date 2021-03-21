#include <stdio.h>
#include <string.h>

// ADICIONAR CONTADOR DE LINHAS E SUBSTITUIR O TAMANHO LINHAS (LS)


int main(){
    FILE *arq;
    int i;
    const int TAM = 173; //A maior palavra do mundo tem 173 letras
    const int LS = 20; //Quantidade de linhas do arquivo
    char palavras[LS][TAM];
    char buffer [LS][TAM];
    char *resul;
    char no_me[15]; //Nome a ser pesquisado e seu tamanho
    arq = fopen("texto.txt","r");
    printf("Arquivo txt: ");
    if(arq != NULL){
        for(i=0;i<20;i++){ //Mostra todas as palavras do arquivo
            resul = fgets(*buffer,TAM,arq); //(ponteiro que irá armazenar, tamanho máximo da palavra, arquivo destino)
            strcpy(palavras[i], *buffer); //Copiando do ponteiro que armazenou para o vetor de palavras
            printf(" %s", *buffer);

        }
    }else{
        printf("Erro ao abrir arquivo");
    }

    do{
        printf("\n\nDigite um nome para ser pesquisado: ");
        gets(no_me);
        fflush(stdin); //Limpar teclado
        for(i=0;i<10;i++){  //N lembro pra que esse for
            if(strstr(palavras[i],no_me)){ //Comparando as strings anteriores com a digitada
                printf("A palavra: %s esta na linha: %d do arquivo\n\n", no_me,i+1);
                for(i=0;i<20;i++){
                    printf(" Linha %d: %s", i+1, palavras[i]);
                }
            }
        }
    }while(1);

}