
void remover (int x, int **lista)
{
    celula *p= *lista, *q = NULL;

    while(*p!=NULL && p-.conteudo !=x)
    {
        q=p;
        p=p->prox;
    }
    if(p==NULL)
    {
        return;
    }
    if(q==NULL)
    {
        *lista = p-> prox;

    }
    else
    {
        q->prox = p->prox;

    }
    free(p);
}
