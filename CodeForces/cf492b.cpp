#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e3 + 5;
int a[MAXN];
int n, l;

inline bool p(double d) {
  if(a[0] > d || a[n-1] + d < l)
    return false;
  for(int i = 1; i < n; ++i) {
    if(a[i] - a[i-1] > 2*d)
      return false;
  }
  return true;
}

int main(void) {
  std::cin.tie(0);
  while(cin >> n >> l) {
    for(int i = 0; i < n; ++i)
      cin >> a[i];
    sort(a, a+n);
    double lo = 0, hi = 1e9;
    for(int i = 0; i < 200; ++i) {
      double mid = lo + (hi-lo)/2.0;
      if(p(mid)) hi = mid;
      else lo = mid;
    }
    printf("%.9f\n", lo);
  }
  return 0;
}
