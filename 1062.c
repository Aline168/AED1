#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 1005

typedef struct {
    int vetor[TAMANHO];
    int topo;
} Pilha;

void inicializa_pilha(Pilha *p) {
    p->topo = 0;
}

void empilha(int valor, Pilha *p) {
    if (p->topo < TAMANHO) {
        p->vetor[p->topo] = valor;
        p->topo++;
    }
}

int desempilha(Pilha *p) {
    if (p->topo > 0) {
        p->topo--;
        return p->vetor[p->topo];
    }
    return -1;
}

void simular_reorganizacao(int N, int saida_desejada[TAMANHO]) {

    Pilha p;
    inicializa_pilha(&p);

    int proximo_entrada = 1;
    int i = 0;

    while (i < N) {

        int desejado = saida_desejada[i];

        if (p.topo > 0 && p.vetor[p.topo - 1] == desejado) {
            desempilha(&p);
            i++;
        }

        else if (proximo_entrada <= N) {
            empilha(proximo_entrada, &p);
            proximo_entrada++;
        }

        else {
            printf("No\n");
            return;
        }
    }

    printf("Yes\n");
}

int main() {
    int N;
    int saida[TAMANHO];
    int primeiro_vagao_saida;

    while (scanf("%d", &N) == 1 && N != 0) {

        while (1) {

            if (scanf("%d", &primeiro_vagao_saida) != 1) break;

            if (primeiro_vagao_saida == 0) {
                printf("\n");
                break;
            }

            saida[0] = primeiro_vagao_saida;

            for (int i = 1; i < N; i++) {
                if (scanf("%d", &saida[i]) != 1) break;
            }

            simular_reorganizacao(N, saida);
        }
    }

    return 0;
}

