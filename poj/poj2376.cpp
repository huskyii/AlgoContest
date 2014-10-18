#include <cstdio>
#include <utility>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;
const int MAXN = 25000;
p times[MAXN];

int main(void){
  int n, t;
  cin >> n >> t;
  for(int i = 0; i < n; ++i)
    cin >> times[i].first >> times[i].second;
  sort(times, times + n);

  int start = 1, cnt = 0;
  for(int i = 0; i < n; ++i) {
    if(start > t) break;
    cnt++;
    bool flag = false;
    int next_start = 0;
    while(times[i].first <= start) {
      next_start = max(next_start, times[i].second+1);
      ++i;
      flag = true;
    }
    if(flag) {
      start = next_start;
      --i;
    }
    else
      break;
  }
  if(start > t)
    cout << cnt << endl;
  else
    cout << -1 << endl;
  return 0;
}
