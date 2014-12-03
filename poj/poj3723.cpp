// 用pq会导致TLE－－坑爹的POJ
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

struct edge {
  int u, v, c;
  edge(int u, int v, int c): u(u), v(v), c(c) {}
  bool operator<(const edge &e) const {
    return c > e.c;
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

int main(void) {
  int T, n, m, r;
  cin >> T;
  while(T--) {
    vector<edge> vec;
    int u, v, c;
    scanf("%d %d %d", &n, &m, &r);
    for(int i = 0; i < r; ++i) {
      scanf("%d %d %d", &u, &v, &c);
      vec.push_back(edge(u, v+n, c));
    }
    sort(vec.begin(), vec.end());
    DisjointSet ds = DisjointSet(n+m);
    int ans = 0;
    for(int i = 0; i < r; ++i) {
      if(ds.find(vec[i].u) != ds.find(vec[i].v)) {
        ans += vec[i].c;
        ds.merge(vec[i].u, vec[i].v);
      }
    }
    printf("%d\n", (10000*(n+m) - ans));
  }
  return 0;
}
