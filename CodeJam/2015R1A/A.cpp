#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1005;
int m[MAXN];

int main(void) {
  int T, N;
  scanf("%d", &T);
  for(int kase = 1; kase <=T; kase++) {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
      scanf("%d", m+i);

    int x = 0, y = 0, max_gap = 0;
    for(int i = 0; i < N-1; ++i) {
      if(m[i] > m[i+1]) {
        x += m[i] - m[i+1];
        max_gap = max(max_gap, m[i] - m[i+1]);
      }
    }

    for(int i = 0; i < N-1; ++i) {
      if(m[i] < max_gap)
        y += m[i];
      else
        y += max_gap;
    }

    printf("Case #%d: %d %d\n", kase, x, y);
  }
}
