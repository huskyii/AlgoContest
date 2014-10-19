// 用iostream TLE了，然后这样的用时是 1000ms（TL 就是1000ms）
// 这是闹哪样啊！！难道有比O(n^2)更高效的算法？
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int64;
const int MAXN = 10000 + 5;
int64 c[MAXN], y[MAXN];

int main(void){
  ios_base::sync_with_stdio(false);
  int n, s;
  scanf("%d %d", &n, &s);
  for(int i = 0; i < n; ++i)
    scanf("%lld %lld", c+i, y+i);

  int64 cost = c[0] * y[0];
  for(int i = 1; i < n; ++i) {
    int64 mincost = c[0] + i * s;
    for(int j = 1; j <= i; ++j) {
      mincost = min(c[j]+(i-j)*s, mincost);
    }
    cost += mincost * y[i];
  }
  cout << cost << endl;
  return 0;
}
