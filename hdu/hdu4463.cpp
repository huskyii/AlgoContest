#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

struct edge {
  int u, v;
  double c;
  edge(int u, int v, double c): u(u), v(v), c(c) {}
  bool operator<(const edge &e) const {
    return c < e.c;
  }
};
struct DisjointSet {
  vector<int> father, rank;

  // n 是并查集中能容纳的最大元素个数
  DisjointSet(int n): father(n), rank(n) {
    for(int i = 0; i < n; i++) {
      father[i] = i;
    }
  }

  int find(int v) {
    int fv = father[v];
    while(fv != v) {
      v = fv;
      fv = father[v];
    }
    return v;
    //return father[v] = father[v] == v ? v: find(father[v]);
  }

  void merge(int x, int y) {
    int a = find(x), b = find(y);
    if(rank[a] < rank[b]) {
      father[a] = b;
    } else {
      father[b] = a;
      if(rank[a] == rank[b])
        ++rank[a];
    }
  }
};
const int MAXN = 100;
typedef pair<int, int> pt;
pt pts[MAXN];

inline double dist(int a, int b) {
  double x = pts[a].first - pts[b].first;
  double y = pts[a].second - pts[b].second;
  return sqrt(x*x + y*y);
}

int main(void) {
  std::cin.tie(0);
  int n, p, q;
  while(cin >> n && n) {
    cin >> p >> q;
    for(int i = 0; i < n; ++i)
      cin >> pts[i].first >> pts[i].second;
    vector<edge> es;
    for(int i = 0; i < n; ++i)
      for(int j = i+1; j < n; ++j)
        es.push_back(edge(i, j, dist(i, j)));
    sort(es.begin(), es.end());
    DisjointSet ds = DisjointSet(n);
    double ans = 0;
    ds.merge(p-1, q-1);
    ans += dist(p-1, q-1);
    for(size_t i = 0; i < es.size(); ++i) {
      if(ds.find(es[i].u) != ds.find(es[i].v)) {
        ds.merge(es[i].u, es[i].v);
        ans += es[i].c;
      }
    }
    printf("%.2lf\n", ans);
  }
  return 0;
}
