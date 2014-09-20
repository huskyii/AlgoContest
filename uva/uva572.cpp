#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 105

char grid[MAXN][MAXN];

void bfs(int row, int col, const int &m, const int &n){
    grid[row][col] = '*';
    for(int dx = -1; dx <= 1; dx++)
        for(int dy = -1; dy <= 1; dy++){
            if(row+dx >= 0 && row+dx < m && col+dy >= 0 && col+dy < n)
                if(grid[row+dx][col+dy] == '@')
                    bfs(row+dx, col+dy, m, n);
        }
}

int main(void){
    int m, n;
    while(scanf("%d %d", &m, &n) == 2 && m && n){
        int cnt = 0;
        for(int row = 0; row < m; row++){
            scanf("%s", grid[row]);
        }
        for(int row = 0; row < m; row++)
            for(int col = 0; col < n; col++)
                if(grid[row][col] == '@'){
                    bfs(row, col, m, n);
                    cnt++;
                }
        printf("%d\n", cnt);
    }
    return 0;
}
