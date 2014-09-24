/*
ID: mail.ji1
PROG: frac1
LANG: C++11
*/
#include <set>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;

inline int gcd(int a, int b) {
  return b == 0? a: gcd(b, a%b);
}

class cmp {
public:
  bool operator()(pair<int, int> a, pair<int, int> b) {
    return ((float)a.first/a.second) < ((float)b.first/b.second);
  }
};

int main(void) {
  freopen("frac1.in", "r", stdin);
  freopen("frac1.out", "w", stdout);

  int n;
  while(scanf("%d", &n) != EOF) {
    set< pair<int, int>, cmp > s;
    for(int a = 0; a <= n; ++a)
      for(int b = max(1,a); b <= n; ++b) {
        s.insert(make_pair(a/gcd(a,b), b/gcd(a,b)));
      }

    for(auto elem : s)
      printf("%d/%d\n", elem.first, elem.second);
  }

  return 0;
}
