#include <stdio.h>
#include <stdlib.h>
#include "ABP.h"


void lerCSV(){
    FILE* arquivo;
    char arqCSV[100];
    cabecalho();
    printf("\nInsira o nome do arquivo CSV a ser lido: ");
    scanf("%s", arqCSV);

    arquivo = fopen(arqCSV, "r");
    getchar();

    if(arquivo == NULL){
        printf("Erro, arquivo não foi aberto");
    }else{
        printf("Arquivo aberto com sucesso!");
    }

    char *token;
    const char s[2] = ",";
    
    //token = strtok(arquivo, s);

    while(token != NULL){
        printf("%s\n", token);
    }

    fclose(arquivo);
}


void cabecalho(){
    system("clear");
    printf("\n=======ARVORE BINÁRIA DE BUSCA==========");
}
void menuPrincipal(){
    printf("\nSELECIONE A OPCAO DESEJADA:");
    printf("\n1 - GERAR ABP A PARTIR DE UM ARQUIVO");
    printf("\n2 - CALCULAR FATOR DE BALANCEAMENTO DA ABP");
    printf("\n3 - MOSTRAR ABP");
    printf("\n4 - SAIR\n");
}

struct NO{
    int Chave; 
    struct NO *pEsq, *pDir;
    int FatBal;
};

//Cria a árvore caso não exista, para isso, 
//se cria a raiz da árvore apontando para NULL
ArvBin* criaABP(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL){
        *raiz = NULL;
    }
    return raiz;
}

//Percorre a árvore de forma recursiva liberando 
//cada um dos seus nós
void liberaNo(struct NO* no){
    if(no == NULL){
        return;
    }
    liberaNo(no->pEsq);
    liberaNo(no->pDir);
    free(no);
    no = NULL;
}

//Verifica se a raiz é nula, caso contrário, 
//chama a liberaNo
void liberaABP(ArvBin *raiz){
    if(raiz == NULL){
        return;
    }
    liberaNo(*raiz);
    free(raiz);
}

//Para verificar se a árvore está vazia
//Se ela estiver vazia, retorna 1, caso contrário, 0
int verificaArv(ArvBin *raiz){
    if(raiz == NULL){
        return 1;
    }
    if(*raiz == NULL){
        return 1;
    }
    return 0;
}

//Calcula a altura da arvore, é recursiva.
//Percorre cada nó folha até que encontre um nó sem filhos
//A altura da árvore é a altura do maior laço + 1
int alturaArv(ArvBin *raiz){
    if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 0;
    }
    int alt_esq = alturaArv(&((*raiz)->pEsq));
    int alt_dir = alturaArv(&((*raiz)->pDir));
    if(alt_esq > alt_dir){
        return (alt_esq + 1);
    }else{
        return(alt_dir + 1);
    }
}

//Funciona como a alturaArv, percorre e conta cada nó
//O total de nós é a altura da esquerda + altura da direita + 1
int totalDeNos(ArvBin *raiz){
    if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 0;
    }
    int alt_esq = totalDeNos(&((*raiz)->pEsq));
    int alt_dir = totalDeNos(&((*raiz)->pDir));
    return (alt_esq + alt_dir + 1);
}

//Exibe a árvore em forma crescente
//Vai para nó folha esquerda, nó, nó folha direita
void arvCrescente(ArvBin *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        arvCrescente(&((*raiz)->pEsq));
        printf("\n%d", (*raiz)->Chave);
        arvCrescente(&((*raiz)->pDir));
    }
}

//Insere os elementos da árvore sem recursão
int insereArv(ArvBin *raiz, int valor){
    if(raiz == NULL){
        return 0;
    }
    struct NO* novoNo;
    novoNo = (struct NO*) malloc(sizeof(struct NO));
    if(novoNo == NULL){
        return 0;
    }
    novoNo->Chave = valor;
    novoNo->pDir = NULL;
    novoNo->pEsq = NULL;

    //Agora procuramos o lugar em que vamos colocar

    if(*raiz == NULL){
        *raiz = novoNo;
    }else{
        struct NO* atual = *raiz;
        struct  NO* anterior = NULL;
        while(atual != NULL){
            anterior = atual;
            if(valor == atual->Chave){
                free(novoNo);
                return 0; //O valor já existe dentro da arvore
            }
            if(valor > atual->Chave){ //Verificando se o valor irá para a direita ou esquerda
                atual = atual->pDir;
            }else{
                atual = atual ->pEsq;
            }
        }
        if(valor > anterior->Chave){
            anterior->pDir = novoNo;
        }
        else{
            anterior->pEsq = novoNo;
        }    
    }
    return 1;
}