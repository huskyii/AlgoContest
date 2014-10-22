#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 20000 + 5;
int cows[MAXN];

int main(void){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int n, s;
  cin >> n >> s;
  for(int i = 0; i < n; ++i)
    cin >> cows[i];
  int ans = 0;
  sort(cows, cows+n);
  for(int i = 0; cows[i] < s/2; ++i)
    ans += upper_bound(cows+i, cows+n, s-cows[i]) - (cows+i+1);
  cout << ans << endl;
  return 0;
}
