#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

// dp[x][y]
// 表示i分钟经过y次移动
// 能吃到的最大苹果数目
int dp[1005][35];

int main(void){
  int t, w, z;
  cin >> t >> w;
  for(int i = 1; i <= t; ++i) {
    cin >> z;
    dp[i][0] = dp[i-1][0] + 2 - z;
    for(int j = 1; j <= w && j <= i; j++) {
      dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]);
      if(j % 2) dp[i][j] += z - 1;
      else dp[i][j] += 2 - z;
    }
  }
  int cnt = 0;
  for(int i = 1; i <= t; ++i)
    cnt = max(dp[t][i], cnt);
  cout << cnt << endl;
  return 0;
}
