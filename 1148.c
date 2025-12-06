#include <stdio.h>
#include <limits.h>

#define MAX_CIDADES 505
#define INF 1000000 

int adj[MAX_CIDADES][MAX_CIDADES];
int dist[MAX_CIDADES];

void dijkstra(int N, int inicio) {
    int i, u, v;
    int visitado[MAX_CIDADES];
    
   
    for (i = 1; i <= N; i++) {
        dist[i] = INF;
        visitado[i] = 0;
    }
    
    dist[inicio] = 0;

    
    for (i = 1; i <= N; i++) {
        int menor_distancia = INF;
        u = -1; 

       
        for (v = 1; v <= N; v++) {
            if (!visitado[v] && dist[v] < menor_distancia) {
                menor_distancia = dist[v];
                u = v;
            }
        }

        if (u == -1) break;

        visitado[u] = 1;

      
        for (v = 1; v <= N; v++) {
           
            if (adj[u][v] != INF && (dist[u] + adj[u][v] < dist[v])) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }
}

int main() {
    int N, E, i, u, v, c, Q, origem, destino, tempo_minimo;

  
    while (scanf("%d %d", &N, &E) && (N != 0 || E != 0)) {

       
        for (u = 1; u <= N; u++) {
            for (v = 1; v <= N; v++) {
                adj[u][v] = INF;
            }
          
        }

      
        for (i = 0; i < E; i++) {
            scanf("%d %d %d", &u, &v, &c);
           
            adj[u][v] = c;
        }

       
        for (u = 1; u <= N; u++) {
            for (v = 1; v <= N; v++) {
               
                if (adj[u][v] != INF && adj[v][u] != INF) {
                
                    adj[u][v] = 0;
                    adj[v][u] = 0;
                }
            }
        }
        
        scanf("%d", &Q);

        for (i = 0; i < Q; i++) {
            scanf("%d %d", &origem, &destino);
            
            dijkstra(N, origem);
            
            tempo_minimo = dist[destino];

            if (tempo_minimo >= INF) { 
                printf("Nao e possivel entregar a carta\n");
            } else {
                printf("%d\n", tempo_minimo);
            }
        }
        
        printf("\n"); 
    }

    return 0;
}
