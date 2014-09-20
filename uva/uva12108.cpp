#include <cstdio>

int a[15], b[15], c[15];

int main(void){
    int n, kase = 0;
    int wake, sleep;
    while(scanf("%d", &n) != EOF && n){
        for(int i = 0; i < n; ++i)
            scanf("%d %d %d", &a[i], &b[i], &c[i]);
        int ans = 1;
        while(ans < 25200){
            wake = 0;
            for(int i = 0; i < n; ++i)
                if(c[i] <= a[i])
                    wake++;
            sleep = n - wake;
            if(sleep == 0)
                break;
            for(int i = 0; i < n; ++i){
                c[i]++;
                if(c[i] == a[i]+b[i]+1)
                    c[i] = 1;
                if(c[i] == a[i]+1 && wake >= sleep)
                    c[i] =1;
            }
            ans++;
        }
        if(ans==25200)
            printf("Case %d: -1\n", ++kase);
        else
            printf("Case %d: %d\n", ++kase, ans);
    }
    return 0;
}
