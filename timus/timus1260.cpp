#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[60];

int main(void){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 2;
  for(int i = 4; i <= 55; i++)
    dp[i] = dp[i-1] + dp[i-3] + 1;

  int n;
  while(cin >> n) {
    cout << dp[n] << endl;
  }
  return 0;
}
