#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

struct stick {
  int l, w;
  bool selected;
  stick(int l, int w): l(l), w(w), selected(false){}
  bool operator<(const stick &s) const {
    if(l < s.l) return true;
    else if(l > s.l) return false;
    else return w < s.w;
  }
};

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int T, n, l, w;
  cin >> T;
  while(T--) {
    vector<stick> ss;
    cin >> n;
    for(int i = 0; i < n; ++i) {
      cin >> l >> w;
      ss.push_back(stick(l, w));
    }
    sort(ss.begin(), ss.end());
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
      int cur = n;
      for(int j = 0; j < n; ++j)
        if(!ss[j].selected) { cur = j; break; }
      if(cur == n) break;
      ss[cur].selected = true;
      for(int j = 1; j < n; ++j) {
        if(!ss[j].selected &&
            ss[cur].l <= ss[j].l && ss[cur].w <= ss[j].w) {
          ss[j].selected = true;
          cur = j;
        }
      }
      cnt++;
    }
    cout << cnt << endl;
  }
  return 0;
}
