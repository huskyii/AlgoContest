#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, c, ans;
const int MAXN = 100000 + 5;
int stall[MAXN], inter[MAXN];

inline bool foo(int x) {
  bool flag = false;
  int cnt = 0, acc = stall[0];
  for(int i = 0; i < n; i++) {
    if(acc + x <= stall[i]) {
      //cout << acc << " " << x << " " << stall[i] << endl;
      if(acc + x == stall[i]) flag = true;
      cnt++;
      acc = stall[i];
    }
  }
  if(cnt >= c-1) {
    if(flag) ans = x;
    return true;
  }
  else return false;
}

int main(void){
  scanf("%d %d", &n, &c);
  for(int i = 0; i < n; ++i)
    scanf("%d", stall+i);
  sort(stall, stall+n);
  int lo = 0, hi = stall[n-1];
  while(lo < hi) {
    int mid = lo + (hi-lo)/2;
    if(foo(mid))
      lo = mid + 1;
    else
      hi = mid;
  }
  cout << ans << endl;
  return 0;
}
