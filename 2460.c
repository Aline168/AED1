#include <stdio.h>
#include <stdlib.h>

struct Elemento
{
    int num;
    struct Elemento *prox;
};
typedef struct Elemento Elemento;

struct Fila
{
    Elemento *inicio;
    Elemento *fim;
    int qtd;
};
typedef struct Fila Fila;


Fila* cria_Fila()
{
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if (fi != NULL)
    {
        fi->fim = NULL;
        fi->inicio = NULL;
        fi->qtd = 0;
    }
    return fi;
}

int insere_Fila(Fila* fi, int num)
{
    if (fi == NULL)
        return 0;

    Elemento *no = (Elemento*) malloc(sizeof(Elemento));
    if (no == NULL)
        return 0;

    no->num = num;
    no->prox = NULL;

    if (fi->fim == NULL)
        fi->inicio = no;
    else
        fi->fim->prox = no;

    fi->fim = no;
    fi->qtd++;
    return 1;
}


int remove_Fila(Fila* fi, int valor)
{
    if(fi == NULL || fi->inicio == NULL)
        return 0;

    Elemento *ant = NULL;
    Elemento *atual = fi->inicio;

    while(atual != NULL && atual->num != valor)
    {
        ant = atual;
        atual = atual->prox;
    }

    if(atual == NULL)
        return 0;

    if(ant == NULL)
        fi->inicio = atual->prox;
    else
        ant->prox = atual->prox;

    if(atual == fi->fim)
        fi->fim = ant;

    free(atual);
    fi->qtd--;
    return 1;
}
void imprime_Fila(Fila* fi)
{
    if(fi == NULL)
        return;
    Elemento* no = fi->inicio;

    int primeiro = 1;
    while(no != NULL)
    {
        if(!primeiro) printf(" ");
        printf("%d", no->num);
        primeiro = 0;
        no = no->prox;
    }
    printf("\n");
}

int main()
{
    Fila* fi = cria_Fila();
    int M = 0, P = 0, R = 0;

    scanf("%d", &M);
    for (int j = 0; j < M; j++)
    {
        scanf("%d", &P);
        insere_Fila(fi, P);

    }
    scanf("%d",&R);
    for(int i=0; i<R; i++)
    {
        scanf("%d",&P);
        remove_Fila(fi, P);

    }
    imprime_Fila(fi);




    return 0;
}
