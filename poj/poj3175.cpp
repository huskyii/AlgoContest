#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

double table[] = {1, 1e-1, 1e-2, 1e-3, 1e-4,
                  1e-5, 1e-6, 1e-7, 1e-8, 1e-9};
typedef long long int64;

int main(void){
  int l, x;
  cin >> l >> x;
  double a = x * table[l];
  double b = (x+1) * table[l];
  for(int i = 0; ; ++i) {
    int64 tmp = (int64)((a+i)*(a+i)) + 1;
    if(tmp < (b+i)*(b+i)) {
      cout << tmp << endl;
      break;
    }
  }
  return 0;
}
