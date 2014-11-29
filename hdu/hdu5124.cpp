#include <cstdio>
#include <utility>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 200000 + 10;
pair<int, int> a[MAXN];

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int T, n, x, y;
  cin >> T;
  while(T--) {
    cin >> n;
    for(int i = 0; i < n; ++i) {
      cin >> x >> y;
      a[2*i] = make_pair(x, 1);
      a[2*i+1] = make_pair(y+1, -1);
    }
    sort(a, a+2*n);
    int tmp = 0, ans = 0;
    for(int i = 0; i < 2*n; ++i) {
      cout << a[i].first << " " << a[i].second << endl;
      tmp += a[i].second;
      ans = max(ans, tmp);
    }
    cout << ans << endl;
  }
  return 0;
}
