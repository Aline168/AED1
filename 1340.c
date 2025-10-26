#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// ---------------------- PILHA ----------------------
int stack(int n)
{
    int pilha[MAX];
    int topo = 0;
    int op, x;

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &op, &x);
        if (op == 1)   // empilha
        {
            pilha[topo++] = x;
        }
        else     // remove
        {
            if (topo == 0 || pilha[topo - 1] != x)
            {
                for (int j = i + 1; j < n; j++)
                    scanf("%d %d", &op, &x);
                return 0;
            }
            topo--;
        }
    }
    return 1;
}

// ---------------------- FILA ----------------------
int queue(int n)
{
    int fila[MAX];
    int ini = 0, fim = 0;
    int op, x;

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &op, &x);
        if (op == 1)   // insere no fim
        {
            fila[fim++] = x;
        }
        else     // remove do início
        {
            if (ini == fim || fila[ini] != x)
            {
                for (int j = i + 1; j < n; j++)
                    scanf("%d %d", &op, &x);
                return 0;
            }
            ini++;
        }
    }
    return 1;
}

// ---------------------- FILA DE PRIORIDADE ----------------------
int priority_queue(int n)
{
    int fp[MAX];
    int tam = 0;
    int op, x;

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &op, &x);
        if (op == 1)   // insere
        {
            fp[tam++] = x;
        }
        else     // remove o maior
        {
            if (tam == 0)
            {
                for (int j = i + 1; j < n; j++)
                    scanf("%d %d", &op, &x);
                return 0;
            }
            int maior = 0;
            for (int k = 1; k < tam; k++)
            {
                if (fp[k] > fp[maior])
                    maior = k;
            }
            if (fp[maior] != x)
            {
                for (int j = i + 1; j < n; j++)
                    scanf("%d %d", &op, &x);
                return 0;
            }
            // remove o maior
            fp[maior] = fp[tam - 1];
            tam--;
        }
    }
    return 1;
}

// ---------------------- PROGRAMA PRINCIPAL ----------------------
int main()
{
    int n;

    while (scanf("%d", &n) != EOF)   // aceita vários casos
    {
        // precisamos ler a entrada 3 vezes
        // então vamos salvar tudo primeiro
        int ops[MAX][2];
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &ops[i][0], &ops[i][1]);
        }

        // agora testamos cada estrutura
        int is_stack = 1, is_queue = 1, is_pqueue = 1;

        // simulando de novo as operações, copiando o vetor
        {
            int topo = 0, op, x;
            for (int i = 0; i < n; i++)
            {
                op = ops[i][0];
                x = ops[i][1];
                static int pilha[MAX];
                if (op == 1) pilha[topo++] = x;
                else
                {
                    if (topo == 0 || pilha[topo - 1] != x)
                        is_stack = 0;
                    else topo--;
                }
            }
        }

        {
            int ini = 0, fim = 0, op, x;
            static int fila[MAX];
            for (int i = 0; i < n; i++)
            {
                op = ops[i][0];
                x = ops[i][1];
                if (op == 1) fila[fim++] = x;
                else
                {
                    if (ini == fim || fila[ini] != x)
                        is_queue = 0;
                    else ini++;
                }
            }
        }

        {
            int tam = 0, op, x;
            static int fp[MAX];
            for (int i = 0; i < n; i++)
            {
                op = ops[i][0];
                x = ops[i][1];
                if (op == 1) fp[tam++] = x;
                else
                {
                    if (tam == 0)
                    {
                        is_pqueue = 0;
                    }
                    else
                    {
                        int maior = 0;
                        for (int k = 1; k < tam; k++)
                            if (fp[k] > fp[maior]) maior = k;
                        if (fp[maior] != x)
                            is_pqueue = 0;
                        else
                        {
                            fp[maior] = fp[tam - 1];
                            tam--;
                        }
                    }
                }
            }
        }

        int total = is_stack + is_queue + is_pqueue;

        if (total == 0)
            printf("impossible\n");
        else if (total > 1)
            printf("not sure\n");
        else if (is_stack)
            printf("stack\n");
        else if (is_queue)
            printf("queue\n");
        else
            printf("priority queue\n");
    }

    return 0;
}
