/*
ID: mail.ji1
PROG: milk
LANG: C++11
*/
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

const int MAXN = 5000 + 5;
pair<int, int> f[MAXN];

int main(void) {
  freopen("milk.in", "r", stdin);
  freopen("milk.out", "w", stdout);

  int n, m;
  while(scanf("%d %d", &n, &m) != EOF) {
    for(int i = 0; i < m; ++i)
      scanf("%d %d", &f[i].first, &f[i].second);

    sort(f, f+m);
    int ans = 0;
    for(int i = 0; n > 0; ++i) {
      ans = ans + min(n, f[i].second) * f[i].first;
      n = n - f[i].second;
    }
    printf("%d\n", ans);
  }

  return 0;
}
