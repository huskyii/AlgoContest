#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;
const int MOD = 365*24*60*60;
typedef long long int64;
typedef pair<int64, int64> P;
P ps[MAXN];
bool cmp(P p1, P p2) {
  return (p1.first*p2.second) >
    (p2.first*p1.second);
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int n;
  while(cin >> n && n) {
    for(int i = 0; i < n; ++i)
      cin >> ps[i].second >> ps[i].first;
    sort(ps, ps+n, cmp);
    int64 cur = 0;
    for(int i = 0; i < n; ++i) {
      cur += ps[i].second%MOD + (cur * (ps[i].first%MOD))%MOD;
      cur %= MOD;
    }
    cout << cur <<endl;
  }
  return 0;
}
