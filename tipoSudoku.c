#include <stdio.h>
#include <stdlib.h>
#include "tipoSudoku.h"

tipoSudoku* preencherSudoku(tipoSudoku *jogo, const char *linha) {
    // Ponteiro para a primeira parte (puzzle)
    const char *p = linha;

    // Preenche a primeira matriz (sudoku)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            jogo->sudoku[i][j] = *p++ - '0';
        }
    }

    // Ponteiro para a segunda parte (solution), posição após a vírgula (linha + 82)
    p = linha + 82;

    // Preenche a segunda matriz (resposta)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            jogo->resposta[i][j] = *p++ - '0';
        }
    }

    return jogo;
}

void imprimirSudoku(tipoSudoku *sudoku) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", sudoku->sudoku[i][j]);
        }
        printf("\n");
    }
}
