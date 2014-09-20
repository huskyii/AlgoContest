/****************************************/
/*          author: jiang.zhu           */
/*    email: mail.jiang.cn@gmail.com    */
/*         created on 2014-09-11        */
/****************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 5000 + 5;
int x1[maxn], x2[maxn], y1[maxn], y2[maxn], x[maxn], y[maxn];
bool v[maxn];

bool solve(int *a, int *b, int *c, int n) {
  bool flag = true;
  memset(v, 0, sizeof(v));
  fill(c, c+n, 0);

  for(int i = 1; i <= n; i++) {
    int rook = -1;
    int mina = n+1, minb = n+1;
    for(int j = 0; j < n; j++) {
      if(c[j] == 0) {
        if(b[j] < minb) { rook = j; minb = b[j]; mina = a[j]; }
        if(b[j] == minb && a[j] < mina) { rook = j; mina = a[j]; }
      }
    }

    flag = false;
    for(int j = a[rook]; j <= b[rook]; j++)
      if(!v[j]) { c[rook] = j; flag = true; v[j] = true; break; }

    if(!flag) break;
  }

  return flag;
}

int main(void){
  int n;
  while(scanf("%d", &n) && n) {
    for(int i = 0; i < n; i++)
      scanf("%d %d %d %d", x1+i, y1+i, x2+i, y2+i);

    if(solve(x1, x2, x, n) && solve(y1, y2, y, n))
      for(int i = 0; i < n; i++)
        printf("%d %d\n", x[i], y[i]);
    else
      printf("IMPOSSIBLE\n");
  }
  return 0;
}
