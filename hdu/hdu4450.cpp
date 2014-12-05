#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int n, a;
  while(cin >> n && n) {
    int sum = 0;
    for(int i = 0; i < n; ++i) {
      cin >> a;
      sum += a*a;
    }
    cout << sum << endl;
  }
  return 0;
}
