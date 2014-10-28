#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[20];

int main(void){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int n, k;
  // 一开始看错题目了，懒得改后面的，所以n，k错位了
  while(cin >> k >> n) {
    memset(dp, 0, sizeof(dp));
    dp[1] = n-1;
    int xx = 0;
    // xx seq end with 0
    for(int i = 2; i <= k; ++i) {
      dp[i] = (dp[i-1] - xx) * n + xx * (n-1);
      xx = dp[i-1] - xx;
    }
    cout << dp[k] << endl;
  }
  return 0;
}

