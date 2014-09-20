/****************************************/
/*          author: jiang.zhu           */
/*    email: mail.jiang.cn@gmail.com    */
/*         created on 2014-09-18        */
/****************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 1 << 30;
const int MAXN = 50 + 5;
const int MAXT = 200 + 5;
// t[i] 表示從車站i到i+1需要多少時間
int t[MAXN];
// train[t][i][0] 代表時刻t，車站i是否有往右開的列車
// train[t][i][1] 代表時刻t，車站i是否有往左開的列車
bool train[MAXT][MAXN][2];
// dp[i][j] 表示i時刻最少需要在j車站等多久
int dp[MAXT][MAXN];

int main(void){
  int n, target, x, m, kase = 0;
  while(scanf("%d", &n) != EOF && n) {
    //printf("n: %d\n", n);
    scanf("%d", &target);
    for(int i = 1; i < n; ++i) scanf("%d", t+i);

    memset(train, 0, sizeof(train));
    scanf("%d", &m);
    for(int i = 0; i < m; ++i) {
      scanf("%d", &x);
      for(int j = 1; x <= target && j <= n; ++j) {
        train[x][j][0] = true;
        x = x + t[j];
      }
    }
    scanf("%d", &m);
    for(int i = 0; i < m; ++i) {
      scanf("%d", &x);
      for(int j = 1; x <= target && j <= n; ++j) {
        train[x][n+1-j][1] = true;
        x = x + t[n-j];
      }
    }

    for(int i = 1; i < n; ++i)
      dp[target][i] = INF;
    dp[target][n] = 0;

    for(int i = target-1; i >= 0; --i) {
      for(int j = 1; j <= n; ++j) {
        dp[i][j] = dp[i+1][j] + 1;
        if(j < n && train[i][j][0] && i + t[j] <= target)
          dp[i][j] = min(dp[i][j], dp[i+t[j]][j+1]);
        if(j > 1 && train[i][j][1] && i + t[j-1] <= target)
          dp[i][j] = min(dp[i][j], dp[i+t[j-1]][j-1]);
      }
    }

    printf("Case Number %d: ", ++kase);
    if(dp[0][1] >= INF)
      printf("impossible\n");
    else
      printf("%d\n", dp[0][1]);

  }
  return 0;
}
