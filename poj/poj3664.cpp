#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 50000 + 5;
struct Cow {
  int a, b, id;
  bool operator<(Cow y) const {
    return a < y.a;
  }
} cows[MAXN];
bool cmp(const Cow &x, const Cow &y) {
  return x.b < y.b;
}

int main(void){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int n, k;
  cin >> n >> k;
  for(int i = 0; i < n; ++i) {
    cin >> cows[i].a >> cows[i].b;
    cows[i].id = i + 1;
  }
  sort(cows, cows+n);
  sort(cows+n-k, cows+n, cmp);
  cout << cows[n-1].id << endl;
  return 0;
}
