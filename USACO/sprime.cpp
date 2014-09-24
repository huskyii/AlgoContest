/*
ID: mail.ji1
PROG: sprime
LANG: C++11
*/
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 100000000 + 5;
bool v[MAXN];

inline int pow10(int exp) {
  int ans = 1;
  while(exp--) ans = ans*10;
  return ans;
}

inline bool is_superprime(int prime) {
  while(prime > 0){
    if(v[prime]) return false;
    prime = prime / 10;
  }
  return true;
}

int main(void) {
  freopen("sprime.in", "r", stdin);
  freopen("sprime.out", "w", stdout);

  int n;
  while(scanf("%d", &n) != EOF) {
    int p = pow10(8);

    v[0] = v[1] = true;
    int m = sqrt(p+0.5);
    for(int i = 2; i <= m; ++i) if(!v[i])
      for(int j = i*i; j <= p; j = j+i) v[j] = true;

    for(int i = 0; i < p; ++i) if(!v[i]) {
      if(is_superprime(i)) printf("%d, ", i);
    }
  }

  return 0;
}
