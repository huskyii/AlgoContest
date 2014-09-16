/****************************************/
/*          author: jiang.zhu           */
/*    email: mail.jiang.cn@gmail.com    */
/*         created on 2014-09-16        */
/****************************************/
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 300000 + 5;
int a[maxn], n;
long long sum[maxn];

inline void process() {
  long long ans = 0;
  for(int i = n-1; i >= 0; --i) sum[i] = ans = ans + a[i];
}

int main(void){
  while(scanf("%d", &n) != EOF) {
    for(int i = 0; i < n; ++i) scanf("%d", a+i);

    long long ans = 0;
    sort(a, a+n);
    process();
    /*
     *for(int i = 0; i < n; i++)
     *  cout << sum[i] << " ";
     *cout << endl;
     */
    ans += sum[0];
    for(int i = 0; i < n-1; ++i) ans = ans + sum[i];
    cout << ans << endl;
  }
  return 0;
}
