#include <cstdio>

int foo(int n){
    int ans = 0;
    while(n > 1){
        ans++;
        if(n%2 != 0)
            n = n/2 + 1;
        else
            n /= 2;
    }
    return ans;
}

int main(void){
    int knife, hand, T, N, M, K, kase = 0;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d", &N, &M, &K);
        printf("Case #%d:", ++kase);
        knife = foo(N) + foo(M) + foo(K);
        hand = N*M*K-1;
        printf(" %d %d\n", hand, knife);
    }
    return 0;
}
