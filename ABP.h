#ifndef ABP_H_INCLUDED
#define ABP_H_INCLUDED

void cabecalho();
void menuPrincipal();
typedef struct NO* ArvBin;
ArvBin* criaABP();
void liberaABP(ArvBin *raiz);
void liberaNo(struct NO* no);
int verificaArv(ArvBin *raiz);
int alturaArv(ArvBin *raiz);
int totalDeNos(ArvBin *raiz);
void arvCrescente(ArvBin *raiz);
int insereArv(ArvBin *raiz, int valor);
void lerCSV();

//int alturaNO(struct NO* no);
//void percBalanceamento(ArvBin *raiz);
int fatorBalanceamento (struct NO *no);
#endif

