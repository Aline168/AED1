#include <stdio.h>

void quicksort(int v[], int p, int r) {
    int i = p, j = r, x = v[(p+r)/2];
    while (i <= j) {
        while (v[i] < x) i++;
        while (v[j] > x) j--;
        if (i <= j) {
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++; j--;
        }
    }
    if (p < j) quicksort(v, p, j);
    if (i < r) quicksort(v, i, r);
}

int main() {
    int N;
    scanf("%d", &N);

    int v[100000];
    int pares[100000], ip = 0;
    int impares[100000], ii = 0;

    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);

        if (v[i] % 2 == 0)      // par
            pares[ip++] = v[i];
        else                   // ímpar
            impares[ii++] = v[i];
    }

    if (ip > 0) quicksort(pares, 0, ip - 1);

    if (ii > 0) quicksort(impares, 0, ii - 1);

    for (int i = 0; i < ip; i++)
        printf("%d\n", pares[i]);

    for (int i = ii - 1; i >= 0; i--)
        printf("%d\n", impares[i]);

    return 0;
}
