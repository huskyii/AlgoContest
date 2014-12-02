#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;
typedef long long int64;
const int64 INF = 1e18;
int64 p[MAXN], s[MAXN], q, dp[MAXN];
int T, n, m;

int main(void) {
  scanf("%d", &T);
  while(T--) {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i)
      scanf("%I64d %I64d", s+i, p+i);
    int64 min_ = INF;
    for(int i = n-1; i >= 0; i--)
      dp[i] = min_ = min(s[i]*p[i], min_);
    for(int i = 0; i < m; ++i) {
      scanf("%I64d", &q);
      if(q >= s[n-1]) printf("%I64d\n", q*p[n-1]);
      else {
        int pos = upper_bound(s, s+n, q) - s;
        int64 ans = q*p[pos-1];
        ans = min(ans, dp[pos]);
        printf("%I64d\n", ans);
      }
    }
  }
  return 0;
}
