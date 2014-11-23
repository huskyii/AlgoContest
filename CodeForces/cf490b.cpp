#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 200000 + 10;
int q[MAXN], n, a, b;

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  map<int, int> mf, mb;
  set<int> s;
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> a >> b;
    mf[a] = b;
    mb[b] = a;
    if(s.find(a) != s.end()) s.erase(a);
    else s.insert(a);
    if(s.find(b) != s.end()) s.erase(b);
    else s.insert(b);
  }
  int cur;
  if(n%2 == 0) {
    cur = 0;
    for(int i = 0; i <= n; i += 2) {
      q[i] = cur;
      cur = mf[cur];
    }
    cur = 0;
    for(int i = n+1; i > 0; i -= 2) {
      q[i] = cur;
      cur = mb[cur];
    }
  } else {
    for(auto x: s)
      if(x && mb.find(x) != mb.end()) cur = x;
    for(int i = n; i > 0; i-=2) {
      q[i] = cur;
      cur = mb[cur];
    }
    cur = 0;
    for(int i = 0; i <= n; i+=2) {
      q[i] = cur;
      cur = mf[cur];
    }
  }
  for(int i = 1; i <= n; ++i)
    cout << q[i] << " ";
  cout << endl;
  return 0;
}
