// g++ WA到死，MS C++ 一次AC
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 10000 + 5;
double stock[MAXN];
int n, k;

inline bool foo(double x) {
  int cnt = 0;
  for(int i = 0; i < n; ++i) {
    cnt += (int)(stock[i]/x);
  }
  if(cnt >= k) return true;
  else return false;
}

int main(void){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  while(cin >> n >> k) {
    double max_ = 0;
    for(int i = 0; i < n; ++i) {
      cin >> stock[i];
      max_ = max(max_, stock[i]);
    }
    double lo = 0, hi = max_;
    int iter = 100;
    while(iter--) {
      double mid = lo + (hi-lo)/2;
      if(foo(mid)) lo = mid;
      else hi = mid;
    }
    cout << setprecision(2) << fixed << (((int)(lo*100)) * 0.01) << endl;
  }
  return 0;
}
