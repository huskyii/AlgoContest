#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

inline double solve(int num, int e) {
  double ans = 1 - (double)num*pow(10,3*e)/(num*pow(2, 10*e));
  return ans;
}

int main(void) {
  int T, num;
  double a[10];
  char unit[5];
  a[0] = 0;
  for(int i = 1; i <= 8; ++i)
    a[i] = (1 - pow(1000.0/1024, i))*100;
  cin >> T;
  for(int kase = 1; kase <= T; ++kase) {
    int ans;
    scanf("%d [%s]", &num, unit);
    switch(unit[0]) {
      case 'B': ans = 0; break;
      case 'K': ans = 1; break;
      case 'M': ans = 2; break;
      case 'G': ans = 3; break;
      case 'T': ans = 4; break;
      case 'P': ans = 5; break;
      case 'E': ans = 6; break;
      case 'Z': ans = 7; break;
      case 'Y': ans = 8; break;
    }
    printf("Case #%d: %.2f", kase, a[ans]);
    cout << "%\n";
  }
  return 0;
}
