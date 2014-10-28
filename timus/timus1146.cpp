#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 105;
const int INF = 100000000;
int rect[MAXN][MAXN];
int s[MAXN], n;

inline void process(int i, int j) {
  for(int a = 0; a < n; ++a) {
    s[a] = 0;
    for(int x = i; x <= j; ++x)
      s[a] += rect[a][x];
  }
}

inline int solve() {
  int ans = -INF, sum = 0;
  for(int i = 0; i < n; ++i){
    sum += s[i];
    ans = max(sum, ans);
    if(sum < 0) sum = 0;
  }
  return ans;
}

int main(void){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  while(cin >> n) {
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j)
        cin >> rect[i][j];

    int ans = -INF;
    for(int i = 0; i < n; ++i)
      for(int j = i; j < n; ++j){
        process(i, j);
        ans = max(ans, solve());
      }
    cout << ans << endl;
  }
  return 0;
}
