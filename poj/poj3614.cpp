#include <cstdio>
#include <utility>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int c, l;
typedef pair<int, int> pii;
const int MAXN = 2505;
pii cows[MAXN], ss[MAXN];

int main(void){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> c >> l;
  for(int i = 0; i < c; ++i)
    cin >> cows[i].second >> cows[i].first;
  for(int i = 0; i < l; ++i)
    cin >> ss[i].first >> ss[i].second;
  sort(cows, cows+c);
  sort(ss, ss+l);
  int cnt = 0;
  for(int i = 0; i < c; ++i)
    for(int j = 0; j < l; ++j) {
      if(cows[i].second <= ss[j].first &&
          ss[j].first <= cows[i].first &&
          ss[j].second > 0) {
        cnt++;
        ss[j].second--;
        break;
      } else if(ss[j].first > cows[i].first)
        break;
    }
  printf("%d\n", cnt);
  return 0;
}
