#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 105;

int main(void){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int n, k, m, cube;
  cin >> m;
  while(m--) {
    priority_queue< int, vector<int>, greater<int> > pq[MAXN];
    bool flag = true;
    cin >> n >> k;
    for(int i = 0; i < n; ++i) {
      cin >> cube;
      pq[cube%k].push(cube);
    }
    for(int i = 1; i <= n; ++i) {
      if(pq[i%k].empty() || pq[i%k].top() > i) {
        flag = false;
        break;
      } else pq[i%k].pop();
    }
    if(flag) cout << "Jerry" << endl;
    else cout << "Tom" << endl;
  }
  return 0;
}
