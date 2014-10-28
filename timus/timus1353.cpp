#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[10][90];
// dp[i][j]代表用i个数位和为j的方案数

int main(void){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int s;
  while(cin >> s) {
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < 10; ++i) {
      dp[1][i] = 1;
      dp[i][0] = 1;
    }
    for(int i = 2; i < 10; ++i)
      for(int j = 1; j <= s; ++j)
        for(int k = 0; k < 10 && j-k >= 0; ++k)
          dp[i][j] += dp[i-1][j-k];
    if(s == 1) cout << 10 << endl;
    else cout << dp[9][s] << endl;
  }
  return 0;
}
