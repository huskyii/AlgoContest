#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define MAXN 100005

int d[MAXN];
bool visited[MAXN];

int g[MAXN][MAXN];

void solve(int j, int n){
    if(j == n)
        return ;
    int ans;
    int min = 0;
    for(int i = 1; i <= n; i++){
        getchar();
        if(g[j][i] && d[j] == d[i]+1){
        printf("%d,%d,%d,%d,%d\n",i,j, g[j][i], d[j],d[i]);
            if(min == 0){
                min = g[j][i];
                ans = i;
            }else if(min > g[j][i]){
                min = g[j][i];
                ans = i;
            }   
        }
    }
    printf("%d ", ans);
    //solve(ans, n);
}

int main(void){
    int n, m;
    int front;
    int a, b, c;
    while(scanf("%d %d", &n, &m) == 2){
        memset(d, 0, sizeof(d));
        memset(visited, 0, sizeof(visited));
        //memset(g, 0, sizeof(g));
        while(m--){
            scanf("%d %d %d", &a, &b, &c);
            //printf("%d, %d, %d ", a, b, g[a][b]);
            if(g[a][b]!=0 && g[a][b] < c)
                continue;
            g[a][b] = c;
            g[b][a] = c;
            printf("%d %d %d\n", a, b, g[a][b]);
        }
        queue<int> w;
        w.push(n);
        while(!w.empty()){
            front = w.front();
            w.pop();
            visited[front] = true;
            for(int i = 1; i <= n; i++){
                if(g[front][i]){
                    if(d[i] == 0){
                        d[i] = d[front] + 1;
                    }else if(d[front] + 1 < d[i]){
                        d[i] = d[front] + 1;
                    }
                    if(!visited[i]){
                        w.push(i);
                    }
                }
            }
        }
        printf("%d\n", d[1]);
        for(int i = 0; i < n; i++)
            printf("%d\n", d[i+1]);
        solve(1, n);
    }
    return 0;
}
