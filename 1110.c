#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct
{
    int itens[MAX];
    int inicio, fim;
} Fila;

void inicializar(Fila *f)
{
    f->inicio = 0;
    f->fim = 0;
}

int vazia(Fila *f)
{
    return f->inicio == f->fim;
}

void enqueue(Fila *f, int valor)
{
    if (f->fim < MAX)
    {
        f->itens[f->fim++] = valor;
    }
}

int dequeue(Fila *f)
{
    if (!vazia(f))
    {
        return f->itens[f->inicio++];
    }
    return -1;
}

int main()
{
    int n;

    while (1)
    {
        scanf("%d", &n);
        if (n == 0) break;

        Fila f;
        inicializar(&f);

        for (int i = 1; i <= n; i++)
        {
            enqueue(&f, i);
        }

        printf("Discarded cards:");

        int primeiro = 1;
        while ((f.fim - f.inicio) > 1)
        {

            int descartada = dequeue(&f);
            if (!primeiro) printf(",");
            printf(" %d", descartada);
            primeiro = 0;


            enqueue(&f, dequeue(&f));
        }

        printf("\nRemaining card: %d\n", dequeue(&f));
    }

    return 0;
}
