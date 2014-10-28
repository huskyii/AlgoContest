#include <set>
#include <cmath>
#include <cstdio>
#include <utility>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
const int MAXN = 1000 + 5;
const int INF = 1000000 + 10;
const double sqrt2 = 1.4142135623730951;
double dp[MAXN][MAXN];

int main(void){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int n, m, k, x, y;
  while(cin >> n >> m >> k) {
    set<pii> s;
    for(int i = 0; i < k; ++i) {
      cin >> x >> y;
      s.insert(make_pair(x, y));
    }
    for(int i = 0; i <= n; ++i)
      for(int j = 0; j <= m; ++j) {
        if(i == 0 && j == 0) { dp[i][j] = 0; continue; }
        dp[i][j] = i>0? dp[i-1][j] + 1: INF;
        dp[i][j] = min(j>0? dp[i][j-1] + 1: INF, dp[i][j]);
        if(s.find(make_pair(i,j)) != s.end())
          dp[i][j] = min(dp[i][j], dp[i-1][j-1] + sqrt2);
      }
    cout << round(dp[n][m] * 100) << endl;
  }
  return 0;
}
