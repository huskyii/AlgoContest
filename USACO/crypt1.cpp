/*
ID: mail.ji1
PROG: crypt1
LANG: C++11
*/
#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 10;
int num[MAXN], n;

inline bool find(int x) {
  for(int i = 0; i < n; ++i)
    if(num[i] == x) return true;
  return false;
}

inline int get_digit(int x, int idx) {
  int base = 1;
  while(--idx) { base = base * 10; }
  return (x/base)%10;
}

inline bool check(int a, int b, int c, int d, int e) {
  int part1 = (a*100 + b*10 + c) * d;
  int part2 = (a*100 + b*10 + c) * e;
  if(part1 > 999 || part2 > 999 || part1 < 100 || part2 < 100) return false;
  for(int i = 1; i <= 3; ++i) {
    if(!find(get_digit(part1, i))) return false;
    if(!find(get_digit(part2, i))) return false;
  }
  int sum = part1 * 10 + part2;
  if(sum > 9999) return false;
  for(int i = 1; i <= 4; ++i)
    if(!find(get_digit(sum, i))) return false;
  return true;
}

int main(void) {
  freopen("crypt1.in", "r", stdin);
  freopen("crypt1.out", "w", stdout);

  while(scanf("%d", &n) != EOF) {
    for(int i = 0; i < n; ++i) scanf("%d", num+i);

    int cnt = 0;
    for(int a = 0; a < n; ++a)
      for(int b = 0; b < n; ++b)
        for(int c = 0; c < n; ++c)
          for(int d = 0; d < n; ++d)
            for(int e = 0; e < n; ++e)
              if(check(num[a], num[b], num[c], num[d], num[e]))
                cnt++;
    printf("%d\n", cnt);
  }

  return 0;
}
