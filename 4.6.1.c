
void BuscaERemove(int x, celula **ist)
{
    celula *p,*q;
    
    if (*lista ==  NULL) return;

  
    if((*lista)-> conteudo == x)
    {
        q = *lista; 
        *lista = q-> prox;
        free(q);
        return;
    }
  
    p = *lista;
    q = p -> prox;

    while(q!=NULL && q->conteudo != x)
    {
        p = q;
        q = q->prox;
    }
    if(q!= NULL)
    {
        p->prox= q-> prox; 
        free (q);
    }


}
