#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define N 9
int **alocasudoku()
{
    int **matriz = (int**) malloc(N * sizeof(int*));

    if(!matriz)
    {
        printf("Erros ao alocar memoria\n");
        exit(1);
    }

    for (int i = 0; i < N; i++)
    {
        matriz[i] = (int*) malloc(N * sizeof(int));
        if (!matriz[i])
        {
            printf("Erro ao alocar memoria!\n");
            exit(1);
        }

    }
    return matriz;
}

void liberasudoku(int **matriz)
{
    for (int i = 0; i < N; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

bool verifica_linha(int **sudoku, int linha)
{
    bool presente[10] = {false};
    for (int j = 0; j < 9; j++)
    {
        int num = sudoku[linha][j];
        if (num < 1 || num > 9 || presente[num]) return false;
        presente[num] = true;
    }
    return true;
}

bool verifica_coluna(int **sudoku, int coluna)
{
    bool presente[10] = {false};
    for (int i = 0; i < 9; i++)
    {
        int num = sudoku[i][coluna];
        if (num < 1 || num > 9 || presente[num]) return false;
        presente[num] = true;
    }
    return true;
}

bool verifica_submatriz(int **sudoku, int inicio_linha, int inicio_coluna)
{
    bool presente[10] = {false};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int num = sudoku[inicio_linha + i][inicio_coluna + j];
            if (num < 1 || num > 9 || presente[num]) return false;
            presente[num] = true;
        }
    }
    return true;
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int instancia = 1; instancia <= n; instancia++)
    {
        int **sudoku= alocasudoku();


        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                scanf("%d", &sudoku[i][j]);
            }
        }

        bool valido = true;


        for (int i = 0; i < N && valido; i++)
        {
            if (!verifica_linha(sudoku, i) || !verifica_coluna(sudoku, i))
            {
                valido = false;
            }
        }


        for (int i = 0; i < N && valido; i += 3)
        {
            for (int j = 0; j < N && valido; j += 3)
            {
                if (!verifica_submatriz(sudoku, i, j))
                {
                    valido = false;
                }
            }
        }

        printf("Instancia %d\n", instancia);
        if (valido)
        {
            printf("SIM\n\n");
        }
        else
        {
            printf("NAO\n\n");
        }

        liberasudoku(sudoku);
    }

    return 0;
}
