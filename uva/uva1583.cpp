#include <stdio.h>
#include <string.h>

#define MAX_N 100005

int ans[MAX_N];

int main(void){
    int T,n;
    int x,y;
    memset(ans, 0, sizeof(ans));
    for(int i = 0; i < MAX_N; i++){
        x = i;
        y = i;
        while(x > 0){
            y += x%10;
            x /= 10;
        }
        if(ans[y] == 0 || i < ans[y])
            ans[y] = i;
    }
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
    return 0;
}
