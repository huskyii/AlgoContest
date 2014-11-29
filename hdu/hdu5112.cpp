#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

struct Record {
  int t, x;
  Record(int t, int x): t(t), x(x){}
  bool operator<(const Record &r) const {
    return t < r.t;
  }
  inline double speed(const Record &r) {
    return (double)abs(r.x - x)/abs(r.t - t);
  }
};

int main(void) {
  int T, n, t, x;
  cin >> T;
  for(int kase = 1; kase <= T; ++kase) {
    vector<Record> rs;
    cin >> n;
    for(int i = 0; i < n; ++i) {
      cin >> t >> x;
      rs.push_back(Record(t, x));
    }
    sort(rs.begin(), rs.end());
    double ans = 0;
    for(int i = 1; i < n; ++i)
      ans = max(ans, rs[i].speed(rs[i-1]));
    printf("Case #%d: %.2lf\n", kase, ans);
  }
  return 0;
}
