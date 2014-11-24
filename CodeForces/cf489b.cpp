#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100 + 10;
int a[MAXN], b[MAXN], m, n;

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  while(cin >> n) {
    for(int i = 0; i < n; ++i)
      cin >> a[i];
    cin >> m;
    for(int i = 0; i < m; ++i)
      cin >> b[i];
    sort(a, a+n);
    sort(b, b+m);
    int bptr = 0;
    int ans = 0;
    for(int aptr = 0; aptr < n; ++aptr) {
      int tmp = bptr;
      bool flag = true;
      while(bptr < m) {
        if(abs(b[bptr++] - a[aptr]) <= 1) {
          ans++; flag = false; break;
        }
      }
      if(flag && bptr >= m) bptr = tmp;
    }
    cout << ans << endl;
  }
  return 0;
}
