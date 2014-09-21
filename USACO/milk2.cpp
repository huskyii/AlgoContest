/*
ID: mail.ji1
PROG: milk2
LANG: C++11
*/
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

const int MAXN = 5000 + 5;
pair<int, int> t[MAXN];

int main(void) {
  freopen("milk2.in", "r", stdin);
  freopen("milk2.out", "w", stdout);

  int n;
  while(scanf("%d", &n) != EOF) {
    for(int i = 0; i < n; ++i)
      scanf("%d %d", &t[i].first, &t[i].second);

    sort(t, t+n);
    int idle = 0, maxt = 0;
    int cur_start = t[0].first, cur_end = t[0].second;
    for(int i = 1; i < n; ++i) {
      if(cur_end >= t[i].first) cur_end = max(cur_end, t[i].second);
      else {
        idle = max(idle, t[i].first - cur_end);
        maxt = max(maxt, cur_end - cur_start);
        cur_start = t[i].first;
        cur_end = t[i].second;
      }
    }
    maxt = max(maxt, cur_end - cur_start);
    printf("%d %d\n", maxt, idle);
  }

  return 0;
}
