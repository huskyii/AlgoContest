/****************************************/
/*          author: jiang.zhu           */
/*    email: mail.jiang.cn@gmail.com    */
/*         created on 2014-09-12        */
/****************************************/
#include <cstdio>
#include <queue>
#include <vector>
#include <set>
using namespace std;

int main(void){
  int n, elem;
  while(scanf("%d", &n) != EOF && n) {
    priority_queue< int, vector<int>, greater<int> > pq;
    for(int i = 0; i < n; i++) {
      scanf("%d", &elem);
      pq.push(elem);
    }

    int ans = 0;
    for(int i = 1; i < n; i++){
      int a = pq.top(); pq.pop();
      int b = pq.top(); pq.pop();
      pq.push(a + b);
      ans += a + b;
    }

    printf("%d\n", ans);
  }
  return 0;
}
