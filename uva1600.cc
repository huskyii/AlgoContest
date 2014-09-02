/****************************************/
/*			author: jiang.zhu			*/
/*	  email: mail.jiang.cn@gmail.com	*/
/*		created on 2014-08-23			*/
/****************************************/
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int g[22][22];
bool v[22][22];
int d[22][22];

int k;

void bfs(int m, int n){
    queue< pair< pair<int, int>, int > > w;
    w.push(make_pair(make_pair(1, 1), k));
    while(!w.empty()){
        int cur = w.front().second;
        int row = w.front().first.first;
        int col = w.front().first.second;
        v[row][col] = true;
        w.pop();
        if(row+1 <= m && !v[row+1][col]){
            d[row+1][col] = d[row][col] + 1;
            if(g[row+1][col] && cur){
                w.push(make_pair(make_pair(row+1, col), cur - 1));
            }
            if(!g[row+1][col]){
                w.push(make_pair(make_pair(row+1, col), k));
            }
        }
        if(row - 1 > 0 && !v[row-1][col]){
            d[row-1][col] = d[row][col] + 1;
            if(g[row-1][col] && cur){
                w.push(make_pair(make_pair(row-1, col), cur - 1));
            }
            if(!g[row-1][col]){
                w.push(make_pair(make_pair(row-1, col), k));
            }
        }
        if(col + 1 <= n && !v[row][col+1]){
            d[row][col+1] = d[row][col] + 1;
            if(g[row][col+1] && cur){
                w.push(make_pair(make_pair(row, col+1), cur - 1));
            }
            if(!g[row][col+1]){
                w.push(make_pair(make_pair(row, col+1), k));
            }
        }
        if(col - 1 > 0 && !v[row][col-1]){
            d[row][col-1] = d[row][col] + 1;
            if(g[row][col-1] && cur){
                w.push(make_pair(make_pair(row, col-1), cur - 1));
            }
            if(!g[row][col-1]){
                w.push(make_pair(make_pair(row, col-1), k));
            }
        }
    }
}

int main(void){
    int T;
    int m, n;
    scanf("%d", &T);
    while(T--){
        memset(g, 0, sizeof(g));
        memset(v, 0, sizeof(v));
        memset(d, 0, sizeof(d));
        scanf("%d %d ", &m, &n);
        scanf("%d ", &k);
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                scanf("%d ", &g[i][j]);
        bfs(m, n);
        printf("%d\n", v[m][n] ? d[m][n] : -1);
    }
    return 0;
}
