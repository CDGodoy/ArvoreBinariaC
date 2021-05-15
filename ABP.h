#ifndef ABP_H_INCLUDED
#define ABP_H_INCLUDED

typedef struct NO* ArvBin;
ArvBin* criaABP();
void cabecalho();
void menuPrincipal();
void lerCSV(ArvBin *raiz);
void liberaNo(struct NO* no);
void liberaABP(ArvBin *raiz);
void arvCrescente(ArvBin *raiz);
void percorreBalanceamento(ArvBin *raiz, struct NO *no);
int insereArv(ArvBin *raiz, int valor);
int fatorBalanceamento (struct NO *no);
int altura(struct NO* no);
void printFatorBalanceamento(struct NO* no);

#endif

