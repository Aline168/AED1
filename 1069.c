#include <stdio.h>
#include <stdlib.h>

#define tamanho 1000

typedef struct
{
    char vetor[tamanho];
    int topo;
} pilha;

void empilha(char valor, pilha *p)
{
    if (p->topo < tamanho - 1)
    {
        p->topo++;
        p->vetor[p->topo] = valor;
    }
}

void desempilha(pilha *p)
{
    if (p->topo >= 0)
    {
        p->topo--;
    }
}

int isvazia(pilha *p)
{
    return p->topo == -1;
}

void inicializa(pilha *p)
{
    p->topo = -1;
}

int verifica(char exp[])
{
    int i =0;
    int contador=0;
    pilha p;
    inicializa(&p);

    for ( i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '<')
        {
            empilha('<', &p);

        }
        else if (exp[i] == '>')
        {
            if (!isvazia(&p))
            {

                desempilha(&p);
                contador++;

            }

        }

    }
    return contador;
}

int main()
{
    int contagem;
    int N=0;
    char expressao[1000];

    scanf("%d",&N);

    for(int i=0; i<N; i++)
    {
        scanf("%s", expressao);

        contagem = verifica(expressao);
        printf("%d\n", contagem);
    }


    return 0;
}
