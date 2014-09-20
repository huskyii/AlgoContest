/*
ID: mail.ji1
PROG: beads
LANG: C++11
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 800;

// left[i][1]    blue
// left[i][0]    red
int left[MAXN][2], right[MAXN][2];
char s[MAXN], input[MAXN];

int main(void){
  freopen("beads.in", "r", stdin);
  freopen("beads.out", "w", stdout);
  int n;
  while(scanf("%d", &n) != EOF) {
    scanf("%s", input);
    strcpy(s, input);
    strcat(s, input);

    left[0][0] = left[0][1] = 0;
    for(int i = 1; i <= 2*n; ++i) {
      if(s[i-1] == 'r') {
        left[i][0] = left[i-1][0] + 1;
        left[i][1] = 0;
      } else if(s[i-1] == 'b') {
        left[i][1] = left[i-1][1] + 1;
        left[i][0] = 0;
      } else {
        left[i][0] = left[i-1][0] + 1;
        left[i][1] = left[i-1][1] + 1;
      }
    }

    right[2*n][0] = right[2*n][1] = 0;
    for(int i = 2*n-1; i >= 0; --i) {
      if(s[i] == 'r') {
        right[i][0] = right[i+1][0] + 1;
        right[i][1] = 0;
      } else if(s[i] == 'b') {
        right[i][1] = right[i+1][1] + 1;
        right[i][0] = 0;
      } else {
        right[i][0] = right[i+1][0] + 1;
        right[i][1] = right[i+1][1] + 1;
      }
    }

    int ans = 0;
    for(int i = 0; i <= 2*n; ++i)
      ans = max(ans, max(left[i][0], left[i][1]) + max(right[i][0], right[i][1]));
    ans = min(ans, n);
    printf("%d\n", ans);
  }
  return 0;
}
