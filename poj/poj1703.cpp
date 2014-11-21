#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;
int r[MAXN];
int p[MAXN];

inline void init(int n) {
  memset(r, 0, sizeof(r));
  for(int i = 1; i <= n; ++i)
    p[i] = i;
}

inline int find(int x) {
  if(x == p[x]) return x;
  // order is important!!!!
  int t = p[x];
  p[x] = find(p[x]);
  r[x] = (r[x] + r[t])%2;
  return p[x];
}

inline void unite(int x, int y) {
  int rx = find(x);
  int ry = find(y);
  p[rx] = ry;
  r[rx] = (r[x]+r[y]+1)%2;
}

int main(void) {
  int n, t, m;
  scanf("%d", &t);
  while(t--) {
    int a, b;
    char op;
    scanf("%d%d%*c", &n, &m);
    init(n);
    while(m--) {
      scanf("%c%d%d%*c", &op, &a, &b);
      if(op == 'A') {
        if(find(a) == find(b)) {
          if(r[a] == r[b])
            printf("In the same gang.\n");
          else printf("In different gangs.\n");
        } else {
          printf("Not sure yet.\n");
        }
      } else if(op == 'D') {
        unite(a, b);
      }
    }
  }
  return 0;
}
