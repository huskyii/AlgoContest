/*
ID: mail.ji1
PROG: holstein
LANG: C++11
*/
#include <cstdio>
#include <vector>
using namespace std;

const int MAXV = 25;
int req[MAXV];
const int MAXG = 15;
int feed[MAXG][MAXV], path[MAXG];
int v, g;

inline bool check(const vector<int> &r) {
  for(int i = 0; i < v; ++i)
    if(r[i] > 0) return false;
  return true;
}

bool iddfs(int s, int cur, int d, vector<int> r) {
  //printf("%d\n", s);
  path[cur] = s;
  for(int i = 0; i < v; ++i)
    r[i] = r[i] - feed[s][i];
  if(check(r)) return true;
  if(d == 1) return false;
  for(int i = s+1; i <= g+1-d; ++i)
    if(iddfs(i, cur+1, d-1, r)) return true;
  return false;
}

inline void print_path(int d) {
  printf("%d", d);
  for(int i = 0; i < d; ++i)
    printf(" %d", path[i] + 1);
  printf("\n");
}

int main(void) {
  freopen("holstein.in", "r", stdin);
  freopen("holstein.out", "w", stdout);

  while(scanf("%d", &v) != EOF) {
    for(int i = 0; i < v; ++i) scanf("%d", req+i);
    scanf("%d", &g);
    for(int i = 0; i < g; ++i)
      for(int j = 0; j < v; ++j)
        scanf("%d", &feed[i][j]);

    for(int d = 1; d <= g; ++d) {
      bool flag = false;
      for(int i = 0; i < g+1-d; ++i) {
        vector<int> r(req, req+v);
        if(iddfs(i, 0, d, r)) { flag = true; break; }
      }
      if(flag) { print_path(d); break; }
    }
  }

  return 0;
}
