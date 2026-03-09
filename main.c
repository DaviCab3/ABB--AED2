#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ARVORE.h"

int main() {

    ArvBin* raiz = criaArv();

    struct Municipio municipios[10] = {
        {"Uberlandia", 4115.0, 706597},
        {"Araguari", 2729.0, 117445},
        {"Ituiutaba", 2598.0, 105255},
        {"Patos de Minas", 3189.0, 153585},
        {"Belo Horizonte", 331.4, 2521564},
        {"Contagem", 195.3, 668949},
        {"Montes Claros", 3568.0, 413487},
        {"Juiz de Fora", 1436.0, 573285},
        {"Uberaba", 4523.0, 341824},
        {"Varginha", 395.4, 136602}
    };

    for (int i = 0; i < 10; i++) {
        insere_ArvBin(raiz, municipios[i]);
    }

    printf("\n===== CIDADES EM ORDEM ALFABETICA =====\n\n");
    mostrarCidadesEmOrdem(*raiz);

    int total = contarMunicipios(*raiz);
    printf("Total de municipios cadastrados: %d\n\n", total);

    float areaTotal = somaAreaTotal(*raiz);
    float percentual = percentualAreaBrasil(areaTotal);

    printf("Area total cadastrada: %.2f km²\n", areaTotal);
    printf("Percentual do territorio brasileiro: %.4f%%\n\n", percentual);

    struct Municipio maior = cidadeMaiorPopulacao(*raiz);

    printf("===== CIDADE COM MAIOR POPULACAO =====\n");
    printf("Nome: %s\n", maior.nome);
    printf("Populacao: %d\n\n", maior.populacao);

    int X = 500000;
    printf("===== CIDADES COM POPULACAO MAIOR QUE %d =====\n", X);
    mostrarPopulacaoMaiorQue(*raiz, X);

    printf("\n===== DENSIDADE POPULACIONAL =====\n");
    mostrarDensidade(*raiz);

    // ===============================
    // BUSCA
    // ===============================

    ArvBin resultado = buscarMunicipio(*raiz, "Uberlandia");

    if (resultado != NULL)
        printf("\nMunicipio encontrado: %s\n", resultado->dados.nome);
    else
        printf("\nMunicipio nao encontrado\n");

    // ===============================
    // REMOÇÃO
    // ===============================

    *raiz = removerMunicipio(*raiz, "Uberaba");

    printf("\nDepois da remocao:\n");
    mostrarCidadesEmOrdem(*raiz);

    // ===============================
    // MEDIA POPULACIONAL
    // ===============================

    printf("\nMedia populacional: %.2f\n", mediaPopulacao(*raiz));

    // ===============================
    // LIBERAR MEMORIA
    // ===============================

    liberarArvore(*raiz);
    free(raiz);

    return 0;
}

