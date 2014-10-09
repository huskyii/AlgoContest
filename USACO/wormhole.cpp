/*
ID: mail.ji1
PROG: wormhole
LANG: C++11
*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 15;
int n, x[MAXN], y[MAXN], nextr[MAXN], p[MAXN];

bool cycle(void) {
  for(int start = 1; start <= n; ++start) {
    int pos = start;
    for(int cnt = 0; cnt < n; cnt++)
      pos = nextr[p[pos]];
    if(pos != 0) return true;
  }
  return false;
}

int solve(void) {
  int i, tot = 0;
  for(i = 1; i <= n; ++i)
    if(p[i] == 0) break;
  if(i > n) {
    if(cycle()) return 1;
    else return 0;
  }

  for(int j = i+1; j <= n; ++j)
    if(p[j] == 0) {
      p[i] = j;
      p[j] = i;
      tot += solve();
      p[i] = p[j] = 0;
    }

  return tot;
}

int main(void) {
  freopen("wormhole.in", "r", stdin);
  freopen("wormhole.out", "w", stdout);

  while(scanf("%d", &n) != EOF) {
    for(int i = 1; i <= n; ++i) scanf("%d %d", x+i, y+i);

    memset(nextr, 0, sizeof(nextr));
    for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= n; ++j)
        if(x[i] < x[j] && y[i] == y[j])
          if(nextr[i] == 0 || x[nextr[i]] > x[j])
            nextr[i] = j;

    printf("%d\n", solve());
  }

  return 0;
}
