// DP, 可以进一步优化内存占用
// 需要注意结果是字典序最大
// 我一直看成字典序最小，WA到死
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int T, m, n;
const int MAXN = 105;
const int INF = 0x7fffffff;
int matrix[MAXN][MAXN];
int dp[MAXN][MAXN];

inline int find_next(int idx, int row) {
  int ans = -1;
  for(int i = idx - 1; i <= idx + 1; ++i)
    if(0 < i && i <= n &&
        dp[row][idx] - dp[row+1][i] == matrix[row][idx])
      ans = i;
  return ans;
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> T;
  for(int kase = 1; kase <= T; ++kase) {
    cin >> m >> n;
    for(int i = 1; i <= m; ++i)
      for(int j = 1; j <= n; ++j)
        cin >> matrix[i][j];
    memcpy(dp, matrix, sizeof(dp));
    for(int i = m-1; i > 0; --i)
      for(int j = 1; j <= n; ++j) {
        int tmp = INF;
        for(int k = j-1; k <= j+1; ++k) {
          if(0 < k && k <= n)
            tmp = min(matrix[i][j] + dp[i+1][k], tmp);
        }
        dp[i][j] = tmp;
      }
    cout << "Case " << kase << endl;
    int idx = 1;
    for(int i = 1; i <= n; ++i)
      idx = dp[1][i] <= dp[1][idx]? i: idx;
    cout << idx;
    for(int i = 1; i < m; ++i) {
      idx = find_next(idx, i);
      cout << " " << idx;
    }
    cout << endl;
  }
  return 0;
}
