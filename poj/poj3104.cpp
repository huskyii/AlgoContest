#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
const int MAXN = 100000 + 10;
int a[MAXN];
typedef long long int64;

inline bool p(int x) {
  int64 cnt = 0;
  for(int i = 0; i < n; ++i) {
    if(a[i] > x)
      cnt += (a[i]-x)%(k-1) == 0?
        (a[i]-x)/(k-1): (a[i]-x)/(k-1) + 1;
  }
  if(cnt > x) return true;
  else return false;
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  while(cin >> n) {
    int hi = 0, lo = 0;
    for(int i = 0; i < n; ++i) {
      cin >> a[i];
      hi = max(hi, a[i]);
    }
    cin >> k;
    if(k == 1) {
      cout << hi << endl;
      continue;
    }
    while(lo < hi) {
      int mid = lo + (hi-lo)/2;
      if(p(mid)) lo = mid + 1;
      else hi = mid;
    }
    cout << lo << endl;
  }
  return 0;
}
