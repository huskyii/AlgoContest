/****************************************/
/*			author: jiang.zhu			*/
/*	  email: mail.jiang.cn@gmail.com	*/
/*		created on 2014-08-25			*/
/****************************************/
#include <cstdio>
#include <cstring>
using namespace std;

bool prime[36] = {1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0};
int ans[18];
bool v[18];

void solve(int *ans, int n, int cur){
    if(cur == n && prime[ans[n] + ans[1]]){
        for(int i = 1; i < n; i++){
            printf("%d ", ans[i]);
        }
        printf("%d\n", ans[n]);
        return ;
    }
    cur++;
    for(int i = 2; i <= n; i++){
        if(!v[i] && prime[ans[cur-1]+i]){
            ans[cur] = i;
            v[i] = true;
            solve(ans, n, cur);
            v[i] = false;
        }
    }
}

int main(void){
    int n, kase = 0;
    memset(v, 0, sizeof(v));
    while(scanf("%d", &n) != EOF){
        v[1] = 1;
        ans[1] = 1;
        if(kase){
            printf("\n");
        }
        printf("Case %d:\n", ++kase);
        solve(ans, n, 1);
    }
    
    return 0;
}
