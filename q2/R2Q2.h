#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

typedef struct no{
    struct no* esq;
    struct no* dir;
    int valor;
    int somaDir;
    int somaEsq;
}no;

typedef no* avbin;
avbin* criaArvore();
void destruirNo(no* no);
void destruirArvore(avbin* raiz);
void inserir(avbin* raiz, int valor);
no* percorre(no* atual, no* pai, int valor, int flag);
int* emOrdem(avbin* raiz, FILE* arq, int* retorno);



/*    if(atual != NULL){
        if(valor < atual->valor){
            atual->esq = novo;
            if(atual->dir != NULL)
                atual->soma += atual->dir->valor + valor;
            else
                atual->soma += valor;
        }else if(valor > atual->valor){
            atual->dir = novo;
            if(atual->esq != NULL)
                atual->soma += atual->esq->valor + valor;
            else
                atual->soma += valor;

        }    
    }
*/