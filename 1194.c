#include <stdio.h>
#include <string.h>

void geraPos(char *pre, char *in, int n) {
    if (n == 0) return;
    char raiz = pre[0];
    int k = 0;
    while (in[k] != raiz) k++;
    geraPos(pre + 1, in, k);
    geraPos(pre + 1 + k, in + k + 1, n-k-1);
    printf("%c", raiz);
}

int main() {
    int C;
    scanf("%d", &C);
    while (C--) {
        int N;
        char pre[60], in[60];
        scanf("%d %s %s", &N, pre, in);
        geraPos(pre, in, N);
        printf("\n");
    }
    return 0;
}
