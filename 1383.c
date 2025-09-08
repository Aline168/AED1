#include <stdio.h>
#include <stdbool.h>

bool verifica_linha(int sudoku[9][9], int linha) {
    bool presente[10] = {false};
    for (int j = 0; j < 9; j++) {
        int num = sudoku[linha][j];
        if (num < 1 || num > 9 || presente[num]) return false;
        presente[num] = true;
    }
    return true;
}

bool verifica_coluna(int sudoku[9][9], int coluna) {
    bool presente[10] = {false};
    for (int i = 0; i < 9; i++) {
        int num = sudoku[i][coluna];
        if (num < 1 || num > 9 || presente[num]) return false;
        presente[num] = true;
    }
    return true;
}

bool verifica_submatriz(int sudoku[9][9], int inicio_linha, int inicio_coluna) {
    bool presente[10] = {false};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int num = sudoku[inicio_linha + i][inicio_coluna + j];
            if (num < 1 || num > 9 || presente[num]) return false;
            presente[num] = true;
        }
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int instancia = 1; instancia <= n; instancia++) {
        int sudoku[9][9];
        
        // Leitura da matriz
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &sudoku[i][j]);
            }
        }

        bool valido = true;

        // Verificar linhas e colunas
        for (int i = 0; i < 9 && valido; i++) {
            if (!verifica_linha(sudoku, i) || !verifica_coluna(sudoku, i)) {
                valido = false;
            }
        }

        // Verificar submatrizes 3x3
        for (int i = 0; i < 9 && valido; i += 3) {
            for (int j = 0; j < 9 && valido; j += 3) {
                if (!verifica_submatriz(sudoku, i, j)) {
                    valido = false;
                }
            }
        }

        printf("Instancia %d\n", instancia);
        if (valido) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }
    }

    return 0;
}
