#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1024
#define TOT (MAX * MAX)

int N, M;
char matriz[MAX][MAX];
bool visitado[MAX][MAX] = {false};


int filax[TOT];
int filay[TOT];

void BFS(int sx, int sy)
{
    int ini = 0, fim = 0;

    filax[fim] = sx;
    filay[fim] = sy;
    fim++;
    visitado[sx][sy] = true;

    while (ini < fim)
    {
        int x = filax[ini];
        int y = filay[ini];
        ini++;

        int dx[4] = { -1, 1, 0, 0 };
        int dy[4] = { 0, 0, -1, 1 };

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M)
            {
                if (matriz[nx][ny] == '.' && !visitado[nx][ny])
                {
                    visitado[nx][ny] = true;
                    filax[fim] = nx;
                    filay[fim] = ny;
                    fim++;
                }
            }
        }
    }
}

int main()
{
    if (scanf("%d %d", &N, &M) != 2) return 0;

    for (int i = 0; i < N; i++)
    {
        scanf("%s", matriz[i]);
    }

    int cliques = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (matriz[i][j] == '.' && !visitado[i][j])
            {
                cliques++;
                BFS(i, j);
            }
        }
    }

    printf("%d\n", cliques);
    return 0;
}
