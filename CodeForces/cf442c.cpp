/****************************************/
/*          author: jiang.zhu           */
/*    email: mail.jiang.cn@gmail.com    */
/*         created on 2014-09-15        */
/****************************************/
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 500000 + 5;
int n, a[maxn], l[maxn], r[maxn];
pair<int, int> aa[maxn];

int main(void){
  while(scanf("%d", &n) != EOF) {
    for(int i = 0; i < n; ++i) {
      scanf("%d", a+i);
      aa[i].first = a[i];
      aa[i].second = i;
      l[i] = i - 1;
      r[i] = i + 1;
    }

    sort(aa, aa+n);

    long long ans = 0;
    for(int i = 0, x = 0; i < n-2; ++i) {
      int pos = aa[i].second;
      int L = l[pos], R = r[pos];

      ans += (long long)(a[pos] - x) * (n-2-i);
      x = a[pos];

      if(L >= 0 && R < n)
        ans += min(a[L], a[R]) - x;
      if(L >= 0)  r[L] = R;
      if(R < n)  l[R] = L;

    }
    cout << ans << endl;
  }
  return 0;
}
