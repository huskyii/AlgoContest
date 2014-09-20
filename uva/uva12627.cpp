/****************************************/
/*          author: jiang.zhu           */
/*    email: mail.jiang.cn@gmail.com    */
/*         created on 2014-09-13        */
/****************************************/
#include <cstdio>
using namespace std;

typedef long long int64;

// how many red balloons after k hours
inline long long c(int i) {
  return i == 0 ? 1 : c(i-1)*3;
}

// how many red balloons in the first i rows, after k hours
long long f(int k, int i) {
  if(i == 0) return 0;
  if(k == 0) return 1;

  int k2 = 1 << (k-1);
  if(i >= k2) return f(k-1, i-k2) + c(k-1)*2;
  else return f(k-1, i) * 2;
}

// how many red balloons in the last i rows, after k hours
long long g(int k, int i) {
  if(i == 0) return 0;
  if(k == 0) return 1;

  int k2 = 1 << (k-1);
  if(i >= k2) return g(k-1, i-k2) + c(k-1);
  else return g(k-1,i);
}

int main(void){
  int T;
  int k, upper, lower;
  scanf("%d", &T);
  for(int kase = 1; kase <= T; kase++) {
    scanf("%d %d %d", &k, &upper, &lower);

    printf("Case %d: %lld\n", kase, f(k, lower) - f(k, upper-1) );
  }
  return 0;
}
