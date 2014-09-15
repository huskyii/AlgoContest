/****************************************/
/*          author: jiang.zhu           */
/*    email: mail.jiang.cn@gmail.com    */
/*         created on 2014-09-15        */
/****************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 500000 + 5;
int a[maxn];
long long cnt[maxn], sums[maxn];

int main(void){
  int n;
  while(scanf("%d", &n) != EOF) {
    long long sum = 0;
    for(int i = 0; i < n; i++) {
      scanf("%d", a+i);
      sum += a[i];
      sums[i] = i > 0 ? sums[i-1] + a[i] : a[i];
    }

    if(sum%3 != 0) {
      printf("0\n");
      continue;
    }

    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i+1 < n; i++) {
      if(sums[i] == 2*sum/3)
        cnt[i+1] = 1;
    }
    for(int i = n-2; i >= 0; --i)
      cnt[i] += cnt[i+1];

    long long ans = 0;
    for(int i = 0; i+2 < n; ++i) {
      if(sums[i] == sum/3)
        ans += cnt[i+2];
    }

    cout << ans << endl;
  }

  return 0;
}
