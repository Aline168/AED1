#include <stdio.h>
#include <stdlib.h>

void insercao (int n, double v[])
{
    int i, j, x;
    for (j = 1; j < n; j++)
    {
        x = v[j];
        for (i = j-1; i >= 0 && v[i] > x; i--){
            v[i+1] = v[i];
        }
            v[i+1] = x;
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

        insercao(N,vetor);

        for(int j=0; j<N; j++)
        {
            printf("%d\t", vetor[j]);
        }
        printf("\n");
    }

    return 0;
}
