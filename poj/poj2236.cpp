#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
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

const int MAXN = 1010;
double matrix[MAXN][MAXN];
int n, d;
struct Laptop {
  int x, y;
  bool repaired;
  Laptop(void): repaired(false) {}
  inline double distance(const Laptop &b) const {
    double dx = abs(x - b.x), dy = abs(y - b.y);
    return sqrt(dx*dx+dy*dy);
  }
};
Laptop lap[MAXN];

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  char op;
  int p, q;
  DisjointSet ss = DisjointSet(MAXN);
  cin >> n >> d;
  for(int i = 1; i <= n; ++i)
    cin >> lap[i].x >> lap[i].y;

  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j)
      matrix[i][j] = lap[i].distance(lap[j]);

  while(cin >> op) {
    if(op == 'O') {
      cin >> p;
      lap[p].repaired = true;
      for(int i = 1; i <= n; ++i)
        if(matrix[p][i] <= d && lap[i].repaired)
          ss.merge(p, i);
    } else {
      cin >> p >> q;
      if(ss.find(p) == ss.find(q))
        cout << "SUCCESS" << endl;
      else cout << "FAIL" << endl;
    }
  }

  return 0;
}
