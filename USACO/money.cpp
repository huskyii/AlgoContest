/*
ID: mail.ji1
PROG: money
LANG: C++11
*/
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXV = 25 + 5;
const int MAXN = 10000 + 5;
int v, n, xx;
long long dp[MAXN];

int main(void) {
  freopen("money.in", "r", stdin);
  freopen("money.out", "w", stdout);

  while(scanf("%d %d", &v, &n) != EOF) {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 0; i < v; ++i) {
      scanf("%d", &xx);
      for(int j = xx; j <= n; ++j)
        dp[j] += dp[j-xx];
    }

    printf("%lld\n", dp[n]);
  }

  return 0;
}
