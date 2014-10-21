#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000000 + 10;
int dp[MAXN];

int main(void){
  int n;
  cin >> n;
  dp[1] = 1;
  for(int i = 2; i <= n; ++i) {
    if(i%2 == 0)
      dp[i] = (dp[i-1] + dp[i/2]) % 1000000000;
    else
      dp[i] = dp[i-1];
  }
  cout << dp[n] << endl;
  return 0;
}
