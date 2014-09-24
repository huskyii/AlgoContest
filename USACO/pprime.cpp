/*
ID: mail.ji1
PROG: pprime
LANG: C++11
*/
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 100000000 + 5;
bool v[MAXN];
char str[10];

inline int to_str(int x) {
  int i = 0;
  while(x > 0) { str[i++] = x%10 + '0'; x = x/10; }
  return i;
}

inline bool is_pal(int x) {
  int len = to_str(x);
  for(int i = 0; i < len/2; ++i)
    if(str[i] != str[len-1-i]) return false;
  return true;
}

int main(void) {
  freopen("pprime.in", "r", stdin);
  //freopen("pprime.out", "w", stdout);

  int a, b;
  while(scanf("%d %d", &a, &b) != EOF) {
    int m = sqrt(MAXN);
    for(int i = 2; i <= m; ++i) if(!v[i]) {
      for(int j = i*i; j <= MAXN; j = j+i) v[j] = true;
    }

    for(int i = 2; i <= MAXN; ++i)
      if(!v[i] && is_pal(i)) printf("%d, ", i);
  }

  return 0;
}
