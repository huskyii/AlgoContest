/*
ID: mail.ji1
PROG: combo
LANG: C++11
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n;

inline bool close(int a, int b) {
  if(abs(a-b) <= 2 || abs(a-b) >= n-2) return true;
  return false;
}

inline bool is_ok(int a, int b, int c,
                  int x, int y, int z) {
  if(close(a, x) && close(b, y) && close(c, z)) return true;
  return false;
}

int main(void) {
  freopen("combo.in", "r", stdin);
  freopen("combo.out", "w", stdout);

  while(scanf("%d", &n) != EOF) {
    int f1, f2, f3, m1, m2, m3;
    cin >> f1 >> f2 >> f3 >> m1 >> m2 >> m3;

    int tot = 0;
    for(int a = 1; a <= n; ++a)
      for(int b = 1; b <= n; ++b)
        for(int c = 1; c <= n; ++c)
          if(is_ok(a, b, c, f1, f2, f3) ||
             is_ok(a, b, c, m1, m2, m3))
            tot++;
    printf("%d\n", tot);
  }

  return 0;
}
