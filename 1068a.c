#include <stdio.h>
#include <stdlib.h>

#define tamanho 1000

typedef struct
{
    char vetor[tamanho];
    int topo;

} pilha;

void empilha(int valor, pilha *p);
void desempilha(pilha *p);
int isvazia(pilha*p);
void imprimepilha(pilha*p);
void inicializa(pilha *p);

void empilha(int valor, pilha *p) //push
{

    if(p-> topo < tamanho)
    {

        p-> vetor[p-> topo]=valor;
        p-> topo++;
    }

    else
    {

        printf("Nao ha espaco");
    }
}

void desempilha(pilha *p) //pop
{
    if (p->topo >= 0)
    {
        int valor = p->vetor[p->topo];
        p->topo--;
        //  printf("Elemento retirado %d\n", valor); // mostra na tela
    }
    else
    {
        printf("A pilha está vazia\n");
    }

}
int isvazia(pilha*p)
{
    return p->topo==-1;
}

void imprimepilha(pilha*p)
{

    for(int i= (p -> topo-1); i>=0; i--)
    {
        printf("%02d\n", p->vetor[i]);

    }


}

void inicializa(pilha *p)
{
    p->topo = -1;
}
int verifica(char exp[])
{
    pilha p;
    inicializa(&p);

    for(int i=0; exp[i] !='\0'; i++)
    {
        if(exp[i] == '(')
        {

            empilha('(',&p);

        }
        else if(exp[i]==')')
        {

            if(isvazia(&p))
            {

                return 0;

            }
            desempilha(&p);
        }
    }
    return isvazia(&p);

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

