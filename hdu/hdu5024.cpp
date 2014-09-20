#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

const int MAXN = 100 + 5;
char g[MAXN][MAXN];
int n;
// dp[i][j][dir] 代表了從點i,j往方向dir出發的最長距離
int dp[MAXN][MAXN][8];
int table[8][2] = {
  {-1,  0},  // north       0
  {-1, -1},  // north-west  1
  { 0, -1},  // west        2
  { 1, -1},  // south-west  3
  { 1,  0},  // south       4
  { 1,  1},  // south-east  5
  { 0,  1},  // east        6
  {-1,  1}   // north-east  7
};

int h[8][2] = {
  {2, 6},
  {3, 7},
  {0, 4},
  {1, 5},
  {2, 6},
  {3, 7},
  {0, 4},
  {1, 5}
};

inline void compute_dp(int i, int j, int start, int dir) {
  if(i < 0 || i >= n || j < 0 || j >= n || g[i][j] == '#') return ;
  dp[i][j][dir] = max(dp[i][j][dir], start+1);
  compute_dp(i+table[dir][0], j+table[dir][1], dp[i][j][dir], dir);
}

int main(void){
  while(scanf("%d", &n) != EOF && n) {
    for(int i = 0; i < n; ++i) scanf("%s", g[i]);

    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j)
        if(g[i][j] == '.') {
          for(int dir = 0; dir < 8; ++dir){
            compute_dp(i, j, 0, dir);
          }
        }

    int ans = 0;
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j)
        if(g[i][j] == '.') {
          for(int dir = 0; dir < 8; ++dir) {
            ans = max(ans, dp[i][j][dir] + dp[i][j][h[dir][0]]);
            ans = max(ans, dp[i][j][dir] + dp[i][j][h[dir][1]]);
          }
        }
    printf("%d\n", ans - 1);
  }
  return 0;
}
