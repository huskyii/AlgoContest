/*
ID: mail.ji1
PROG: nocows
LANG: C++11
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[201][101];
int n, k;

void solve(void) {
  for(int j = 1; j <= k; ++j)
    for(int i = 1; i <= n; i+=2)
      for(int m = 1; m <= i-2; ++m)
        dp[i][j]=(dp[i][j]+dp[m][j-1]*dp[i-1-m][j-1])%9901;
}

int main(void) {
  freopen("nocows.in", "r", stdin);
  freopen("nocows.out", "w", stdout);

  while(scanf("%d %d", &n, &k) != EOF) {
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= k; ++i)
      dp[1][i] = 1;
    solve();
    printf("%d\n", (9901+dp[n][k]-dp[n][k-1])%9901);
  }

  return 0;
}
