/****************************************/
/*          author: jiang.zhu           */
/*    email: mail.jiang.cn@gmail.com    */
/*         created on 2014-09-15        */
/****************************************/
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long int64;

int n, m;

inline int64 foo(int64 x) {
  int64 ans = 0;
  --x;
  for(int i = 1; i <= n; ++i) ans = ans + min((int64)m, x/i);
  return ans;
}

int main(void){
  int64 k;
  while(scanf("%d %d", &n, &m) != EOF) {
    cin >> k;

    int64 lo = 1, hi = (int64)n*m+1;
    while(lo < hi) {
      int64 mid = lo + (hi-lo)/2;
      if(foo(mid) < k) lo = mid + 1;
      else hi = mid;
    }

    cout << lo-1 << endl;
  }
  return 0;
}
