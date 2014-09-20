/****************************************/
/*			author: jiang.zhu			*/
/*	  email: mail.jiang.cn@gmail.com	*/
/*		created on 2014-08-25			*/
/****************************************/
#include <cstdio>
#include <cstring>
using namespace std;

char ans[85];
int cnt;

inline void print_ans(int n){
    for(int i = 1; i < n; i++){
        printf("%c", ans[i]);
        if(!(i%4) && i%64){
            printf(" ");
        }else if(!(i%64)){
            printf("\n");
        }
    }
    printf("%c\n", ans[n]);
    printf("%d\n", n);
}

inline bool is_hard(int cur){
    if(cur == 1){
        cnt++;
        return true;
    }
    for(int i = 1; i < cur; i++){
        for(int k = i+1; k <= cur; k++){
            if(strncmp(ans+i, ans+k, k-i) == 0){
                return false;
            }
        }
    }
    cnt++;
    return true;
}

inline bool solve(int cur, int n, int l){
    for(int i = 0; i < l; i++){
        ans[cur] = 'A' + i;
        if(is_hard(cur)){
            //print_ans(cur);
            if(cnt == n){
                print_ans(cur);
                return true;
            }
            if(solve(cur+1, n, l)){
                return true;
            }
        }
        ans[cur] = 0;
    }
    return false;
}

int main(void){
    int n, l;
    while(scanf("%d %d", &n, &l) == 2 && n){
        memset(ans, 0, sizeof(ans));
        ans[84] = '\0';
        cnt = 0;
        solve(1, n, l);
    }
    return 0;
}
