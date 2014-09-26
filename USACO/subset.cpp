/*
ID: mail.ji1
PROG: subset
LANG: C++11
*/
#include <cstdio>
#include <cstring>
using namespace std;

// dp[i]代表1...N中有多少種子集和為i
long long dp[1000];

int main(void) {
  freopen("subset.in", "r", stdin);
  freopen("subset.out", "w", stdout);

  int n;
  while(scanf("%d", &n) != EOF) {
    if( (n*(n+1))/2 % 2) { printf("0\n"); continue; }
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 1; i <= n; ++i)
      for(int j = (n*(n+1))/2 - i; j >= 0; --j) {
        dp[j+i] += dp[j];
      }
    printf("%lld\n", dp[(n*(n+1))/4]/2);
  }

  return 0;
}
