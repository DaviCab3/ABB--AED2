#ifndef ARVORE_H
#define ARVORE_H



struct Municipio {
 char nome[100];
 float area; // em km²
 int populacao;
};

struct NO {
 struct Municipio dados;
 struct NO *esq;
 struct NO *dir;
};

typedef struct NO * ArvBin;

ArvBin* criaArv();
int insere_ArvBin(ArvBin* raiz, struct Municipio m);
void emOrdem(ArvBin raiz);
void liberarArvore(ArvBin raiz);



int contarMunicipios(ArvBin raiz);
float somaAreaTotal(ArvBin raiz);
float percentualAreaBrasil(float areaTotal);

void mostrarCidadesEmOrdem(ArvBin raiz);
void mostrarPopulacaoMaiorQue(ArvBin raiz, int X);
void mostrarDensidade(ArvBin raiz);

struct Municipio cidadeMaiorPopulacao(ArvBin raiz);
ArvBin buscarMunicipio(ArvBin raiz, char nome[]);
ArvBin removerMunicipio(ArvBin raiz, char nome[]);
float mediaPopulacao(ArvBin raiz);


#endif

