#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 305
#define PILHA_MAX 100

char pilha[PILHA_MAX];
int topo = -1;

void push(char item) {
    if (topo < PILHA_MAX - 1) {
        pilha[++topo] = item;
    }
}

char pop() {
    if (topo >= 0) {
        return pilha[topo--];
    }
    return '\0'; 
}

char peek() {
    if (topo >= 0) {
        return pilha[topo];
    }
    return '\0';
}

int vazia() {
    return topo == -1;
}

int precedencia(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0; 
}

void infixa_para_posfixa(char *infixa) {
    int len = strlen(infixa);
    topo = -1; 
    
    for (int i = 0; i < len; i++) {
        char C = infixa[i];

        if (isalnum(C)) {
            printf("%c", C);
        } 
        else if (C == '(') {
            push(C);
        } 
        else if (C == ')') {
            while (!vazia() && peek() != '(') {
                printf("%c", pop());
            }
            if (!vazia() && peek() == '(') {
                pop(); 
            }
        } 
        else if (C == '+' || C == '-' || C == '*' || C == '/' || C == '^') {
            while (!vazia() && precedencia(peek()) >= precedencia(C)) {
                if (C == '^' && peek() == '^') {
                    break;
                }
                printf("%c", pop());
            }
            push(C);
        }
    }

    while (!vazia()) {
        printf("%c", pop());
    }
    printf("\n");
}

int main() {
    int N;
    char linha[MAX_SIZE];
    
    if (scanf("%d", &N) != 1) return 0;
    getchar(); 

    while (N--) {
        if (fgets(linha, MAX_SIZE, stdin) == NULL) break;
        
        linha[strcspn(linha, "\n")] = '\0';
        
        infixa_para_posfixa(linha);
    }

    return 0;
}
