#include <stdio.h>
#include <string.h>



int contalinhas(char *pesq){
    FILE *arqCL; //Arquivo conta linhas

    char c, letra = '\n'; 
    int contaLinha;

    arqCL = fopen(pesq, "r"); //Abrindo arquivo solicitado pelo usuário
    if(arqCL != NULL){
    while(fread (&c, sizeof(char), 1, arqCL)) {
        if(c == letra) {
            contaLinha++;
        }
    } 
    }else{
        printf("Erro no arquivo");
        return 0;
    }
    fclose(arqCL);
    return (contaLinha+1); //+1 pois a quantidade de \n é igual a linhas-1

}


int main(){
    
    const int MAX = 172; //A maior palavra do mundo tem 173 letras
    char pesq[MAX];
    printf("Nome do arquivo a ser pesquisado: ");
    scanf("%s", pesq);

    int nlinhas = contalinhas(pesq);
 
    FILE *arq;
    FILE *uarq;
    //FILE *tarq;
    int i, j, k, tam, tam1;
    char palavras[nlinhas][MAX];
    char buffer[nlinhas][MAX];
    char *resul;
    char dicpalavra[MAX];

    //tarq = fopen("meutexto.txt", "a+b");
    uarq = fopen(pesq, "r");
    arq = fopen("dic.txt", "r");

    while (!feof(arq)){
        fgets(dicpalavra, MAX, arq);
        tam = strlen(dicpalavra);
        for (i=0; i<tam; i++){ //Convertendo palavras do dic em CapsLock
            dicpalavra[i] = toupper(dicpalavra[i]); 
        } 
    }
        //     for(i=0;i<nlinhas;i++){ //Mostra todas as palavras do arquivo
        //     resul = fgets(*buffer,MAX,uarq); //(ponteiro que irá armazenar, tamanho máximo da palavra, arquivo destino)
        //     strcpy(palavras[i], *buffer); //Copiando do ponteiro que armazenou para o vetor de palavras
        //     tam1 = strlen(palavras);
        //     for (k=0; k<nlinhas; k++){ //Convertendo palavras do arquivo em CapsLock
        //         //printf("linha: %d\n", k);
        //         for(j=0;j<tam1; j++){
        //             palavras[k][j] = toupper(palavras[k][j]); 
        //             //printf("COLUNA: %d\n", j);
        //         }
        //         printf("%s", palavras);

        //     }
            
        //     //fputs(palavras,tarq);

        // }

}