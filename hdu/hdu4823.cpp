#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int64;
int64 n, m, v, k;
int solve(int64 a) {
  int ans = 0;
  while(a < n && a >= v) {
    int64 b = (a-v)*k;
    a = b > a? b: -1;
    ans++;
  }
  if(a >= n) return ans;
  return -1;
}

int main(void) {
  int T;
  cin >> T;
  while(T--) {
    cin >> n >> m >> v >> k;
    cout << solve(m) << endl;
  }
  return 0;
}
