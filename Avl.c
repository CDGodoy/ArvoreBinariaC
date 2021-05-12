#include<stdio.h>
#include<stdlib.h>
#include "Avl.h"

struct NO{
    int info;
    int altura;
    struct NO *esq;
    struct NO *dir;
};

ArvAVL* raiz;

int alt_NO(struct NO* no){
    if(no==NULL)
        return -1;
    else
        return no->altura;
}

int fatorBalanceamento_NO(struct NO* no){
    return labs(alt_NO(no->esq) - alt_NO(no->dir));
}

int maior(int x, int y){
    if(x>y)
        return x;
    else
        return y;
}

void RotacaoLL(ArvAVL *raiz){
    struct NO *no;
    no = (*raiz)->esq;
    (*raiz)->esq = no->dir;
    no->dir = *raiz;
    (*raiz)->altura = maior(altura_NO((*raiz)->esq),
                          altura_NO((*raiz)->dir))
                            + 1;
    no->altura = maior(altura_NO(no->esq),
                        (*raiz)->altura) + 1;
    *raiz = no;
}

//Mesma coisa que a LL mas no outro sentido
void RotacaoRR(ArvAVL *raiz){
    struct NO *no;
    no = (*raiz)->dir;
    (*raiz)->dir = no->esq;
    no->esq = *raiz;
    (*raiz)->altura = maior(altura_NO((*raiz)->esq),
                            altura_NO((*raiz)->dir))
                            + 1;
    no->altura = maior(altura_NO(no->dir),
                        (*raiz)->altura)+1;
}

void RotacaoLR(ArvAVL *raiz){
    RotacaoRR(&(*raiz)->esq);
    RotacaoLL(raiz);
}

void RotacaoRL(ArvAVL *raiz){
    RotacaoLL(&(*raiz)->dir);
    RotacaoRR(raiz);
}

int insere_ArvAVL(ArvAVL *raiz, int valor){
    int res;
    if(*raiz == NULL){
        struct NO *novo;
        novo = (struct NO*)malloc(sizeof(struct NO));
        if (novo == NULL)
            return 0;

        novo->info = valor;
        novo->altura = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return 1;
    }
    struct NO *atual = *raiz;
    if (valor < atual->info){
        if((res=insere_ArvAVL(&(atual->esq), valor))==1){
            if(fatorBalanceamento_NO(atual) >= 2){
                if(valor < (*raiz)->esq->info){
                    RotacaoLL(raiz);
                }else{
                    RotacaoLR(raiz);
                }
            }
        }
    }else{
        if(valor > atual->info){
            if((res=insere_ArvAVL(&(atual->dir), valor))==1){
                if(fatorBalanceamento_NO(atual) >= 2){
                    if((*raiz)->dir->info < valor){
                        RotacaoRR(raiz);
                    }else{
                        RotacaoRL(raiz);
                    }
                }
            }
        }else{
            printf("Valor duplicado!!\n");
            return 0;
        }
    }
    atual->altura = maior(altura_NO(atual->esq),
                            altura_NO(atual->dir)) + 1;
    return res;
}

int remove_ArvAVL(ArvAVL *raiz, int valor){

    if(*raiz == NULL){
        printf("Valor não existe!!\n");
        return 0;
    }
    int res;
    if(valor < (*raiz)->info){
        if((res=remove_ArvAVL(&(*raiz)->esq,valor))==1){
           if(fatorBalanceamento_NO(*raiz) >=2 ){
            if(altura_NO((*raiz)->dir->esq)
                <= altura_NO((*raiz)->dir->dir))
                RotacaoRR(raiz);
            else
                RotacaoRL(raiz);
           } 
        }
    }
    if ((*raiz)->info < valor){
        if((res=remove_ArvAVL(&(*raiz)->dir, valor))==1){
            if(fatorBalanceamento_NO(*raiz) >=2 ){
                if(altura_NO((*raiz)->esq->dir)
                    <= altura_NO((*raiz)->esq->esq))
                    RotacaoLL(raiz);
                else
                    RotacaoLR(raiz);
           } 
        }
    }
    if ((*raiz)->info == valor){
        if(((*raiz)->esq==NULL)||(*raiz)->dir==NULL){
            struct NO *oldNode = (*raiz);
            if((*raiz)->esq !=NULL)
                *raiz = (*raiz)->esq;
            else
                *raiz = (*raiz)->dir;
            free(oldNode);
        }else{//nó tem 2 filhos
            struct NO* temp = procuraMenor((*raiz)->dir);
            (*raiz)->info = temp->info;
            remove_ArvAVL(&(*raiz)->dir, (*raiz)->info);
            if(fatorBalanceamento_NO(*raiz)>=2){
                if(altura_NO((*raiz)->esq->dir)
                    <=altura_NO((*raiz)->esq->esq))
                    RotacaoLL(raiz);
                else
                    RotacaoLR(raiz);
            }
        }
        return 1;
    }
    return res;
}

struct NO* procuraMenor(struct NO* atual){
    struct NO *no1 = atual;
    struct NO *no2 = atual->esq;
    while(no2 !=NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}
