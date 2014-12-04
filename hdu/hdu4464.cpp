#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

char url[1000];

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int kase = 0, n;
  while(cin >> n) {
    int ans = 0;
    for(int i = 0; i < n; ++i) {
      cin >> url;
      int score = 0;
      for(size_t j = 0; j < strlen(url); ++j)
        score += (int)url[j];
      ans = max(ans, score);
    }
    cout << "Case " << ++kase << ": " << ans << endl;
  }
  return 0;
}
