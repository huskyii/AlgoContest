#include <queue>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int64;

int main(void){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int n, a;
  double ans;
  while(cin >> n) {
    priority_queue<int> pq;
    for(int i = 0; i < n; ++i) {
      cin >> a;
      pq.push(a);
      if(i > n/2) pq.pop();
    }
    ans = pq.top();
    pq.pop();
    if(n%2 == 0)
      ans = (ans + pq.top())/2;
    cout << setprecision(1) << fixed << ans << endl;
  }
  return 0;
}
