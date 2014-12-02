#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct DisjointSet {
  vector<int> father, rank;

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

struct Edge {
  int u, v, c;
  bool operator<(const Edge &e) const {
    return c < e.c;
  }
};

inline bool cmp(const Edge &e1, const Edge &e2) {
  return e1.c > e2.c;
}

Edge es[100000+10];
int fib[] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025};
const int LEN = 24;

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int n, m, T;
  cin >> T;
  for(int kase = 1; kase <= T; kase++) {
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
      cin >> es[i].u >> es[i].v >> es[i].c;
    sort(es, es+m);
    DisjointSet ds1 = DisjointSet(n+1);
    int min_ = 0;
    int cnt1 = 0;
    for(int i = 0; i < m; ++i) {
      if(ds1.find(es[i].u) != ds1.find(es[i].v)) {
        min_ += es[i].c;
        ds1.merge(es[i].u, es[i].v);
        if(++cnt1 >= n-1) break;
      }
    }
    sort(es, es+m, cmp);
    DisjointSet ds2 = DisjointSet(n+1);
    int max_ = 0;
    int cnt2 = 0;
    for(int i = 0; i < m; ++i) {
      if(ds2.find(es[i].u) != ds2.find(es[i].v)) {
        max_ += es[i].c;
        ds2.merge(es[i].u, es[i].v);
        if(++cnt2 >= n-1) break;
      }
    }
    string ans = "No";
    if(cnt2 == n-1)
      for(int i = 0; i < LEN; ++i) {
        if(min_ <= fib[i] && fib[i] <= max_)
          ans = "Yes";
      }
    cout << "Case #" << kase << ": " << ans << endl;
  }
  return 0;
}
