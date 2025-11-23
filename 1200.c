#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NO
{
    char num;
    struct NO *esq, *dir;
};

typedef struct NO* ArvBin;

ArvBin* cria_ArvBin()
{
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL) *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO* no)
{
    if(no == NULL) return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
}

void libera_ArvBin(ArvBin* raiz)
{
    if(raiz == NULL) return;
    libera_NO(*raiz);
    free(raiz);
}

void preOrdem(ArvBin* raiz)
{
    if(raiz == NULL) return;
    if(*raiz != NULL)
    {
        printf("%c", (*raiz)->num);
        preOrdem(&((*raiz)->esq));
        preOrdem(&((*raiz)->dir));
    }
}

void emOrdem(ArvBin* raiz)
{
    if(raiz == NULL) return;
    if(*raiz != NULL)
    {
        emOrdem(&((*raiz)->esq));
        printf("%c", (*raiz)->num);
        emOrdem(&((*raiz)->dir));
    }
}

void posOrdem(ArvBin* raiz)
{
    if(raiz == NULL) return;
    if(*raiz != NULL)
    {
        posOrdem(&((*raiz)->esq));
        posOrdem(&((*raiz)->dir));
        printf("%c", (*raiz)->num);
    }
}

struct NO* remove_atual(struct NO* atual)
{
    struct NO *no1, *no2;

    if(atual->esq == NULL)
    {
        no2 = atual->dir;
        free(atual);
        return no2;
    }

    no1 = atual;
    no2 = atual->esq;

    while(no2->dir != NULL)
    {
        no1 = no2;
        no2 = no2->dir;
    }

    if(no1 != atual)
    {
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }

    no2->dir = atual->dir;
    free(atual);

    return no2;
}

int insere(ArvBin* raiz, char valor)
{
    if(raiz == NULL) return 0;

    struct NO* novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL) return 0;

    novo->num = valor;
    novo->esq = novo->dir = NULL;

    if(*raiz == NULL)
    {
        *raiz = novo;
    }
    else
    {
        struct NO* atual = *raiz;
        struct NO* ant = NULL;

        while(atual != NULL)
        {
            ant = atual;

            if(valor == atual->num)
            {
                free(novo);
                return 0;
            }

            if(valor > atual->num)
                atual = atual->dir;
            else
                atual = atual->esq;
        }

        if(valor > ant->num) ant->dir = novo;
        else ant->esq = novo;
    }

    return 1;
}

int consulta(ArvBin* raiz, char valor)
{
    if(raiz == NULL || *raiz == NULL)
        return 0;

    struct NO* atual = *raiz;

    while(atual != NULL)
    {
        if(valor == atual->num)
            return 1; // achou

        if(valor > atual->num)
            atual = atual->dir;
        else
            atual = atual->esq;
    }

    return 0;
}
int main()
{
    ArvBin* raiz = cria_ArvBin();
    char comando[20];
    char valor;

    while (scanf("%s", comando) != EOF)
    {

        if (strcmp(comando, "I") == 0)
        {
            scanf(" %c", &valor);
            insere(raiz, valor);
        }

        else if (strcmp(comando, "P") == 0)
        {
            scanf(" %c", &valor);
            if (consulta(raiz, valor))
                printf("%c existe\n", valor);
            else
                printf("%c nao existe\n", valor);
        }

        else if (strcmp(comando, "INFIXA") == 0)
        {
            emOrdem(raiz);
            printf("\n");
        }

        else if (strcmp(comando, "PREFIXA") == 0)
        {
            preOrdem(raiz);
            printf("\n");
        }

        else if (strcmp(comando, "POSFIXA") == 0)
        {
            posOrdem(raiz);
            printf("\n");
        }

    }

    return 0;
}
