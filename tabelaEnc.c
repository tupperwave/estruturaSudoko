#include <stdio.h>
#include <stdlib.h>
#include "tabelaEnc.h"

static int qOperacoes = 0;

void inicializarTabela(tipoTabela **tabela) {
    *tabela = NULL;
}

void destruirTabela(tipoTabela *tabela) {
    tipoTabela *aux;

    while (tabela != NULL) {
        aux = tabela;
        tabela = tabela->prox;
        free(aux);
    }
}

// Existe a necessidade de alocar novos nohs dinamicamente?
// Há uma maneira mais eficiente do que essa?
void inserirElementoTab(tipoTabela **tabela, tDado *jogo) {
    tipoTabela *novo = malloc(sizeof(tipoTabela));
    qOperacoes++;
    if (!novo) {  
        printf("qOperacoes: %d\n", qOperacoes);
        puts("Erro ao alocar novo elemento.");
        destruirTabela(*tabela);
        exit(1);
    }
    novo->sudoku = *jogo;   // Coloca o jogo no novo noh
    novo->prox = *tabela;   // Coloca o novo no inicio da tabela
    *tabela = novo;         // Faz a tabela apontar para o novo primeiro noh
}

tDado* removerElementoTab(tipoTabela **tabela, int matriz[TAM][TAM]) {
    //
}

tDado* buscarElementoTab(tipoTabela *tabela, int matriz[TAM][TAM]){
    //
}

int quantOperacoes(){
    return qOperacoes;
}