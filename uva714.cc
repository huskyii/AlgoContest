/****************************************/
/*          author: jiang.zhu           */
/*    email: mail.jiang.cn@gmail.com    */
/*         created on 2014-09-12        */
/****************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxm = 500 + 5;
int p[maxm], m, k;

inline int solve(long long maxp) {
  long long s = 0;
  int ans = 1;
  for(int i = 0; i < m; i++) {
    if(s + p[i] <= maxp) s += p[i];
    else { ans++; s = p[i]; }
  }
  return ans;
}

int last[maxm]; // last[i] = 1 iff i is the last book assigned to someone
void print(long long ans) {
  long long done = 0;
  memset(last, 0, sizeof(last));
  int remain = k;
  for(int i = m-1; i >= 0; i--) {
    if(done + p[i] > ans || i+1 < remain) {
      last[i] = 1; remain--; done = p[i];
    }
    else {
      done += p[i];
    }
  }
  for(int i = 0; i < m-1; i++) {
    printf("%d ", p[i]);
    if(last[i]) printf("/ ");
  }
  printf("%d\n", p[m-1]);
}

int main(void){
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d %d", &m, &k);
    long long sum = 0;
    int maxp = -1;
    for(int i = 0; i < m; i++) { scanf("%d", p+i); sum += p[i];  maxp = max(maxp, p[i]); }

    long long lo = maxp, hi = sum;
    while(lo < hi) {
      //printf("lo: %d, hi: %d\n", lo, hi);
      long long mid = lo + (hi - lo)/2;
      if(solve(mid) <= k) hi = mid;
      else lo = mid + 1;
    }

    print(lo);
  }
  return 0;
}

