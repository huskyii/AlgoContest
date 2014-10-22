// see Algorithm Design by KT
// section 6.1 weighted interval scheduling
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

struct Interval {
  int s, e, val;
  bool operator<(Interval b) const {
    return e < b.e;
  }
};

const int MAXN = 1000 + 5;
int dp[MAXN];
Interval inter[MAXN];

inline int p(int j) {
  for(int i = 1; i < j; ++i)
    if(inter[i].e > inter[j].s)
      return i-1;
  return j-1;
}

int main(void){
  int n, m, r, x;
  cin >> n >> m >> r;
  for(int i = 1; i <= m; ++i) {
    cin >> inter[i].s >> x >> inter[i].val;
    inter[i].e = x + r;
  }
  sort(inter+1, inter+m+1);
  for(int i = 1; i <= m; ++i)
    dp[i] = max(inter[i].val+dp[p(i)], dp[i-1]);
  cout << dp[m] << endl;
  return 0;
}
