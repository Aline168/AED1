#include <stdio.h>

int main() {
    int X = 0;
    int Y = 0;
    int i, soma=0;

    scanf("%d",&X);
    scanf("%d",&Y);

    if(X < Y){
        for(i=X; i<=Y; i++){
            if(i % 13!=0){
                soma+=i;
            }

        }
    }
    else{
         for(i=Y; i<=X; i++){
            if(i % 13!=0){
                soma+=i;
            }

        }
    }

    printf("%d\n", soma);


    return 0;
}
