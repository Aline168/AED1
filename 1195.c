#include <stdio.h>
#include <stdlib.h>

 struct NO{
    int num;
    struct NO *esq, *dir;
};
typedef struct NO* ArvBin;

ArvBin* cria_ArvBin(){
    ArvBin* raiz= (ArvBin*) malloc (sizeof(ArvBin));
    if(raiz !=NULL)
        *raiz=NULL;
    return raiz;
}
int insere(ArvBin* raiz, int valor){
    if(raiz==NULL)
        return 0;
    struct NO* novo;
    novo= (struct NO*) malloc(sizeof(struct NO));
    if(novo== NULL) {
        return 0;
    }
    novo->num = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz ==NULL)
        *raiz= novo;
    else{
        struct NO* atual= *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->num){
                free (novo);
                return 0;

            }
            if(valor > atual-> num){
                atual = atual->dir;
            }
            else{
                atual = atual->esq;
            }

        }
        if(valor > ant->num){
            ant->dir = novo;
        }
        else{
            ant->esq = novo;
        }
    }
    return 1;
}

void preOrdem(ArvBin* raiz){
    if(raiz==NULL)
        return;
    if(*raiz != NULL){
        printf("%d, ", (*raiz)->num);
        preOrdem(&((*raiz)->esq));
        preOrdem(&((*raiz)->dir));


    }
}


void emOrdem(ArvBin* raiz){
    if(raiz==NULL)
        return;
    if(*raiz != NULL){
        emOrdem(&((*raiz)->esq));
        printf("%d, ", (*raiz)->num);
        emOrdem(&((*raiz)->dir));
    }
}

void posOrdem(ArvBin* raiz){
    if(raiz==NULL)
        return;
    if(*raiz != NULL){
        posOrdem(&((*raiz)->esq));
        posOrdem(&((*raiz)->dir));
        printf("%d, ", (*raiz)->num);


    }
}
int main() {
    int C=0;
    int N=0;
    int N2[500];
    int j,i;

    scanf("%d",&C);

    for( i =0; i<C ; i++){
        ArvBin* raiz = cria_ArvBin();
        scanf("%d",&N);
        for(j=0; j<N;j++){
            int valor;
            scanf("%d",&valor);
            insere(raiz,valor);
        }

        printf("Case %d:\n", i+1);
        printf("Pre.:  " );
        preOrdem (raiz);
        printf("\n");
        printf("In..: ");
        emOrdem(raiz);
        printf("\n");
        printf("Post:  ");
        posOrdem(raiz);
        printf("\n");

    }
}
