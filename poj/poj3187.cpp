/****************************************/
/*          author: jiang.zhu           */
/*    email: mail.jiang.cn@gmail.com    */
/*         created on 2014-10-14        */
/****************************************/
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, s, b[10];
int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

inline int compute_sum(int cnt) {
  while(cnt--) {
    for(int i = 0; i < cnt; ++i)
      b[i] += b[i+1];
  }
  return b[0];
}

int main(void){

  scanf("%d %d", &n, &s);
  do {
    memcpy(b, a, sizeof(a));
    if(compute_sum(n) == s) break;
  } while(next_permutation(a, a+n));

  for(int i = 0; i < n; ++i) {
    if(i) printf(" ");
    printf("%d", a[i]);
  }
  printf("\n");
  return 0;
}
