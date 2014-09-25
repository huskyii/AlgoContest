/*
ID: mail.ji1
PROG: hamming
LANG: C++11
*/
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 64;
int ans[MAXN];
int n, b, d;

inline int hamming(int x, int y) {
  return __builtin_popcount(x^y);
}

inline bool confilict(int elem, int cur) {
  for(int i = 0; i < cur; ++i)
    if(hamming(ans[i], elem) < d)
      return false;
  return true;
}

bool dfs(int elem, int cur) {
  ans[cur++] = elem;
  if(cur == n) return true;
  for(int i = elem+1; i <= (1 << b); ++i) {
    if(confilict(i, cur) && dfs(i, cur))
      return true;
  }
  return false;
}

int main(void) {
  freopen("hamming.in", "r", stdin);
  freopen("hamming.out", "w", stdout);

  while(scanf("%d %d %d", &n, &b, &d) != EOF) {
    memset(ans, 0, sizeof(ans));
    dfs(0, 0);
    for(int i = 0; i < n; ++i) {
      if(i%10) { printf(" "); }
      else { if(i) printf("\n"); }
      printf("%d", ans[i]);
    }
    printf("\n");

  }

  return 0;
}
