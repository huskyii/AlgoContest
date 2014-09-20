/****************************************/
/*          author: jiang.zhu           */
/*    email: mail.jiang.cn@gmail.com    */
/*         created on 2014-09-17        */
/****************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 5;
bool t[maxn];

int main(void){
  int n, r, x;
  while(scanf("%d %d", &r, &n) != EOF && r != -1) {
    memset(t, 0, sizeof(t));
    while(n--) { scanf("%d", &x); t[x] = true; }

    int ans = 0;
    for(int i = 0; i <= 1000; ++i) {
      if(t[i]) {
        ans++;
        for(int j = i+r; j >= i; --j)
          if(t[j]) { i=j+r; break; }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
