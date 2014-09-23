/*
ID: mail.ji1
PROG: barn1
LANG: C++11
*/
#include <cstdio>
#include <algorithm>
using namespace std;

struct Interval {
  int start, end;
  int length;
  Interval(): start(0), end(0), length(0) {}
  void set(int _start, int _end) {
    start = _start;
    end = _end;
    length = end - start - 1;
  }

  bool operator<(const Interval &b) const {
    return length > b.length;
  }
};

const int MAXN = 200 + 5;
Interval inter[MAXN];
int tmp[MAXN];

int main(void) {
  freopen("barn1.in", "r", stdin);
  freopen("barn1.out", "w", stdout);

  int m, s, c;
  while(scanf("%d %d %d", &m, &s, &c) != EOF) {
    for(int i = 0; i < c; ++i)
      scanf("%d", tmp+i);
    sort(tmp, tmp+c);
    for(int i = 0; i < c-1; ++i)
      inter[i].set(tmp[i], tmp[i+1]);

    sort(inter, inter+c);
    int ans = 0;
    for(int i = 0; i < m-1; ++i)
      ans = ans + inter[i].length;
    ans = ans + tmp[0] - 1;
    ans = ans + s - tmp[c-1];
    ans = s - ans;
    printf("%d\n", ans);
  }

  return 0;
}
