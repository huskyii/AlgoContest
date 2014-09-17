/****************************************/
/*          author: jiang.zhu           */
/*    email: mail.jiang.cn@gmail.com    */
/*         created on 2014-09-17        */
/****************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 3000 + 5;
int t[maxn];

int main(void){
  int n, v, a, b;
  while(scanf("%d %d", &n, &v) != EOF) {
    memset(t, 0, sizeof(t));
    for(int i = 0; i < n; ++i) {
      scanf("%d %d", &a, &b);
      // 真是坑爹，可以有a相同的情況，所以得是加上b
      t[a] = t[a] + b;
    }

    int fromLastDay = 0, ans = 0;
    for(int i = 1; i <= 3001; ++i) {
      ans += min(v, fromLastDay + t[i]);
      fromLastDay = min(max(0, t[i] + fromLastDay - v), v);
    }
    printf("%d\n", ans);
  }
  return 0;
}
