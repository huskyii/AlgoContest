/****************************************/
/*			author: jiang.zhu			*/
/*	  email: mail.jiang.cn@gmail.com	*/
/*		created on 2014-09-08			*/
/****************************************/
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 110;

char g[maxn][maxn];
bool v[maxn][maxn];
int n;

bool solve(int i, int j) {
    int cnt = 0;
    v[i][j] = true;

    if(i-1 >= 0 && g[i-1][j] == 'o') cnt++;
    if(i+1 < n && g[i+1][j] == 'o') cnt++;
    if(j-1 >= 0 && g[i][j-1] == 'o') cnt++;
    if(j+1 < n && g[i][j+1] == 'o') cnt++;

    if(cnt%2 == 0)
        return true;
    else
        return false;
}

int main(void){
    while(scanf("%d", &n) != EOF) {
        memset(v, 0, sizeof(v));
        for(int i = 0; i < n; i++)
            scanf("%s", g[i]);

        bool flag = true;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(g[i][j] == 'o') {
                    if(i+1 < n && !v[i+1][j])
                        flag = solve(i+1, j);
                    if(i-1 >= 0 && !v[i-1][j])
                        flag = solve(i-1, j);
                    if(j+1 < n && !v[i][j+1])
                        flag = solve(i, j+1);
                    if(j-1 >= 0 && !v[i][j-1])
                        flag = solve(i, j-1);
                }
                if(!flag) break;
            }
            if(!flag) break;
        }

        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
