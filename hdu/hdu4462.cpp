#include <cstdio>
#include <utility>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 60;
bool g[MAXN][MAXN];
typedef pair<int, int> pt;
pt pts[20];
int r[20], n, k;

inline bool judge(void) {
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j)
      if(!g[i][j]) return false;
  return true;
}

inline void update(const pt &p, int r) {
  for(int i = -r; i <= r; ++i)
    for(int j = -r; j <= r; ++j)
      if(abs(i)+abs(j) <= r && 0 < p.first+i &&
          p.first+i <= n && 0 < p.second+j
          && p.second+j <= n)
        g[p.first+i][p.second+j] = true;
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  while(cin >> n && n) {
    cin >> k;
    for(int i = 0; i < k; ++i)
      cin >> pts[i].first >> pts[i].second;
    for(int i = 0; i < k; ++i)
      cin >> r[i];
    int ans = 100;
    for(int i = 0; i < (1<<k); ++i) {
      memset(g, 0, sizeof(g));
      int step = 0;
      for(int j = 0; j < k; ++j) {
        g[pts[j].first][pts[j].second] = true;
        if(i & (1<<j)) {
          update(pts[j], r[j]);
          step++;
        }
      }
      //for(int i = 1; i <= n; ++i) {
        //for(int j = 1; j <= n; ++j)
          //cout << g[i][j] << " ";
        //cout << endl;
      //}
      if(judge()) ans = min(step, ans);
    }
    if(ans == 100) cout << -1 << endl;
    else cout << ans << endl;
  }
  return 0;
}
