/*
ID: mail.ji1
PROG: sprime
LANG: C++11
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int ans[83] = {2, 3, 5, 7, 23, 29, 31, 37, 53, 59, 71, 73, 79, 233, 239, 293, 311, 313, 317, 373, 379, 593, 599, 719, 733, 739, 797, 2333, 2339, 2393, 2399, 2939, 3119, 3137, 3733, 3739, 3793, 3797, 5939, 7193, 7331, 7333, 7393, 23333, 23339, 23399, 23993, 29399, 31193, 31379, 37337, 37339, 37397, 59393, 59399, 71933, 73331, 73939, 233993, 239933, 293999, 373379, 373393, 593933, 593993, 719333, 739391, 739393, 739397, 739399, 2339933, 2399333, 2939999, 3733799, 5939333, 7393913, 7393931, 7393933, 23399339, 29399999, 37337999, 59393339, 73939133};

inline int pow10(int exp) {
  int ans = 1;
  while(exp--) ans = ans*10;
  return ans;
}

int main(void) {
  freopen("sprime.in", "r", stdin);
  freopen("sprime.out", "w", stdout);

  int n;
  while(scanf("%d", &n) != EOF) {
    int lo = pow10(n-1), hi = pow10(n) - 1;
    for(auto it = lower_bound(ans, ans+83, lo);
        it != upper_bound(ans, ans+83, hi); ++it)
      printf("%d\n", *it);
  }

  return 0;
}
