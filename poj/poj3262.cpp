#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
typedef long long int64;
typedef pair<int64, int64> pii;
pii cows[MAXN];
inline bool cmp(const pii &a, const pii &b) {
  // 考虑a，b两头牛。
  // 先牵走牛a的损失是 2 * d[b] * t[a]
  // 先牵走牛b的损失是 2 * d[a] * t[b]
  return a.first*b.second < b.first*a.second;
}

int main(void){
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%lld %lld", &cows[i].first, &cows[i].second);
  sort(cows, cows+n, cmp);
  int64 t = 0, ans = 0;
  for(int i = 0; i < n; ++i) {
    ans += t * cows[i].second;
    t += 2 * cows[i].first;
  }
  cout << ans << endl;
  return 0;
}
