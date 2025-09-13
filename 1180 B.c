#include <stdio.h>

int main()
{

    int N;

    scanf("%d", &N);

    int x[N];
    int i;
    for(i=0; i<N; i++)
    {
        scanf("%d", &x[i]);
    }

    int *p = &x[0];
    int posicao= 0;

    for(i=0; i<N; i++)
    {
        if(x[i]< *p)
        {
            *p = x[i];
            posicao = i;
        }
    }
    printf("Menor valor: %d\n", *p);
    printf("Posicao: %d\n", posicao);

    return 0;
}
