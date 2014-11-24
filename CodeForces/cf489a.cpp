#include <vector>
#include <cstdio>
#include <utility>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 3000 + 5;
int a[MAXN], sorted[MAXN];
int n;

inline int find_(int s, int x) {
  for(int i = s+1; i < n; ++i)
    if(a[i] == x) return i;
  return -1;
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  while(cin >> n) {
    for(int i = 0; i < n; ++i)
      cin >> a[i];
    memcpy(sorted, a, n*sizeof(int));
    sort(sorted, sorted+n);
    vector< pair<int, int> > ans;
    for(int i = 0; i < n; ++i) {
      if(a[i] != sorted[i]) {
        int j = find_(i, sorted[i]);
        swap(a[i], a[j]);
        ans.push_back(make_pair(i, j));
      }
    }
    cout << ans.size() << endl;
    for(auto elem: ans)
      cout << elem.first << " " << elem.second << endl;
  }
  return 0;
}
