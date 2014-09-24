/*
ID: mail.ji1
PROG: numtri
LANG: C++11
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000 + 5;
int tri[MAXN][MAXN], dp[MAXN][MAXN];

int main(void) {
  freopen("numtri.in", "r", stdin);
  freopen("numtri.out", "w", stdout);

  int r;
  while(scanf("%d", &r) != EOF) {
    for(int i = 0; i < r; ++i)
      for(int j = 0; j <= i; ++j)
        scanf("%d", &tri[i][j]);

    for(int j = 0; j < r; ++j)
      dp[r-1][j] = tri[r-1][j];
    for(int i = r-2; i >= 0; --i)
      for(int j = 0; j <= i; ++j)
        dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + tri[i][j];

    printf("%d\n", dp[0][0]);
  }

  return 0;
}
