/*
ID: mail.ji1
PROG: castle
LANG: C++11
*/
#include <queue>
#include <cstdio>
#include <utility>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 50 + 5;
int g[MAXN][MAXN], v[MAXN][MAXN];
int m, n, size, s[MAXN*MAXN];

void bfs(int id, int i, int j) {
  size = 0;
  queue< pair<int, int> > w;
  w.push(make_pair(i, j));
  v[i][j] = id;
  while(!w.empty()) {
    i = w.front().first, j = w.front().second;
    ++size;
    w.pop();
    //cout << i << " " << j << " " << size << endl;
    if(!(g[i][j] & 1) && !v[i][j-1]) { w.push(make_pair(i, j-1)); v[i][j-1] = id; }
    if(!(g[i][j] & 2) && !v[i-1][j]) { w.push(make_pair(i-1, j)); v[i-1][j] = id; }
    if(!(g[i][j] & 4) && !v[i][j+1]) { w.push(make_pair(i, j+1)); v[i][j+1] = id; }
    if(!(g[i][j] & 8) && !v[i+1][j]) { w.push(make_pair(i+1, j)); v[i+1][j] = id; }
  }
}

int x, y, ans;
char dir;
inline void process(int i, int j, int a, int b, char d) {
  if(v[i][j] == v[a][b]) return ;
  if(ans >= s[v[i][j]] + s[v[a][b]]) return ;
  if(ans < s[v[i][j]] + s[v[a][b]]) {
    dir = d; x = i; y = j;
    ans = s[v[i][j]] + s[v[a][b]];
  }
}

int main(void) {
  freopen("castle.in", "r", stdin);
  freopen("castle.out", "w", stdout);

  while(scanf("%d %d", &m, &n) != EOF) {
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < m; ++j)
        scanf("%d", &g[i][j]);

    int cnt = 0;
    memset(v, 0, sizeof(v));
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < m; ++j)
        if(!v[i][j]) { bfs(cnt+1, i, j); s[++cnt] = size; }

    ans = 0;
    for(int j = 0; j < m; ++j)
      for(int i = n-1; i >= 0; --i) {
        if(g[i][j] & 2) process(i, j, i-1, j, 'N');
        if(g[i][j] & 4) process(i, j, i, j+1, 'E');
      }
    int max_size = 0;
    for(int i = 1; i <= cnt; ++i)
      max_size = max(max_size, s[i]);
    printf("%d\n%d\n%d\n%d %d %c\n", cnt, max_size, ans, x+1, y+1, dir);
  }

  return 0;
}
