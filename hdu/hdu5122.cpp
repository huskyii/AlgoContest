#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000000 + 10;
int a[MAXN], T, n;

int main(void) {
  cin >> T;
  for(int kase = 1; kase <= T; ++kase) {
    cin >> n;
    for(int i = 1; i <= n; ++i)
      cin >> a[i];
    int m = MAXN, ans = 0;
    for(int i = n; i > 0; --i)
      if(a[i] < m) m = a[i];
      else ans++;
    printf("Case #%d: %d\n", kase, ans);
  }
  return 0;
}
