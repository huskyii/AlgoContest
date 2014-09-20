/****************************************/
/*          author: jiang.zhu           */
/*    email: mail.jiang.cn@gmail.com    */
/*         created on 2014-09-11        */
/****************************************/
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 4000 + 5;
int a[maxn], b[maxn], c[maxn], d[maxn], sum[maxn*maxn], n, m;

int main(void){
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
      scanf("%d %d %d %d", a+i, b+i, c+i, d+i);

    m = 0;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        sum[m++] = a[i] + b[j];

    sort(sum, sum+m);

    long long cnt = 0;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        cnt += upper_bound(sum, sum+m, -(c[i]+d[j])) - lower_bound(sum, sum+m, -(c[i]+d[j]));

    printf("%lld\n", cnt);
    if(T) printf("\n");
  }
  return 0;
}
