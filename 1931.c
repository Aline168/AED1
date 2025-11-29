#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CIDADES 10001
#define MAX_HEAP 100001
#define INF INT_MAX

typedef struct No {
    int vizinho;
    int custo_pedagio;
    struct No *prox;
} No;


No *adj[MAX_CIDADES]; 

typedef struct {
    int custo;
    int cidade;
    int paridade;
} ItemFila;

ItemFila min_heap[MAX_HEAP];
int tamanho_heap = 0;

int dist[MAX_CIDADES][2]; 



void troca(ItemFila *a, ItemFila *b) {
    ItemFila temp = *a;
    *a = *b;
    *b = temp;
}

void sobe_heap(int i) {
    while (i > 1 && min_heap[i].custo < min_heap[i/2].custo) {
        troca(&min_heap[i], &min_heap[i/2]);
        i /= 2;
    }
}

void desce_heap(int i) {
    int menor;
    int esq = 2 * i;
    int dir = 2 * i + 1;

    if (esq <= tamanho_heap && min_heap[esq].custo < min_heap[i].custo)
        menor = esq;
    else
        menor = i;
    
    if (dir <= tamanho_heap && min_heap[dir].custo < min_heap[menor].custo)
        menor = dir;

    if (menor != i) {
        troca(&min_heap[i], &min_heap[menor]);
        desce_heap(menor);
    }
}

void inserir_heap(ItemFila item) {
    if (tamanho_heap < MAX_HEAP) {
        tamanho_heap++;
        min_heap[tamanho_heap] = item;
        sobe_heap(tamanho_heap);
    }
}

ItemFila extrair_minimo() {
    ItemFila min_item = min_heap[1];
    min_heap[1] = min_heap[tamanho_heap];
    tamanho_heap--;
    desce_heap(1);
    return min_item;
}

void dijkstra_modificado(int C, int F, int N) {
    int i;
    
    for (i = 1; i <= N; i++) {
        dist[i][0] = INF;
        dist[i][1] = INF;
    }
    dist[C][0] = 0;

    ItemFila inicio = {0, C, 0};
    inserir_heap(inicio); 

    while (tamanho_heap > 0) {
        ItemFila atual = extrair_minimo(); 
        int u = atual.cidade;
        int custo_u = atual.custo;
        int p_u = atual.paridade;

        if (custo_u > dist[u][p_u]) {
            continue;
        }

        
        No *temp = adj[u];
        while (temp != NULL) {
            int v = temp->vizinho;
            int w = temp->custo_pedagio;

            int p_v = 1 - p_u;
            int novo_custo = custo_u + w;

            if (novo_custo < dist[v][p_v]) {
                dist[v][p_v] = novo_custo;
                
                ItemFila novo_item = {novo_custo, v, p_v};
                inserir_heap(novo_item);
            }
            temp = temp->prox;
        }
    }

    if (dist[F][0] == INF) {
        printf("-1\n");
    } else {
        printf("%d\n", dist[F][0]);
    }
}

void adiciona_aresta(int C, int F, int P) {
    // Adiciona F como vizinho de C
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) exit(1); 
    novo->vizinho = F;
    novo->custo_pedagio = P;
    novo->prox = adj[C];
    adj[C] = novo;
}

int main() {
    int N, M, i;
    int C, F, P;

    if (scanf("%d %d", &N, &M) != 2) return 1;

    // Inicializa todos os ponteiros do adj como NULL
    for (i = 1; i <= N; i++) {
        adj[i] = NULL;
    }

    for (i = 0; i < M; i++) {
        if (scanf("%d %d %d", &C, &F, &P) != 3) return 1;

        // Adiciona C -> F e F -> C
        adiciona_aresta(C, F, P);
        adiciona_aresta(F, C, P);
    }

    int cidade_inicial = 1;
    int cidade_final = N;

    dijkstra_modificado(cidade_inicial, cidade_final, N);

    // LIBERAÇÃO DE MEMÓRIA (Boa prática, mas opcional no beecrowd)
    for(i = 1; i <= N; i++){
        No *atual = adj[i];
        while(atual != NULL){
            No *proximo = atual->prox;
            free(atual);
            atual = proximo;
        }
    }

    return 0;
}
