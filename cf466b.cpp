/****************************************/
/*          author: jiang.zhu           */
/*    email: mail.jiang.cn@gmail.com    */
/*         created on 2014-09-15        */
/****************************************/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void){
  int _n, _a, _b;
  while(scanf("%d %d %d", &_n, &_a, &_b) != EOF) {
    long long n = (long long)_n, a = (long long)_a, b = (long long)_b;
    if(6*n <= a*b) { cout<< a*b << endl << a << " " << b << endl; continue; }

    bool flag = false;
    if(a > b) { swap(a, b); flag = true; }

    long long sq = 1e18, a1, b1;
    for(long long newa = a; newa*newa <= 6*n; ++newa) {
      long long newb = 6*n/newa;
      if(newa*newb < 6*n) newb++;
      if(newb < b) continue;

      if(newa*newb < sq) {
        sq = newa*newb;
        a1 = newa;
        b1 = newb;
      }
    }

    if(flag) swap(a1, b1);
    cout << a1*b1 << endl << a1 << " " << b1 << endl;
  }
  return 0;
}
