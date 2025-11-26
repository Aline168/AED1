#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10000

int inverter(int n)
{
    int invertido=0;
    while(n>0)
    {
        invertido= invertido* 10 +(n%10);
        n /= 10;
    }

    return invertido;

}
int resolver(int A, int B)
{
    static int dist[MAX + 1];
    static int fila[MAX + 5];

    for (int i = 0; i <= MAX; i++) dist[i] = -1;

    int ini = 0, fim = 0;

    fila[fim++] = A;
    dist[A] = 0;

    while (ini < fim)
    {
        int x = fila[ini++];

        if (x == B) return dist[x];

        if (x + 1 <= MAX && dist[x + 1] == -1)
        {
            dist[x + 1] = dist[x] + 1;
            fila[fim++] = x + 1;
        }

        int y = inverter(x);
        if (y <= MAX && dist[y] == -1)
        {
            dist[y] = dist[x] + 1;
            fila[fim++] = y;
        }
    }
    return -1;
}

int main()
{
    int T = 0;
    int A = 0;
    int B = 0;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d %d", &A, &B);
        printf("%d\n", resolver(A, B));
    }

    return 0;
}
