#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100 + 5;
int cnt[MAXN];

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int T, n, a;
  cin >> T;
  while(T--) {
    memset(cnt, 0, sizeof(cnt));
    cin >> n;
    for(int i = 0; i < n; ++i) {
      cin >> a;
      cnt[a]++;
    }
    int ans = 1;
    for(int i = 1; i <= n; ++i)
      if(cnt[ans] < cnt[i]) ans = i;
    cout << ans << endl;
  }
  return 0;
}
