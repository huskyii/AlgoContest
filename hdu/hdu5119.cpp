#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int64;
const int MAXN = 40 + 5;
int k[MAXN], dp[MAXN][(1<<20) + 5];

int main(void) {
  int T, n, m;
  cin >> T;
  for(int kase = 1; kase <= T; ++kase) {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
      cin >> k[i];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i) {
      for(int j = 0; j <= (1<<20); ++j) {
        dp[i][j^k[i]] += dp[i-1][j];
        dp[i][j] += dp[i-1][j];
      }
    }
    int64 ans = 0;
    for(int i = m; i <= (1<<20); ++i)
      ans += dp[n][i];
    printf("Case #%d: ", kase);
    cout << ans << endl;
  }
  return 0;
}
