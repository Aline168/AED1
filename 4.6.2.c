void BuscaEInsere (int x, celula **lista){
    celula *p,*q;, *novo;
    novo = malloc(sizeof(celula));
    novo->conteudo= y;
    
   
    if (novo ==  NULL) return;
    
    novo->conteudo =y;
    
  
    if (*lista== NULL){
        novo->prox = NULL; 
        *lista = novo;
        return;
        
    }
  
    
    if((*lista)->conteudo == x){
        novo->prox=*lista;
        *lista = novo; 
        return;
        
    }
    p=*lista; 
    q=p->prox; 
    
    while(q!= NUUL && q->conteudo != x){
        p=q;
        q=q->prox;
    
    }
    novo->prox = q; 
    p->prox=novo; 
    
}
