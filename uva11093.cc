/****************************************/
/*          author: jiang.zhu           */
/*    email: mail.jiang.cn@gmail.com    */
/*         created on 2014-09-13        */
/****************************************/
#include <cstdio>
using namespace std;

int q[100001], p[100001];

int main(void){
  int T, n, ans;
  scanf("%d", &T);
  for(int kase = 1; kase <= T; kase++) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", p+i);
    for(int i = 0; i < n; i++) scanf("%d", q+i);

    bool flag;
    for(int start = 0; start < n; start++) {
      int cur = 0;
      flag = true;
      ans = start+1;
      for(int j = 0; j < n; j++) {
        cur += p[start%n] - q[start%n];
        if(cur < 0) break;
        else start++;
      }
      if(cur >= 0) break;
      else flag = false;
    }

    if(flag) printf("Case %d: Possible from station %d\n", kase, ans);
    else printf("Case %d: Not possible\n", kase);
  }
  return 0;
}
