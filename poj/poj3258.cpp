#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int l, n, m;
const int MAXN = 50000 + 10;
int d[MAXN];

inline bool p(int x) {
  int cnt = 0, pos = 0;
  for(int i = 0; i < n; ++i) {
    if(d[i] - pos >= x) pos = d[i];
    else cnt++;
  }
  if(l - pos < x) cnt++;
  if(cnt > m) return true;
  else return false;
}

int main(void){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> l >> n >> m;
  for(int i = 0; i < n; ++i)
    cin >> d[i];
  sort(d, d+n);
  int hi = l, lo = 0;
  while(lo <= hi) {
    int mid = lo + (hi-lo)/2;
    if(p(mid)) hi = mid - 1;
    else lo = mid + 1;
  }
  cout << hi << endl;
  return 0;
}
