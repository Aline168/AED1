
void remover (int x, int **lista)
{
    celula *p, *pmin, *pmin_ant, *ant;
    if(lista->prox == NULL) return;

    ant=lista;
    p= lista->prox;
    pmin =p;
    pmin_ant=ant;

    while(p != NULL)
    {
        if(p->conteudo < ->conteudo)
        {
            pmin = p;
            pmin_ant=ant;

        }
        ant = p;
        p = p->prox;
    }
    pmin_ant->prox = pmin-> prox;
    free(pmin);


}
