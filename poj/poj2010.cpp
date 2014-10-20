#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
typedef long long int64;
int64 f;
int n, c;

struct cow {
  int csat, aid;
};
cow cows[MAXN], tmp[MAXN];
int64 lo[MAXN], hi[MAXN];

void compute_lo() {
  int64 tot = 0;
  priority_queue<int> pq;
  for(int i = 0; i < n/2; ++i) {
    tot += cows[i].aid;
    pq.push(cows[i].aid);
  }
  for(int i = n/2; i < c - n/2; ++i) {
    lo[i] = tot;
    pq.push(cows[i].aid);
    tot -= pq.top() - cows[i].aid;
    pq.pop();
  }
}
void compute_hi() {
  int64 tot = 0;
  priority_queue<int> pq;
  for(int i = c-1; i >= c - n/2; --i) {
    tot += cows[i].aid;
    pq.push(cows[i].aid);
  }
  for(int i = c - 1 - n/2; i >= n/2; --i) {
    hi[i] = tot;
    pq.push(cows[i].aid);
    tot -= pq.top() - cows[i].aid;
    pq.pop();
  }
}

bool cmp(const cow &a, const cow &b) {
  return a.csat < b.csat;
}

int main(void){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> n >> c >> f;
  for(int i = 0; i < c; ++i) {
    cin >> cows[i].csat >> cows[i].aid;
  }
  sort(cows, cows+c, cmp);
  compute_lo();
  compute_hi();

  int ans = -1;
  for(int i = c - 1 - n/2; i >= n/2; --i) {
    if(lo[i] + hi[i] + cows[i].aid <= f) {
      ans = cows[i].csat;
      break;
    }
  }
  printf("%d\n", ans);

  return 0;
}

