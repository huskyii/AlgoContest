#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXT = 100005;
int m, t;
char s[MAXT], t2[256];
int tt[MAXT], t1[256];

int main(void){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> m >> t >> t1[(int)'u'] >> t1[(int)'f'] >> t1[(int)'d'];
  t2[(int)'u'] = 'd'; t2[(int)'f'] = 'f'; t2[(int)'d'] = 'u';
  for(int i = 1; i <= t; ++i)
    cin >> s[i];
  for(int i = 1; i <= t; ++i)
    tt[i] += tt[i-1] + t1[(int)s[i]] + t1[(int)t2[(int)s[i]]];
  int lo = 0, hi = t;
  while(hi > lo) {
    int mid = lo + (hi-lo)/2;
    if(tt[mid] > m)
      hi = mid;
    else
      lo = mid + 1;
  }
  cout << (lo - 1) << endl;
  return 0;
}
