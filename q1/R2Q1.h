#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>


typedef struct no{
    struct no* esq;
    int nun;
    struct no* dir;
    int alt;
}no;

typedef no* avbin;

typedef struct saida{
    int valor;
    int alt;
    int ant;
}saida;

avbin* criaArvore();
no* percorre(no* atual, int valor, no* ant, int alt);
saida inserir(avbin* raiz, FILE* arq, int valor);
void destruirNo(no* no);
void destruirArvore(avbin* raiz);