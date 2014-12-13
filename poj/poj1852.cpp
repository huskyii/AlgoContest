#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int T, l, n, pos;
  cin >> T;
  while(T--) {
    cin >> l >> n;
    int mint = 0, maxt = 0;
    for(int i = 0; i < n; ++i) {
      cin >> pos;
      if(l-pos > pos) {
        mint = max(pos, mint);
        maxt = max(l-pos, maxt);
      } else {
        maxt = max(pos, maxt);
        mint = max(l-pos, mint);
      }
    }
    cout << mint << " " << maxt << endl;
  }
  return 0;
}
