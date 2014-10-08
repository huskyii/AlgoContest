#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;
int n, a[MAXN], m, q, tmp;

inline int query() {
  int lo = 1, hi = n;
  while(lo < hi) {
    int mid = lo + (hi-lo)/2;
    if(a[mid-1]+1 <= q && q <= a[mid]) return mid;
    if(q <= a[mid-1]) hi = mid;
    if(q > a[mid]) lo = mid + 1;
  }
  return lo;
}

int main(void){
  scanf("%d", &n);
  a[0] = 0;
  for(int i = 1; i <= n; ++i) { scanf("%d", &tmp); a[i] = a[i-1] + tmp; }
  scanf("%d", &m);
  while(m--) {
    scanf("%d", &q);
    printf("%d\n", query());
   }
  return 0;
}
