/****************************************/
/*			author: jiang.zhu			*/
/*	  email: mail.jiang.cn@gmail.com	*/
/*		created on 2014-08-22			*/
/****************************************/
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

bool g[1005][1005];
int visit[1005];
int degree[1005];
int odd[1005];

inline void bfs(int node, int num, int v){
    queue<int> w;
    w.push(node);
    while(!w.empty()){
        int f = w.front();
        visit[f] = num;
        w.pop();
        for(int i = 1; i <= v; i++)
            if(g[f][i] && !visit[i]){
                w.push(i);
            }
    }
}

int main(void){
    int v, e, t;
    int kase = 0;
    int a, b, ans, sum;
    while(scanf("%d %d %d", &v, &e, &t) == 3 && v){
        memset(g, 0, sizeof(g));
        memset(odd, 0, sizeof(odd));
        memset(degree, 0, sizeof(degree));
        memset(visit, 0, sizeof(visit));
        int cnt = 0;
        for(int i = 0; i < e; i++){
            scanf("%d %d", &a, &b);
            g[a][b] = true;
            g[b][a] = true;
        }
        for(int i = 1; i <= v; i++){
            for(int j = 1; j <= v; j++)
                if(g[i][j]){
                    degree[i]++;
                    if(!visit[i]){
                        cnt++;
                        bfs(i, cnt, v);
                    }
                }
        }
        for(int i = 1; i <= v; i++){
            if(degree[i]%2){
                odd[visit[i]]++;
            }
        }
        ans = e;
        if(cnt > 0){
            ans += cnt -1;
        }
        for(int i = 1; i <= cnt; i++){
            if(odd[i] > 3){
                ans += odd[i] / 2 - 1;
            }
        }
        printf("Case %d: %d\n", ++kase, ans * t);
    }
    return 0;
}
