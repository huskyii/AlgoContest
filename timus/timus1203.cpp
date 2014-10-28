// 这题明明是贪心啊尼玛的，为何有一个dp的tag
#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
int n;
vector<pii> t;

int main(void){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int ts, te;
  while(cin >> n) {
    t.clear();
    t.push_back(make_pair(0,0));
    for(int i = 0; i < n; ++i) {
      cin >> ts >> te;
      t.push_back(make_pair(te+1, ts));
    }
    sort(t.begin(), t.end());

    int ans = 0, e = 0;
    for(int i = 1; i <= n; ++i) {
      if(e <= t[i].second) {
        e = t[i].first;
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
