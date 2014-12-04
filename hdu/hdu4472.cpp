#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int64;
const int MOD = 1e9 + 7;
int64 dp[1500];

inline void init(void) {
  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 2;
  for(int i = 4; i <= 1000; ++i) {
    int n = i - 1;
    for(int j = 1; j < i; ++j)
      if(n%j == 0) {
        dp[i] += dp[n/j];
        dp[i] %= MOD;
      }
  }
}

int main(void) {
  init();
  int n, kase = 0;
  while(cin >> n) {
    cout << "Case " << ++kase << ": ";
    cout << dp[n] << endl;
  }
  return 0;
}
