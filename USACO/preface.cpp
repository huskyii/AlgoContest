/*
ID: mail.ji1
PROG: preface
LANG: C++11
*/
#include <cstdio>
#include <cstring>
using namespace std;

char table[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int val[7] = {1, 5, 10, 50, 100, 500, 1000};
int cnt[7];

inline int pow10(int x) {
  int ans = 1;
  while(x--) { ans = ans * 10; }
  return ans;
}

inline int get(int x, int idx) {
  return (x/pow10(idx)) % 10;
}

inline void foo(int x) {
  for(int i = 0; i <= 3; ++i) {
    int digit = get(x, i);
    if(digit == 4) { ++cnt[2*i]; ++cnt[2*i+1]; }
    else if(digit == 9) { ++cnt[2*i]; ++cnt[2*i+2]; }
    else if(digit > 4) {
      cnt[2*i] += digit-5;
      ++cnt[2*i+1];
    } else { cnt[2*i] += digit; }
  }
}

int main(void) {
  freopen("preface.in", "r", stdin);
  freopen("preface.out", "w", stdout);

  int n;
  while(scanf("%d", &n) != EOF) {
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i <= n; ++i) foo(i);

    for(int i = 0; cnt[i] != 0; ++i)
      printf("%c %d\n", table[i], cnt[i]);
  }

  return 0;
}
