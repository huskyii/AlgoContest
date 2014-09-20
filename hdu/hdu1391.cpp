#include <stdio.h>

int main(void){
    int x, y;
    int cas;
    scanf("%d", &cas);
    for(int i = 0; i < cas; ++i){
        scanf("%d %d", &x, &y);
        if( x != y && (x-2)!=y ){
            printf("No Number\n");
        }else{
            if(x == y)
                if(x%2 == 0)
                    printf("%d\n", 2*x);
                else
                    printf("%d\n", 2*(x+1) - 3);
            else
                if(x%2 == 0)
                    printf("%d\n", 2*x - 2);
                else
                    printf("%d\n", 2*(x+1) - 5);
        }
    }
    return 0;
}
