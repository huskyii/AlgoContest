/*
ID: mail.ji1
PROG: zerosum
LANG: C++11
*/
#include <cstdio>
using namespace std;

int n;
char s[20] = "1 2 3 4 5 6 7 8 9";

bool check() {
  int sum = 0, cur = 0, sign = 1;
  for(int i = 0; i < 2*n-1; ++i) {
    switch(s[i]) {
      case ' ': break;
      case '+':
      case '-':
        sum += sign * cur;
        sign = s[i] == '+'? 1 : -1;
        cur = 0;
        break;
      default:
        cur = cur * 10 + s[i] - '0';
    }
  }
  sum += sign * cur;
  return !sum;
}

void dfs(int cur) {
  if(check()) {
    for(int i = 0; i <= 2*(n-1); ++i)
      printf("%c", s[i]);
    printf("\n");
    return ;
  }
  if(cur > 2*n) return ;
  dfs(cur+2);
  s[cur] = '+';
  dfs(cur+2);
  s[cur] = '-';
  dfs(cur+2);
  s[cur] = ' ';
}

int main(void) {
  freopen("zerosum.in", "r", stdin);
  freopen("zerosum.out", "w", stdout);

  while(scanf("%d", &n) != EOF) {
    dfs(1);
  }

  return 0;
}
