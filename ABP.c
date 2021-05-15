#include <stdio.h>
#include <stdlib.h>
#include "ABP.h"



struct NO{
    int Chave; 
    struct NO *pEsq, *pDir;
    int FatBal;
    int altura;
    void *v;
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
    printf("Árvore limpa com sucesso\n");
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

//Exibe a árvore em forma crescente
//Vai para nó folha esquerda, nó, nó folha direita
void arvCrescente(ArvBin *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        arvCrescente(&((*raiz)->pEsq));
        printf("\nChave: %d", (*raiz)->Chave);
        printFatorBalanceamento(*raiz);
        arvCrescente(&((*raiz)->pDir));
    }
}

void percorreBalanceamento(ArvBin *raiz, struct NO *no){
    if(raiz == NULL){
        printf("\nArvore nao existe!!");
        return;
    }
    if(*raiz != NULL){
        percorreBalanceamento(&((*raiz)->pEsq), no);
        no->FatBal = fatorBalanceamento(*raiz);
        percorreBalanceamento(&((*raiz)->pDir), no);
    }
    printf("\nFator de balanceamento calculado com sucesso!");
    printf("\nPressione qualquer tecla para continuar.");
    getchar();
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

int fatorBalanceamento (struct NO *no){
  int esquerda = 0;
  int direita = 0;

  if (no->pDir != NULL) {
    direita = altura(no->pDir)+1;
  }

  if (no->pEsq != NULL) {
    esquerda = altura(no->pEsq)+1;
  }

  return esquerda - direita;
}

int altura(struct NO* no) {
  int contDireita = 0, contEsquerda = 0;

  if (no != NULL) {
    if(no->pEsq != NULL){
      contEsquerda = altura(no->pEsq) + 1;

    }
    if(no->pDir != NULL){
      contDireita = altura(no->pDir) + 1;
    }
  }

  if(contEsquerda > contDireita){
    return contEsquerda;
  }
  else{
    return contDireita;
  }
  
}

void printFatorBalanceamento(struct NO* no){
  int fator;
  fator = fatorBalanceamento(no);
  printf("\nFator de Balanceamento: %d", fator);
}

