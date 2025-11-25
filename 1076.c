#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int vertice;
    struct Node* prox;
} Node;

typedef struct {
    Node* lista[100]; // até 100 vértices
    int V;
} Grafo;


Node* novoNo(int v) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->vertice = v;
    n->prox = NULL;
    return n;
}

void inicializaGrafo(Grafo* g, int V) {
    g->V = V;
    for (int i = 0; i < V; i++) {
        g->lista[i] = NULL;
    }
}

void adicionaAresta(Grafo* g, int u, int v) {
    Node* n = novoNo(v);
    n->prox = g->lista[u];
    g->lista[u] = n;
}

void DFSUtil(Grafo* g, int v, bool visitado[], int* movimento) {
    visitado[v] = true;

    Node* temp = g->lista[v];
    while (temp) {
        int vizinho = temp->vertice;
        if (!visitado[vizinho]) {
            (*movimento)++;
            DFSUtil(g, vizinho, visitado, movimento);
            (*movimento)++;
        }
        temp = temp->prox;
    }
}

void DFS(Grafo* g, int inicio) {
    bool visitado[100] = {false};
    int movimento = 0;
    DFSUtil(g, inicio, visitado,&movimento);
    printf("%d",movimento) ;
}

int main() {
    Grafo g;
    int T, N, V, A, u,v;
    scanf("%d", &T);
    while(T--){
        scanf("%d",&N);
        scanf("%d %d",&V, &A);
        inicializaGrafo(&g, V);

        for (int i = 0; i < A; i++) {
            scanf("%d %d", &u, &v);
            adicionaAresta(&g, u, v);
            adicionaAresta(&g, v, u);
        }
        DFS(&g, N);
        printf("\n");
    }
         return 0;
}






