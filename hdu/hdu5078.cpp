#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000 + 5;
int x[MAXN], y[MAXN], t[MAXN], n;

inline double difficulty(double x1, double y1, double t1, double x2, double y2, double t2) {
  if(t1 == t2) return 0;
  return sqrt((double)(x1-x2)*(x1-x2) + (double)(y1-y2)*(y1-y2))/abs(t1-t2);
}

int main(void) {
  int T;
  scanf("%d", &T);
  while(T--) {
    double ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
      scanf("%d %d %d", t+i, x+i, y+i);
    for(int i = 1; i < n; ++i)
      ans = max(ans, difficulty(x[i], y[i], t[i], x[i-1], y[i-1], t[i-1]));
    printf("%.10lf\n", ans);
  }
  return 0;
}
