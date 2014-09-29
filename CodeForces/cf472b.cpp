/****************************************/
/*          author: jiang.zhu           */
/*    email: mail.jiang.cn@gmail.com    */
/*         created on 2014-09-29        */
/****************************************/
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 2000 + 5;
int n, k, f[MAXN];

int main(void){
  scanf("%d %d", &n, &k);
  for(int i = 1; i <= n; ++i) scanf("%d", f+i);

  sort(f+1, f+n+1);

  long long ans = 0;
  for(int i = 0; n-i*k > 0; ++i)
    ans = ans + f[n-i*k] - 1;
  ans = ans * 2;
  cout << ans << endl;

  return 0;
}
