/****************************************/
/*          author: jiang.zhu           */
/*    email: mail.jiang.cn@gmail.com    */
/*         created on 2014-09-12        */
/****************************************/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 200000 + 5;
const int inf = 1000000000 + 5;
int a[maxn], g[maxn], f[maxn], dp[maxn];

int main(void){
  int T, n;
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) scanf("%d", a+i);
    if(n == 1) { printf("1\n"); continue; }

    // compute g[i], length of longest increasing continuous
    // subsequence ending at i
    g[0] = 1;
    for(int i = 1; i < n; i++)
      if(a[i-1] < a[i]) g[i] = g[i-1] + 1;
      else g[i] = 1;

    // compute f[i], length of longest increasing continuous
    // subsequence starting at i
    f[n-1] = 1;
    for(int i = n-2; i >= 0; i--)
      if(a[i] < a[i+1]) f[i] = f[i+1] + 1;
      else f[i] = 1;

    // dp[i] 是長度為i的最長連續上升子序列的最後一位中的最小值
    fill(dp+1, dp+n+1, inf);
    int ans = 0;
    for(int i = 0; i < n; i++) {
      int len = lower_bound(dp+1, dp+n+1, a[i]) - dp;
      ans = max(ans, len+f[i]-1);
      dp[g[i]] = min(dp[g[i]], a[i]);
    }

    printf("%d\n", ans);
  }
  return 0;
}
