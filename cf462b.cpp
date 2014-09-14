/****************************************/
/*          author: jiang.zhu           */
/*    email: mail.jiang.cn@gmail.com    */
/*         created on 2014-09-15        */
/****************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

// 一定要用 long long，
// 下面的k也要轉換成 long long
// 不然，WA 停都停不下來
long long cnt[26];

int main(void){
  int n, k;
  long long k_;
  while(scanf("%d %d", &n, &k) != EOF) {
    k_ = (long long) k;
    memset(cnt, 0, sizeof(cnt));
    getchar();
    for(int i = 0; i < n; i++) cnt[getchar()-'A']++;
    getchar();

    long long ans = 0;
    sort(cnt, cnt+26);
    for(int i = 25; i >= 0; --i) {
      ans += (k_ > cnt[i] ? cnt[i]*cnt[i] : k_*k_);
      k_ -= cnt[i];
      if(k_ <= 0) break;
    }
    cout << ans << endl;
  }
  return 0;
}
