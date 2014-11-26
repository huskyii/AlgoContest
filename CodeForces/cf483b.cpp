#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int cnt1, cnt2, x, y;

inline bool p(int mid, int cnt1, int cnt2) {
  int f1 = mid/x, f2 = mid/y, f3 = mid/(x*y);
  cnt1 -= (f2-f3); cnt2 -= (f1-f3);
  cnt1 = cnt1 > 0? cnt1: 0;
  cnt2 = cnt2 > 0? cnt2: 0;
  if(cnt1 + cnt2 > mid - f1 - f2 + f3)
    return false;
  else
    return true;
}

int main(void) {
  while(cin >> cnt1 >> cnt2 >> x >> y) {
    int lo = 0, hi = 0x7fffffff;
    while(lo < hi) {
      int mid = lo + (hi-lo)/2;
      if(p(mid, cnt1, cnt2)) hi = mid;
      else lo = mid + 1;
    }
    cout << lo << endl;
  }
  return 0;
}
