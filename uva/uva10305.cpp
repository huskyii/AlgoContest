#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

#define MAXN 105

bool G[MAXN][MAXN];

int mark[MAXN];

bool visit(int node, stack<int> &topo, int n){
    if(mark[node] == -1){
        return false;
    }else if(mark[node] == 0){
        mark[node] = -1;
        for(int ad = 1; ad <= n; ad++){
            if(G[node][ad]){
                if(!visit(ad, topo, n)) return false;
            }
        }
        mark[node] = 1;
        topo.push(node);
    }
    return true;
}

bool dfs(int n){
    stack<int> topo;
    memset(mark, 0, sizeof(mark));
    for(int node = 1; node <= n; node++){
        if(mark[node] == 0){
            if(!visit(node, topo, n)) return false;
        }
    }
    while(topo.size() > 1){
        printf("%d ", topo.top());
        topo.pop();
    }
    printf("%d\n", topo.top());
    return true;
}

int main(void){
    int m, n;
    int v, w;
    while(scanf("%d %d", &n, &m) == 2 && n){
        memset(G, 0, sizeof(G));
        while(m--){
            scanf("%d %d", &v, &w);
            G[v][w] = true;
        }
        dfs(n);
    }
    return 0;
}
