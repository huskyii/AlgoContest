#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 350 + 5;
int tri[MAXN][MAXN], dp[MAXN][MAXN];

int main(void){
  int n;
  cin >> n;
  for(int i = 1; i <= n; ++i)
    for(int j = 0; j < i; ++j)
      cin >> tri[i][j];
  for(int i = n; i > 0; --i)
    for(int j = 0; j < i; ++j)
      dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + tri[i][j];
  cout << dp[1][0] << endl;
  return 0;
}
