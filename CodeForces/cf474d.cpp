#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int64;
const int MAXN = 100000 + 10;
const int MOD = 1000000000 + 7;
int64 dp[MAXN];
int64 sum[MAXN];
bool v[MAXN];
int64 t, k, a, b;

inline int64 foo(int64 x) {
  if(v[x]) return dp[x];
  dp[x] = (foo(x-1) + foo(x-k))%MOD;
  v[x] = true;
  return dp[x];
}

inline int64 solve(int64 a, int64 b) {
  if(sum[b] == 0)
    for(int i = 1; i <= b; ++i)
      if(!sum[i]) sum[i] = sum[i-1] + foo(i);
  return (sum[b]-sum[a]+foo(a))%MOD;
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> t >> k;
  for(int i = 0; i < k; ++i) {
    dp[i] = 1;
    v[i] = true;
  }
  while(t--) {
    cin >> a >> b;
    cout << solve(a, b) << endl;
  }
  return 0;
}
