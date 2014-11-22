#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
const int MAXN = 105;
int a[MAXN];
typedef pair<int, int> PII;

inline int max_(void) {
  int pos = 1;
  for(int i = 1; i <= n; ++i)
    if(a[i] > a[pos]) pos = i;
  return pos;
}

inline int min_(void) {
  int pos = 1;
  for(int i = 1; i <= n; ++i)
    if(a[i] < a[pos]) pos = i;
  return pos;
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  while(cin >> n >> k) {
  memset(a, 0, sizeof(a));
  for(int i = 1; i <= n; ++i)
    cin >> a[i];

  int s = 0;
  vector<PII> ans;
  while(s < k) {
    int minp = min_();
    int maxp = max_();
    if(a[maxp] - a[minp] == 0) break;
    a[maxp]--;
    a[minp]++;
    ans.push_back(make_pair(maxp, minp));
    s++;
  }

  cout << (a[max_()] - a[min_()]) << " " << s << endl;
  for(auto elem: ans)
    cout << elem.first << " " << elem.second << endl;
  }
  return 0;
}
