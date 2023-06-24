#include "R2Q1.h"

int main()
{
    FILE* arqIn = fopen("L2Q1.in", "r");
    FILE* arqOut = fopen("L2Q1.out", "w");
    if(arqOut == NULL || arqIn == NULL){
        printf("ERRO AO ABRIR ARQUIVOS");
        return 0;
    }
    avbin* raiz = criaArvore();
    char linha[256], *token;
    int nun, ant, cont = 0;
    saida output, maior;
    maior.valor = 0;
    while(fgets(linha, 256, arqIn) != NULL){
        token = strtok(linha, " ");
        if(cont != 0)
            fprintf(arqOut, "\n");
        while(token != NULL){
            nun = atoi(token);
            output = inserir(raiz, arqOut, nun);
            token = strtok(NULL, " ");
            if(maior.valor < output.valor){
                maior.valor = output.valor;
                maior.alt = output.alt;
                maior.ant = ant;
            }
            ant = nun;
        }
        fprintf(arqOut, " max %d alt %d pred %d", maior.valor, maior.alt, maior.ant);
        cont++;
        maior.valor = 0;
        destruirArvore(raiz);
        avbin* raiz = criaArvore();
    }
    destruirArvore(raiz);
    return 0;
}