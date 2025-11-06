#include <stdio.h>
#include <stdlib.h>

struct NO
{
    int num;
    struct NO *esq, *dir;
};
typedef struct NO* ArvBin;


ArvBin* cria_ArvBin()
{
    ArvBin* raiz= (ArvBin*) malloc (sizeof(ArvBin));
    if(raiz !=NULL)
        *raiz=NULL;
    return raiz;
}
int insere(ArvBin* raiz, int valor)
{
    if(raiz==NULL)
        return 0;
    struct NO* novo;
    novo= (struct NO*) malloc(sizeof(struct NO));
    if(novo== NULL)
        return 0;
    novo->num = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz ==NULL)
        *raiz= novo;
    else
    {
        struct NO* atual= *raiz;
        struct NO* ant = NULL;
        while(atual != NULL)
        {
            ant = atual;
            if(valor == atual->num)
            {
                free (novo);
                return 0;

            }
            if(valor > atual-> num)
            {
                atual = atual->dir;
            }
            else
            {
                atual = atual->esq;
            }

        }
        if(valor > ant->num)
        {
            ant->dir = novo;
        }
        else
        {
            ant->esq = novo;
        }
    }
    return 1;
}

void preOrdem(ArvBin* raiz)
{
    if(raiz==NULL)
        return;
    if(*raiz != NULL)
    {

        preOrdem(&((*raiz)->esq));
        printf("%d\n", (*raiz)->num);
        preOrdem(&((*raiz)->dir));
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
        ArvBin* raiz = cria_ArvBin();
        for(int j=0; j<N; j++)
        {
            int valor ;
            scanf("%d",&valor);
            insere(raiz,valor);
        }

        preOrdem(raiz);
        printf("\n");

    }

    return 0;
}
