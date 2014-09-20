/****************************************/
/*			author: jiang.zhu			*/
/*	  email: mail.jiang.cn@gmail.com	*/
/*		created on 2014-09-03			*/
/****************************************/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 25;
int target, cur, cnt;
bool g[maxn][maxn], v[maxn], mark[maxn];
int route[maxn];

inline void preprocess(int node) {
    mark[node] = true;
    for(int i = 1; i < 22; i++) {
        if(g[node][i] && !mark[i]) {
            preprocess(i);
        }
    }
}

void dfs(int start) {
    v[start] = true;
    route[cur++] = start;
    if(start == target) {
        cnt++;
        for(int i = 0; i < cur; i++) {
            if(i) printf(" ");
            printf("%d", route[i]);
        }
        printf("\n");
        cur--;
        v[start] = false;
        return ;
    }
    for(int i = 1; i < 22; i++) {
        if(mark[i] && !v[i] && g[start][i])
            dfs(i);
    }
    cur--;
    v[start] = false;
}

int main(void){
    int kase = 0;
    while(scanf("%d", &target) != EOF) {
        int a, b;
        memset(g, 0, sizeof(g));
        while(scanf("%d %d", &a, &b) == 2 && a && b) {
            g[a][b] = true;
            g[b][a] = true;
        }
        printf("CASE %d:\n", ++kase);
        memset(v, 0, sizeof(v));
        memset(mark, 0, sizeof(mark));
        cnt = 0, cur = 0;
        preprocess(target);
        dfs(1);
        printf("There are %d routes from the firestation to streetcorner %d.\n", cnt, target);
    }
    return 0;
}
