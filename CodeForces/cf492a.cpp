#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXA = 120;

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int n;
  while(cin >> n)
  {
    int ans = 0;
    int cubes = 0;
    for(int i = 1; i < MAXA; ++i)
    {
      cubes += i*i + i;
      if(cubes <= 2*n)
      {
        ans = i;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
