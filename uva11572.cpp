/****************************************/
/*          author: jiang.zhu           */
/*    email: mail.jiang.cn@gmail.com    */
/*         created on 2014-09-11        */
/****************************************/
#include <cstdio>
#include <set>
using namespace std;

const int maxn = 1000000 + 5;

int snow[maxn];

int main(void){
  int T;
  scanf("%d", &T);
  while(T--) {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", snow+i);

    int ans = 0, r = 0;
    set<int> s;
    for(int l = 0; l < n; l++) {
      if(r > n) break;
      while(r < n && s.find(snow[r]) == s.end()) {
        s.insert(snow[r++]);
        ans = max(ans, r-l);
      }
      s.erase(snow[l]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
