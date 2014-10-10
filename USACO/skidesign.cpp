/*
ID: mail.ji1
PROG: skidesign
LANG: C++11
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000 + 10;
int n, h[MAXN];

inline int compute_cost(int s) {
  int cost = 0, diff;
  for(int i = 0; i < n; ++i) {
    if(s + 17 < h[i]) diff = h[i] - s - 17;
    else if(s > h[i]) diff = s - h[i];
    else diff = 0;
    cost += diff * diff;
  }
  return cost;
}

int main(void) {
  freopen("skidesign.in", "r", stdin);
  freopen("skidesign.out", "w", stdout);

  while(scanf("%d", &n) != EOF) {
    for(int i = 0; i < n; ++i) scanf("%d", h+i);
    sort(h, h+n);

    int min_cost = 10000000;
    for(int s = h[0]; s < h[n-1]; ++s)
      min_cost = min(min_cost, compute_cost(s));

    printf("%d\n", min_cost);
  }

  return 0;
}
