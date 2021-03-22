#include <stdio.h>
#include <string.h>



int contalinhas(char *pesq){
    FILE *arqCL; //Arquivo conta linhas

    char c, letra = '\n'; 
    int contaLinha;

    arqCL = fopen(pesq, "r"); //Abrindo arquivo solicitado pelo usuário

    while(fread (&c, sizeof(char), 1, arqCL)) {
        if(c == letra) {
            contaLinha++;
        }
    } 

    return (contaLinha+1); //+1 pois a quantidade de \n é igual a linhas-1

}

int main(){
    
    const int MAX = 173; //A maior palavra do mundo tem 173 letras
    char pesq[MAX];
    printf("Nome do arquivo a ser pesquisado: ");
    scanf("%s", pesq);

    int nlinhas;
    nlinhas = contalinhas(pesq);
    printf("%d", nlinhas);
}