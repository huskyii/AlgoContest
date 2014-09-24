/*
ID: mail.ji1
PROG: sort3
LANG: C++11
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000 + 5;
int seq[MAXN];
int cnt[4];

inline int find(int l, int r, int x) {
  for(int i = l; i < r; ++i)
    if(seq[i] == x) return i;
  return -1;
}

int main(void) {
  freopen("sort3.in", "r", stdin);
  freopen("sort3.out", "w", stdout);

  int n;
  while(scanf("%d", &n) != EOF) {
    memset(seq, 0, sizeof(seq));
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n; ++i) { scanf("%d", seq+i); cnt[seq[i]]++; }

    int ans = 0;
    for(int i = 0; i < cnt[1]; ++i) {
      if(seq[i] == 1) continue;
      int x;
      if(seq[i] == 2)
        x = find(cnt[1], n, 1);
      if(seq[i] == 3) {
        x = find(cnt[1]+cnt[2], n, 1);
        if(x == -1) x = find(cnt[1], n , 1);
      }
      ++ans; swap(seq[i], seq[x]);
    }
    for(int i = cnt[1]; i < cnt[1]+cnt[2]; ++i) {
      if(seq[i] == 3) {
        int x = find(cnt[1]+cnt[2], n, 2);
        ++ans; swap(seq[i], seq[x]);
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}
