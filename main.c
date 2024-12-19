#include "tabelaEnc.h"
#include "tipoSudoku.h"
#include <stdio.h>
#include <stdlib.h>

int carregaArquivo(const char *nomeArquivo, tipoTabela **tabela) {
    FILE *fp;
    char linha[165], *sudoku, *resposta;
    int cont;
    tipoSudoku *jogo;

    fp = fopen(nomeArquivo, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    cont = 0;
    while (fgets(linha, 165, fp) != NULL) {
        if (cont == 0) {
            ;
        } else {
            jogo = preencherSudoku(jogo, linha);
            inserirElementoTab(tabela, jogo);
        }
        cont++;
        if (cont == 2000000) {
            break;
        }
    }

    fclose(fp);

    return 0;
}


int main(void) {

    tipoTabela *tabela = NULL;
    inicializarTabela(&tabela);
    carregaArquivo("sudoku.csv", &tabela);
    return 0;
}