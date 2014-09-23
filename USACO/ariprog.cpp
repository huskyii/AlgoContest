/*
ID: mail.ji1
PROG: ariprog
LANG: C++11
*/
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

const int MAXN = 251*251*4;
bool seq[MAXN];
// b, a
pair<int, int> ans[10000+100];

int main(void) {
  freopen("ariprog.in", "r", stdin);
  freopen("ariprog.out", "w", stdout);

  int n, m;
  while(scanf("%d %d", &n, &m) != EOF) {
    memset(seq, 0, sizeof(seq));
    for(int i = 0; i <= m; ++i)
      for(int j = 0; j <= m; ++j)
        seq[i*i+j*j] = true;

    int cur = 0;
    int limit = m*m*2;
    for(int a = 0; a < limit; ++a) {
      if(!seq[a]) continue;
      for(int b = 1; b <= (limit-a)/(n-1); ++b) {
        bool flag = true;
        for(int i = 0; i < n; ++i) {
          if(!seq[a+b*i]) { flag = false; break; }
        }
        if(flag) { ans[cur].first = b; ans[cur++].second = a; }
      }
    }
    if(cur) {
      sort(ans, ans+cur);
      for(int i = 0; i < cur; ++i)
        printf("%d %d\n", ans[i].second, ans[i].first);
    } else printf("NONE\n");
  }

  return 0;
}
