/*
ID: mail.ji1
PROG: runround
LANG: C++11
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int num[10];
bool v[10];

inline int convert(int x) {
  int cur = 0;
  while(x > 0) {
    num[cur++] = x%10;
    x = x / 10;
  }
  reverse(num, num + cur);
  return cur;
}

inline bool check(int x) {
  memset(v, 0, sizeof(v));
  memset(num, 0, sizeof(num));
  int len = convert(x);
  int cur = num[0], pos = 0;
  //if(x == 134259) printf("11\n");
  for(int i = 0; i < len; ++i) {
    if(cur == 0 || v[cur]) return false;
    v[cur] = true;
    //if(x == 134259)printf("%d %d\n", cur, pos);
    pos = (pos+cur)%len;
    cur = num[pos];
  }
  if(pos == 0) return true;
  else return false;
}

int main(void) {
  freopen("runround.in", "r", stdin);
  freopen("runround.out", "w", stdout);

  int m;
  while(scanf("%d", &m) != EOF) {
    while(!check(++m)) ;
    printf("%d\n", m);
  }

  return 0;
}
