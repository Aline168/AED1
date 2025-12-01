#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int val;
    struct no *prox;
} No;

No* tabela[1010];

int main() {
    int N, M, C, V;

    scanf("%d", &N);

    while (N--) {

        scanf("%d %d", &M, &C);

        for (int i = 0; i < M; i++) {
            tabela[i] = NULL;
        }

        while (C--) {
            scanf("%d", &V);
            int h = V % M;

            No *novo = (No*) malloc(sizeof(No));
            novo->val = V;
            novo->prox = NULL;

            if (tabela[h] == NULL) {
                tabela[h] = novo;
            } else {
                No *p = tabela[h];
                while (p->prox != NULL) p = p->prox;
                p->prox = novo;
            }
        }

        for (int i = 0; i < M; i++) {
            printf("%d -> ", i);

            No *p = tabela[i];
            while (p != NULL) {
                printf("%d -> ", p->val);
                p = p->prox;
            }

            printf("\\\n");
        }

        if (N) printf("\n");
    }

    return 0;
}
