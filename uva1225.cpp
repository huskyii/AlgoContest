#include <stdio.h>
#include <string.h>

int main(void){
    int T,tmp,ans[10],n;
    scanf("%d", &T);
    while(T--){
        memset(ans, 0, sizeof(ans));
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
            tmp = i;
            while(tmp){
                ans[tmp%10]++;
                tmp /= 10;
            }
        }
        for(int i = 0; i < 9; i++)
            printf("%d ", ans[i]);
        printf("%d", ans[9]);
        printf("\n");
    }
    return 0;
}
