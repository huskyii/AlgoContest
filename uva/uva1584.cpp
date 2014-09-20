#include <stdio.h>
#include <string.h>

char seq[105];

int less(char *seq, int m, int n, int len){
    for(int i = 0; i < len; i++){
        if(seq[(m+i)%len] < seq[(n+i)%len])
            return 1;
        if(seq[(m+i)%len] > seq[(n+i)%len])
            return -1;
    }
    return 0;
}

int main(void){
    int min, len;
    int T;
    scanf("%d", &T);

    while(T--){
        scanf("%s", seq);
        len = strlen(seq);
        min = 0;
        for(int i = 1; i < len; ++i){
            if(less(seq, i, min, len) == 1)
                min = i;
        }
        for(int i = 0; i < len; ++i){
            printf("%c", seq[(min+i)%len]);
        }
        printf("\n");
    }
    return 0;
}
