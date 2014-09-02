#include <stdio.h>

int main(void){
//    freopen("uva272.out","w",stdout);
//    freopen("uva272.in","r",stdin);
    char c;
    int flag = 1;
    while(scanf("%c", &c) != EOF){
        if(c == '"'){
            if(flag){
                printf("``");
                flag = 0;
            }else{
                printf("''");
                flag = 1;
            }
        }else{
            printf("%c", c);
        }
    }
}
