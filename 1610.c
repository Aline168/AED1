#include <stdio.h>
#include <stdlib.h>

#define MAX 10005

typedef struct No {
    int v;
    struct No *prox;
} No;

No* lista[MAX];
int visitando[MAX]; 
int deuLoop;
int N, M;

void analisar(int x) {
    visitando[x] = 1;  

    for (No *p = lista[x]; p != NULL; p = p->prox) {
        int y = p->v;

        if (visitando[y] == 1) { 
            deuLoop = 1;
            return;
        }

        if (visitando[y] == 0) { 
            analisar(y);
            if (deuLoop) return;
        }
    }

    visitando[x] = 2;  
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {

        scanf("%d %d", &N, &M);

        for (int i = 1; i <= N; i++) {
            lista[i] = NULL;
            visitando[i] = 0;
        }

        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);

            No* novo = (No*) malloc(sizeof(No));
            novo->v = B;
            novo->prox = lista[A];
            lista[A] = novo;
        }

        deuLoop = 0;

        for (int i = 1; i <= N && !deuLoop; i++) {
            if (visitando[i] == 0) {
                analisar(i);
            }
        }

        if (deuLoop)
            printf("SIM\n");
        else
            printf("NAO\n");
    }

    return 0;
}
