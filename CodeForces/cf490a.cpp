#include <set>
#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 5005;
int t, cnt[4], xx[4][MAXN], n;

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  while(cin >> n) {
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i <= n; ++i) {
      cin >> t;
      xx[t][cnt[t]] = i;
      cnt[t]++;
    }
    int w = min(cnt[1], cnt[2]);
    w = min(w, cnt[3]);
    cout << w << endl;
    for(int i = 0; i < w; ++i)
      cout << xx[1][i] << " " << xx[2][i] << " " << xx[3][i] << endl;
  }
  return 0;
}
