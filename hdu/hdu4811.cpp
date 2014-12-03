#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int64;

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int xx[3], t[3][3][3];
  t[0][0][0]=0,t[0][0][1]=0,t[0][0][2]=1,t[0][1][1]=1,t[0][1][2]=3,t[0][2][2]=6;
 	t[1][1][1]=3,t[1][1][2]=6,t[1][2][2]=10,t[2][2][2]=15;
  while(cin >> xx[0] >> xx[1] >> xx[2]) {
    int64 score = 0, cnt = 0;
    for(int i = 0; i < 3; ++i)
      if(xx[i] > 2) { cnt += xx[i]-2; xx[i] = 2; }
    sort(xx, xx+3);
    score = cnt * (xx[0] + xx[1] + xx[2]) + t[xx[0]][xx[1]][xx[2]];
    cout << score << endl;
  }
  return 0;
}
