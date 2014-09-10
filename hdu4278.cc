/****************************************/
/*			author: jiang.zhu			*/
/*	  email: mail.jiang.cn@gmail.com	*/
/*		created on 2014-09-10			*/
/****************************************/
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long int64;
int num[10];

inline int pow(int base, int exp) {
  int ans = 1;
  while(exp--) {
    ans *= base;
  }
  return ans;
}

inline int process(int64 x) {
  int ans = 0;
  while(x > 0) {
    num[ans] = x%10;
    if(num[ans] > 3)
      num[ans]--;
    if(num[ans] > 7)
      num[ans]--;
    ans++;
    x /= 10;
  }
  return ans;
}

int a[10] = {0, 1, 2, 0, 3, 4, 5, 6, 0, 7};

int main(void){
  int x;
  while(scanf("%d", &x) != EOF && x) {
/*
 *    int64 ans = 0, k = 1, tmp = x;
 *    while(tmp > 0) {
 *      ans += a[tmp%10] * k;
 *      tmp /= 10;
 *      k *= 8;
 *    }
 */
    memset(num, 0, sizeof(num));
    int n = process(x);

    int ans = 0;
    for(int i = 0; i < n; i++) {
      ans += pow(8,i) * num[i];
    }
    printf("%d: %d\n", x, ans);
  }
  return 0;
}
