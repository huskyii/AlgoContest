#include <stdio.h>
#include <string.h>

int main(void){
    int len,T,ans,point;
    char seq[85];
    scanf("%d", &T);

    while(T--){
        ans = 0;
        point = 0;
        scanf("%s", seq);
        len = strlen(seq);
        for(int i = 0; i < len; ++i){
            if(seq[i] == 'O'){
                ans += ++point;
            }else if(seq[i] == 'X'){
                point = 0;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
