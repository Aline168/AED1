#include <stdio.h>
#include <stdlib.h>

int main(){
    int v=0;
    int t=0;
    int resultado=0;

    while(scanf("%d %d",&v,&t)!=EOF){
         resultado= v*t*2;
         printf("%d\n", resultado);
    }
    
    return 0;
}
