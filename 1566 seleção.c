#include <stdio.h>
#include <stdlib.h>

void selecao (int n, double v[])
{
    int i, j, min, x;
    for (i = 0; i < n-1; i++)
    {
        min = i;
        for (j = i+1; j < n; j++){
            if (v[j] < v[min]) min = j;
        }
        x = v[i];
        v[i] = v[min];
        v[min] = x;
    }

}
int main ()
{

    int NC;
    int N;
    double vetor[30000];
    scanf("%d",&NC);

    for(int i=0; i<NC; i++)
    {
        scanf("%d",&N);
        for(int j=0; j<N; j++)
        {
            scanf("%d",&vetor[j]);
        }

        selecao(N,vetor);

        for(int j=0; j<N; j++)
        {
            printf("%d\t", vetor[j]);
        }
        printf("\n");
    }

    return 0;
}
