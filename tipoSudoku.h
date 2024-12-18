#ifndef TIPOSUDOKU_H
#define TIPOSUDOKU_H

#define TAM 9

/*
    ESTRUTURA DO SUDOKU
    Foi decidido utilizar matrizes indexadas para representar o jogo e sua resposta
    porque assim o preenchimento das matrizes ocorre com acessos em tempo constante
    às posições da matriz.
*/
typedef struct rotSudoku {
    int sudoku[TAM][TAM];
    int resposta[TAM][TAM];
} tipoSudoku;

extern tipoSudoku* preencherSudoku(tipoSudoku *jogo, const char *linha);
extern void imprimirSudoku(tipoSudoku *sudoku);

#endif // TIPOSUDOKU_H