#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int64;
const int MAXN = 500 + 5;
int64 dp[MAXN][MAXN];
// dp[i][j] 是i个砖，最底下有j个砖的方法数

int main(void){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int n;

  for(int i = 1; i <= 500; ++i)
    dp[i][i] = 1;
  for(int i = 2; i <= 500; ++i)
    for(int j = 1; j < i; ++j)
      for(int k = 1; k <= i-j && k < j; ++k)
        dp[i][j] += dp[i-j][k];

  while(cin >> n) {
    int64 ans = 0;
    for(int i = 1; i < n; ++i)
      ans += dp[n][i];
    cout << ans << endl;
  }
  return 0;
}
