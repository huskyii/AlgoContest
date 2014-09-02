#include <stdio.h>
#include <string.h>

int main(void){
    int k,T,len,flag;
    char s[85];
    scanf("%d", &T);
    while(T--){
        scanf("%s", s);
        len = strlen(s);
        for(k=1; k < len; k++){
            if(len%k != 0)
                continue;
            flag = 1;
            for(int i = 0; i < k; i++){
                if(flag == 0)
                    break;
                for(int j = 0;j < len/k; j++){
                    if(s[i] != s[j*k+i]){
                        flag = 0;
                        break;
                    }
                }
            }
            if(flag == 0)
                continue;
            break;
        }
        printf("%d\n", k);
        if(T) printf("\n");
    }
    return 0;
}
