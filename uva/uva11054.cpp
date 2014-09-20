/****************************************/
/*          author: jiang.zhu           */
/*    email: mail.jiang.cn@gmail.com    */
/*         created on 2014-09-11        */
/****************************************/
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(void){
  int n;
  while(scanf("%d", &n) != EOF && n) {
    long long ans = 0;
    long long cur = 0;
    int tmp;
    for(int i = 0; i < n; i++) {
      ans += abs(cur);
      scanf("%d", &tmp);
      cur += tmp;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
