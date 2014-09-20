/****************************************/
/*          author: jiang.zhu           */
/*    email: mail.jiang.cn@gmail.com    */
/*         created on 2014-09-18        */
/****************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 30 + 5;
// blocks[i] 中保存了 type i block 的三維信息
// blocks[i][0] <= blocks[i][1] <= blocks[i][2]
int blocks[MAXN][3];
// dp[i][j] 保存的是type i block，高的index為j時的最高高度
int dp[MAXN][3];
int n;

inline void get_dim(int *v, int b, int dim) {
  int idx = 0;
  for(int i = 0; i < 3; ++i)
    if(i != dim) v[idx++] = blocks[b][i];
}

int solve(int i, int j) {
  int &ans = dp[i][j];
  if(ans > 0) return ans;
  int v1[2], v2[2];
  get_dim(v1, i, j);
  for(int a = 0; a < n; ++a)
    for(int b = 0; b < 3; ++b) {
      get_dim(v2, a, b);
      if(v2[0] < v1[0] && v2[1] < v1[1]) ans = max(ans, solve(a, b));
    }
  ans = ans + blocks[i][j];
  return ans;
}

int main(void){
  int kase = 0;
  while(scanf("%d", &n) != EOF && n) {
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < 3; ++j) scanf("%d", &blocks[i][j]);
      sort(blocks[i], blocks[i]+3);
    }
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < 3; ++j)
        ans = max(ans, solve(i, j));
    printf("Case %d: maximum height = %d\n", ++kase, ans);
  }
  return 0;
}
