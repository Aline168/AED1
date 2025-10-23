#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    char dado;
    struct No *prox;
} No;

void push(char c,No **topo)
{
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = c;
    novo->prox = *topo;
    *topo = novo;
}

int pop(No **topo)
{
    if(*topo != NULL)
    {
        No *temp = *topo;
        *topo = temp->prox;
        free(temp);
    }
}
int isvazia (No *topo)
{
    return topo == NULL;
}
int verifica(char exp[])
{
    No*topo = NULL;
    for(int i=0; exp[i] != '\0'; i++)
    {

        if(exp[i] == '(')
        {

            push('(',&topo);

        }
        else if(exp[i]==')')
        {

            if(isvazia(topo))
            {

                return 0;

            }
            pop(&topo);
        }
    }
    return isvazia(topo);

}

int main()
{

    char expressao[1000];

    printf("digite a expressao\n");
    fgets(expressao,sizeof(expressao),stdin);

    if(verifica(expressao))
    {
        printf("correto");

    }
    else
    {
        printf("incorreto");

    }
    return 0;
}
