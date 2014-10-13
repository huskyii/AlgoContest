/****************************************/
/*          author: jiang.zhu           */
/*    email: mail.jiang.cn@gmail.com    */
/*         created on 2014-10-13        */
/****************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 22;
int w, h, cnt;
bool v[MAXN][MAXN];
char g[MAXN][MAXN];

inline void locate(int &x, int &y) {
  for(int i = 0; i < h; ++i)
    for(int j = 0; j < w; ++j)
      if(g[i][j] == '@') { x = i, y = j; return; }
}

void dfs(int x, int y) {
  if(!v[x][y] && g[x][y] != '#') { v[x][y] = true; cnt++; }
  else return;

  if(x+1 < h) dfs(x+1, y);
  if(x-1 >= 0) dfs(x-1, y);
  if(y+1 < w) dfs(x, y+1);
  if(y-1 >= 0) dfs(x, y-1);
}

int main(void){
  while(scanf("%d %d", &w, &h) != EOF && w && h) {
    for(int i = 0; i < h; ++i) scanf("%s", g[i]);

    int x, y;
    locate(x, y);
    memset(v, 0, sizeof(v));
    cnt = 0;
    dfs(x, y);
    printf("%d\n", cnt);
  }
  return 0;
}
