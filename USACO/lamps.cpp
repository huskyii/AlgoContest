/*
ID: mail.ji1
PROG: lamps
LANG: C++11
*/
#include <set>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

set< vector<int> > s;
int state[1<<4][101], on[101], off[101];
int n, c, tmp;
vector<int> v;

inline void foo1(int x) {
  for(int i = 1; i <= n; ++i)
    state[x][i] = !state[x][i];
}

inline void foo2(int x) {
  for(int i = 1; i <= n; ++i)
    if(i%2 == 0) state[x][i] = !state[x][i];
}

inline void foo3(int x) {
  for(int i = 1; i <= n; ++i)
    if(i%2) state[x][i] = !state[x][i];
}

inline void foo4(int x) {
  for(int i = 1; i <= n; i = i + 3)
    state[x][i] = !state[x][i];
}

inline void ernumerate() {
  for(int i = 0; i < (1<<4); ++i) {
    if(i & 1) foo1(i);
    if(i & 2) foo2(i);
    if(i & 4) foo3(i);
    if(i & 8) foo4(i);
  }
}

inline bool check(int on_pos, int off_pos, int x) {
  for(int i = 0; i < on_pos; ++i)
    if(state[x][on[i]] == 1) return false;
  for(int i = 0; i < off_pos; ++i)
    if(state[x][off[i]] == 0) return false;
  return true;
}

inline void print(const vector<int> q) {
  for(int i = 1; i <= n; ++i)
    if(q[i]) printf("0");
    else printf("1");
  printf("\n");
}

inline bool equal(int i, int j) {
  if(memcmp(state[i], state[j], sizeof(int)*n) == 0)
    return true;
  return false;
}

inline bool visited(int x) {
  for(auto i: v)
    if(equal(i, x)) return true;
  return false;
}

inline bool cmp(int *a, int *b) {
  for(int i = 1; i <= n; ++i) {
    if(a[i] < b[i]) return true;
    if(a[i] > b[i]) return false;
  }
  return false;
}

int main(void) {
  freopen("lamps.in", "r", stdin);
  freopen("lamps.out", "w", stdout);

  while(scanf("%d", &n) != EOF) {
    memset(state, 0, sizeof(state));
    ernumerate();
    scanf("%d", &c);
    int on_pos = 0;
    while(scanf("%d", &tmp) && tmp != -1) {
      on[on_pos++] = tmp;
    }
    int off_pos = 0;
    while(scanf("%d", &tmp) && tmp != -1) {
      off[off_pos++] = tmp;
    }

    bool flag = false;
    v.clear();
    s.clear();
    int cur = 0;
    for(int i = 0; i < (1<<4); ++i) {
      if(c >= __builtin_popcount(i) &&
          check(on_pos, off_pos, i) &&
          !visited(i)) {
        vector<int> aa(state[i], state[i]+n+1);
        s.insert(aa);
        flag = true; v.push_back(i);
      }
    }
    for(set< vector<int> >::reverse_iterator it = s.rbegin(); it != s.rend(); it++)
      print(*it);
    if(!flag) printf("IMPOSSIBLE\n");
  }

  return 0;
}
