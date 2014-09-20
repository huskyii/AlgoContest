/****************************************/
/*          author: jiang.zhu           */
/*    email: mail.jiang.cn@gmail.com    */
/*         created on 2014-09-17        */
/****************************************/
#include <cstdio>
#include <queue>
using namespace std;

int main(void){
  int n, l;
  while(scanf("%d", &n) != EOF) {
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i = 0; i < n; ++i) {
      scanf("%d", &l);
      pq.push(l);
    }

    long long ans = 0;
    while(pq.size() > 1) {
      int a = pq.top(); pq.pop();
      int b = pq.top(); pq.pop();
      pq.push(a+b);
      ans = ans + a + b;
    }

    printf("%lld\n", ans);
  }
  return 0;
}
