// 应该还可以用dfs backtrack 来做
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int64;
int64 dp[50];

int main(void){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int n;
  while(cin >> n) {
    dp[1] = 2;
    int64 xx = 0;
    // end with blue stripe
    for(int i = 2; i <= n; ++i) {
      dp[i] = (dp[i-1] - xx) * 2 + xx;
      xx = dp[i-1] - xx;
    }
    cout << dp[n] - xx << endl;
  }
  return 0;
}
