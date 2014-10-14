/****************************************/
/*          author: jiang.zhu           */
/*    email: mail.jiang.cn@gmail.com    */
/*         created on 2014-10-14        */
/****************************************/
#include <queue>
#include <cstdio>
#include <utility>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 400;
int g[MAXN][MAXN];
int v[MAXN][MAXN];
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};

inline void mark(int x, int y, int t) {
  g[x][y] = g[x][y] >= 0? min(g[x][y], t): t;
}

int bfs() {
  memset(v, -1, sizeof(v));
  v[0][0] = 0;
  queue< pair<int, int> > w;
  w.push(make_pair(0, 0));
  while(!w.empty()) {
    int x = w.front().first, y = w.front().second;
    w.pop();
    if(g[x][y] == -1) return v[x][y];
    if(g[x][y] <= v[x][y]) continue;
    for(int i = 0; i < 4; ++i) {
      int nx = x+dx[i], ny = y+dy[i];
      if(0 <= nx  && 0 <= ny
          && v[nx][ny] == -1) {
        w.push(make_pair(nx, ny));
        v[nx][ny] = v[x][y] + 1;
      }
    }
  }
  return -1;
}

int main(void){
  int m, x, y, t;
  scanf("%d", &m);
  memset(g, -1, sizeof(g));
  for(int i = 0; i < m; ++i) {
    scanf("%d %d %d", &x, &y, &t);
    mark(x, y, t);
    if(x-1 >= 0) mark(x-1, y, t);
    mark(x+1, y, t);
    if(y-1 >= 0) mark(x, y-1, t);
    mark(x, y+1, t);
  }

  printf("%d\n", bfs());
  return 0;
}
