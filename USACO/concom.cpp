/*
ID: mail.ji1
PROG: concom
LANG: C++11
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int c[102][102];
int own[102][102];
int m = 0;

void dfs(int i, int j) {
  for(int k = 1; k <= m; k++) {
    if(i != k && own[i][k] <= 50) {
      own[i][k] += c[j][k];
      if(own[i][k] > 50) dfs(i, k);
    }
  }
}

int main(void) {
  freopen("concom.in", "r", stdin);
  freopen("concom.out", "w", stdout);

  int n, x, y, p;
  scanf("%d", &n);
  memset(c, 0, sizeof(c));
  while(n--) {
    scanf("%d %d %d", &x, &y, &p);
    c[x][y] = p;
    m = max(m, x); m = max(m, y);
  }
  memcpy(own, c, sizeof(c));
  for(int i = 1; i <= m; ++i)
    for(int j = 1; j <= m; ++j)
      if(own[i][j] > 50) dfs(i, j);

  for(int i = 1; i <= m; ++i)
    for(int j = 1; j <= m; ++j)
      if(i != j && own[i][j] > 50)
        printf("%d %d\n", i, j);

  return 0;
}
