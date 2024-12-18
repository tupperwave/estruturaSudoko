#ifndef TABELAENC_H
#define TABELAENC_H

#include "tipoSudoku.h"

typedef tipoSudoku tDado;

/*
    Foi escolhido utilizar uma tabela encadeada para representar a tabela de jogos
    porque o espaço ocupado na memória não é contínuo, facilitando colocar tantos
    dados em memoria.
*/
typedef struct rotTabela{
    tDado sudoku;
    tipoTabela *prox;
} tipoTabela;

extern void inicializarTabela(tipoTabela **tabela);
extern void destruirTabela(tipoTabela **tabela);
extern void inserirElementoTab(tipoTabela **tabela, tDado *jogo);
extern int quantOperacoes();
extern tDado* removerElementoTab(tipoTabela **tabela, int matriz[TAM][TAM]);
extern tDado* buscarElementoTab(tipoTabela *tabela, int matriz[TAM][TAM]);
#endif // TABELAENC_H
