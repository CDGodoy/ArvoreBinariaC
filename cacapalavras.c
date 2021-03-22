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
    FILE *tarq;
    int i, j, k, tam, tam1, l=0, contador = 0, Linha =1;
    char palavras[MAX][MAX];
    char buffer[nlinhas][MAX];
    char resul[nlinhas];
    char dicpalavra[MAX];
    char ch;
    int qt=0;
    tarq = fopen("meutexto.txt", "w");
    uarq = fopen(pesq, "r");
    if (uarq == NULL){
        printf("Erro ao abrir o arquivo");
        return(0);
    }
    arq = fopen("dic.txt", "r");

    while (!feof(arq)){
        fgets(dicpalavra, MAX, arq);
        dicpalavra[strlen(dicpalavra)-1] = dicpalavra[strlen(dicpalavra)]; //Retira o \0 do fgets
        tam = strlen(dicpalavra);
        for (i=0; i<tam; i++){ //Convertendo palavras do dic em CapsLock
            dicpalavra[i] = toupper(dicpalavra[i]); 
        }
        qt = 0;
        //printf("%s", dicpalavra);        
        //dicpalavra é a palavra a ser pesquisada no texto

        while(fscanf(uarq, "%s",palavras[contador]) != EOF || fscanf(uarq,"%c",&ch)!=EOF){
            if(ch=='\n')Linha++;
            tam1 = strlen(palavras[contador]);
            for (i=0; i<tam1; i++){ //Convertendo palavras do dic em CapsLock
                palavras[contador][i] = toupper(palavras[contador][i]); 
            }
            if (strcmp(palavras[contador],dicpalavra)==0){
                qt++;
                printf("A palavra %s está no texto\n", palavras[contador]);
            }else
                contador++;
        }
        printf("A palavra %s foi encontrada %d no texto\n", dicpalavra,qt);


        // while (!feof(uarq)){
        //     for (i=0; i<nlinhas; i++){
 
        //         fgets(*buffer, MAX, uarq);
        //         strcpy(palavras[i], *buffer);
        //         tam1 = strlen(palavras[i]);
        //         for (j=0; j<tam1; j++){
        //             palavras[i][j] = toupper(palavras[i][j]);
                    
        //         }



        //         // printf("dicpalavra = %s", dicpalavra);
        //         // printf("\npalavras[i] %s", palavras[i]);
        //         // if (strstr(palavras[i],dicpalavra)){
        //         //     printf("----------verdadeiro-------------\n");
        //         //     l++;

        //         //     //fprintf(tarq,"%s %d\n",dicpalavra,l);
        //         // }
        //         //printf("%s", palavras[i]);
                
        //     }
            
        //     //printf("%s", buffer);

        // }

        //fputs(dicpalavra, tarq); //Escrevendo em outro arquivo com tudo em maiúsculo
        
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


    fclose(arq);
    fclose(uarq);
    fclose(tarq);
}