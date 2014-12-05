#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

bool xx[1005][1005];
int yy[1005];

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int n, m, k, p, a, b;
  string x, y;
  while(cin >> n >> m >> k && n) {
    cin >> p;
    memset(xx, 0, sizeof(xx));
    memset(yy, 0, sizeof(yy));
    for(int i = 0; i < p; ++i) {
      cin >> x >> a >> y >> b;
      if(x == "clothes") {
        xx[a][b] = true;
      } else {
        yy[a]++;
      }
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= m; ++j){
        if(!xx[i][j]) {
          ans += (k - yy[j]);
        }
      }
    cout << ans << endl;
  }
  return 0;
}
