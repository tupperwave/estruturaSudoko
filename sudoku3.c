#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 9
#define TOTAL_NUMS 81

// Estrutura do Sudoku (apenas strings para simplificação)
typedef struct {
    char puzzle[TOTAL_NUMS + 1];
    char solucao[TOTAL_NUMS + 1];
} tipoSudoku;

// Função para carregar Sudokus do arquivo
int carregarSudokus(const char *nomeArquivo, tipoSudoku **sudokus) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    char linha[200];
    fgets(linha, sizeof(linha), arquivo); // Ignorar cabeçalho

    int count = 0, capacidade = 10; // capacidade inicial do vetor
    *sudokus = malloc(capacidade * sizeof(tipoSudoku));
    if (*sudokus == NULL) {
        perror("Erro ao alocar memória");
        fclose(arquivo);
        exit(EXIT_FAILURE);
    }
    // começa o vetor com 10 elementos e vai dobrando a capacidade conforme necessário
    while (fgets(linha, sizeof(linha), arquivo)) {
        if (count >= capacidade) {
            capacidade *= 2;
            *sudokus = realloc(*sudokus, capacidade * sizeof(tipoSudoku));
            if (*sudokus == NULL) {
                perror("Erro ao redimensionar memória");
                fclose(arquivo);
                exit(EXIT_FAILURE);
            }
        }
        // lê a linha e armazena em puzzle e solucao
        sscanf(linha, "%81[^,],%81[^\"]", (*sudokus)[count].puzzle, (*sudokus)[count].solucao);
        count++;
    }

    fclose(arquivo);
    return count;
}

// Função para converter uma string de 81 caracteres para uma matriz 9x9
// converte por meio de subtração de '0' para obter o valor numérico
void stringParaMatriz(const char *str, int matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            matriz[i][j] = str[i * TAM + j] - '0';
        }
    }
}

// Função de busca sequencial no array
const char *buscarSudoku(tipoSudoku *sudokus, int count, const char *entrada) {
    for (int i = 0; i < count; i++) {
        if (strcmp(sudokus[i].puzzle, entrada) == 0) {
            return sudokus[i].solucao;
        }
    }
    return NULL;
}

int main() {
    tipoSudoku *sudokus;
    int totalSudokus = carregarSudokus("sudoku.csv", &sudokus);

    // Solicitar entrada do usuário
    char entrada[TOTAL_NUMS + 1];
    printf("Digite o Sudoku completo (81 dígitos): ");
    scanf("%s", entrada);

    // Buscar o Sudoku
    const char *solucao = buscarSudoku(sudokus, totalSudokus, entrada);
    while (solucao == NULL) {
        printf("Sudoku não encontrado. Tente novamente.\n");
        printf("Digite o Sudoku completo (81 dígitos): ");
        scanf("%s", entrada);
        solucao = buscarSudoku(sudokus, totalSudokus, entrada);
    }

    // Exibir a solução como matriz 9x9
    printf("Sudoku encontrado!\nSolução:\n");
    int matriz[TAM][TAM];
    stringParaMatriz(solucao, matriz);
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Liberar memória
    free(sudokus);

    return 0;
}
