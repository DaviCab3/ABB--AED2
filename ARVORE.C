#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ARVORE.h"

//  Criar árvore

ArvBin* criaArv (){
    ArvBin* raiz = (ArvBin*) malloc (sizeof(ArvBin));
    if (raiz !=NULL)
        *raiz = NULL;
    return raiz;

}


//   Inserir município (Ordenado pelo nome )


int insere_ArvBin (ArvBin* raiz , struct Municipio m){
    if (raiz == NULL)
        return 0;
        // Novo no

    struct NO* novo ;
    novo = (struct NO*) malloc (sizeof(struct NO));
    if (novo == NULL)
        return 0;
    novo -> dados = m;
    novo -> dir = NULL;
    novo -> esq = NULL;

    //   procurando onde inserir

         if (*raiz ==NULL){
            *raiz = novo;
            return 1;  // primeiro elemente
       } 
            struct NO* atual = *raiz;
            struct NO* ant = NULL;
        
            while (atual !=NULL) { // navega ate o chegar em um nó folha
                ant = atual;
                if (strcmp (m.nome, atual->dados.nome)== 0){
                    free (novo);
                    return 0;
                }
                if (strcmp ( m.nome , atual->dados.nome)<0)
                    atual = atual->esq;
                else
                    atual = atual->dir;
            }
               if (strcmp (m.nome , ant ->dados.nome)>0)  // insere elemento como filho do nó folha
                ant ->dir = novo;
               else
                ant -> esq = novo;
        

        return 1;
}


void emOrdem( ArvBin raiz){
    if (raiz !=NULL){
        emOrdem(raiz->esq);
        printf("%s\n", raiz->dados.nome);
        emOrdem(raiz->dir);

    }

}


void liberarArvore (ArvBin raiz){
    if (raiz !=NULL){
        liberarArvore(raiz->esq);
        liberarArvore(raiz->dir);
        free(raiz);
    }
}

int contarMunicipios (ArvBin raiz){
    if ( raiz == NULL)
        return 0;
    return 1
                +contarMunicipios(raiz->esq)
                +contarMunicipios(raiz->dir);
}

void mostrarPopulacaoMaiorQue(ArvBin raiz, int X ){
    if(raiz!= NULL) {
        mostrarPopulacaoMaiorQue(raiz->esq,X);
        if(raiz->dados.populacao > X){
            printf("%s\n",raiz->dados.nome);
        }
        mostrarPopulacaoMaiorQue(raiz->dir,X);
    }




}
void mostrarDensidade(ArvBin raiz){
    if (raiz != NULL){
         mostrarDensidade(raiz->esq);
         printf(" %s:%f\n",
                 raiz->dados.nome,
                 raiz->dados.populacao/raiz->dados.area);


        mostrarDensidade(raiz->dir);
    }

}

float somaAreaTotal(ArvBin raiz) {
    if (raiz == NULL)
        return 0;

    return raiz->dados.area
         + somaAreaTotal(raiz->esq)
         + somaAreaTotal(raiz->dir);
}


float percentualAreaBrasil(float areaTotal) {
    return (areaTotal / 8510000.0) * 100;
}


void mostrarCidadesEmOrdem(ArvBin raiz) {
    if (raiz != NULL) {
        mostrarCidadesEmOrdem(raiz->esq);

        float densidade = raiz->dados.populacao / raiz->dados.area;

        printf("Nome: %s\n", raiz->dados.nome);
        printf("Área: %.3f km²\n", raiz->dados.area);
        printf("População: %d\n", raiz->dados.populacao);
        printf("Densidade: %.2f hab/km²\n\n", densidade);

        mostrarCidadesEmOrdem(raiz->dir);
    }
}



struct Municipio cidadeMaiorPopulacao(ArvBin raiz) {
    struct Municipio maior;

    // caso base (árvore vazia)
    if (raiz == NULL) {
        struct Municipio vazio;
        vazio.populacao = -1; // sentinela
        return vazio;
    }

    // maior começa sendo o nó atual
    maior = raiz->dados;

    // verifica esquerda
    struct Municipio esq = cidadeMaiorPopulacao(raiz->esq);
    if (esq.populacao > maior.populacao) {
        maior = esq;
    }

    // verifica direita
    struct Municipio dir = cidadeMaiorPopulacao(raiz->dir);
    if (dir.populacao > maior.populacao) {
        maior = dir;
    }

    return maior;
}

