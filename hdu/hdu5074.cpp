#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100 + 5;
int dp[MAXN][MAXN], score[MAXN][MAXN];
int T, n, m, a[MAXN];

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> T;
  while(T--) {
    cin >> n >> m;
    for(int i = 1; i <= m; ++i)
      for(int j = 1; j <= m; ++j)
        cin >> score[i][j];
    for(int i = 1; i <= n; ++i)
      cin >> a[i];
    memset(dp, 0, sizeof(dp));
    for(int i = 2; i <= n; ++i) {
      if(a[i] < 0 && a[i-1] < 0) {
        for(int j = 1; j <= m; ++j)
          for(int k = 1; k <= m; ++k)
            dp[i][j] = max(dp[i][j], dp[i-1][k] + score[k][j]);
      }
      if(a[i] < 0 && a[i-1] > 0) {
        for(int j = 1; j <= m; ++j)
          dp[i][j] = max(dp[i][j], dp[i-1][a[i-1]] + score[a[i-1]][j]);
      }
      if(a[i] > 0 && a[i-1] < 0) {
        for(int j = 1; j <= m; ++j)
          dp[i][a[i]] = max(dp[i][a[i]], dp[i-1][j]+score[j][a[i]]);
      }
      if(a[i] > 0 && a[i-1] > 0)
        dp[i][a[i]] = dp[i-1][a[i-1]] + score[a[i-1]][a[i]];
    }
    int ans = 0;
    for(int i = 1; i <= m; ++i)
      ans = max(ans, dp[n][i]);
    cout << ans << endl;
  }
  return 0;
}
