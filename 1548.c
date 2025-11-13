#include <stdio.h>

void ordenaDecrescente(int v[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (v[j] > v[i]) { // ordena do maior pro menor
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}

int main() {
    int N, M;
    scanf("%d", &N);

    for (int caso = 0; caso < N; caso++) {
        scanf("%d", &M);
        int original[M];
        int ordenado[M];

       
        for (int i = 0; i < M; i++) {
            scanf("%d", &original[i]);
            ordenado[i] = original[i];
        }
      
        ordenaDecrescente(ordenado, M);
  
        int iguais = 0;
        for (int i = 0; i < M; i++) {
            if (original[i] == ordenado[i])
                iguais++;
        }

        printf("%d\n", iguais);
    }

    return 0;
}
