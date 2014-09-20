/*
ID: mail.ji1
PROG: beads
LANG: C++11
*/
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 350 + 5;
char necklace[MAXN];
char h[256];
int n;

inline int compute(int pos, int dir) {
  int ans = 0;
  size_t cur = (size_t)necklace[pos];
  for(int i = 0; i < n; ++i) {
    //cout << necklace[(n+pos+i*dir)%n];
    if(cur != (size_t)'w') {
      if(necklace[(n+pos+i*dir)%n] == h[cur]) break;
      else ++ans;
    } else {
      if(cur != (size_t)necklace[(n+pos+i*dir)%n]) { cur = necklace[(n+pos+i*dir)%n]; }
      ++ans;
    }
  }
  //cout << endl;
  //cout << pos << " " << ans << endl;
  return ans;
}

int main(void){
  freopen("beads.in", "r", stdin);
  freopen("beads.out", "w", stdout);
  h[(size_t)'r'] = 'b';
  h[(size_t)'b'] = 'r';
  while(scanf("%d", &n) != EOF) {
    scanf("%s", necklace);

    int ans = 0;
    for(int pos = 0; pos < n; ++pos)
      if(necklace[pos] != necklace[(n+pos-1)%n])
        ans = max(ans, compute(pos, 1) + compute((n+pos-1)%n, -1));
    ans = ans > 0? min(ans, n): n;
    printf("%d\n", ans);
  }
  return 0;
}
