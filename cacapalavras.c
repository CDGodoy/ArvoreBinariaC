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
    
    const int MAX = 173; //A maior palavra do mundo tem 173 letras
    char pesq[MAX];
    printf("Nome do arquivo a ser pesquisado: ");
    scanf("%s", pesq);

    int nlinhas = contalinhas(pesq);
 
    FILE *arq;
    int i, j, tam;
    char palavras[nlinhas][MAX];
    char buffer[nlinhas][MAX];
    char *resul;

    char dicpalavra[MAX];

    arq = fopen("dic.txt", "r");

    while (!feof(arq)){
        fgets(dicpalavra, MAX, arq);
        tam = strlen(dicpalavra);
        for (i=0; i<tam; i++){ //Convertendo palavras do dic em CapsLock
            dicpalavra[i] = toupper(dicpalavra[i]); 
        }
        
    }

}