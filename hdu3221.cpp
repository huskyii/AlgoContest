// #define LOCAL
#include <cstdio>
#include <cmath>

int ans[4];

int main(void){
#ifdef LOCAL
    freopen("hdu3221.in", "r", stdin);
    freopen("hdu3221.out", "w", stdout);
#endif
    int T,a,b,P,n,kase = 0;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d %d", &a, &b, &P, &n);
        ans[1] = a;
        ans[2] = b;
        for(int i = 3; i <= n; ++i){
            ans[3] =  (ans[1] * ans[2])%P;
            ans[1] = ans[2];
            ans[2] = ans[3];
        }
        printf("Case #%d: %d\n", ++kase, (n >2 ? ans[3] : ans[n]) );
    }
    return 0;
}
