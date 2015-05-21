#include <set>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 2e5 + 10;
char s[maxn], t[maxn];
int pos[26][26];
int arr[26];

inline int ord(char c) {
  return (int)(c-'a');
}

int main(void) {
  int n;
  while(scanf("%d", &n) != EOF) {
    getchar();
    fgets(s+1, maxn, stdin);
    fgets(t+1, maxn, stdin);
    memset(pos, 0, 26*26);
    memset(arr, 0, 26);

    int dis = 0, x = -1, y = -1, r = 0;

    for(int i = 1; i <= n; ++i) {
      if(s[i] != t[i]) {
        pos[ord(s[i])][ord(t[i])] = i;
        arr[ord(s[i])] = i;
        dis++;
      }
    }

    for(int i = 0; i < 26; ++i) {
      for(int j = 0; j < 26; ++j) {
        if(pos[i][j] != 0 && pos[j][i] != 0) {
          x = pos[i][j]; y = pos[j][i];
          r = 2;
          goto END;
        }
      }
    }

    for(int i = 0; i < 26; ++i) {
      for(int j = 0; j < 26; ++j) {
        if(pos[i][j] != 0 && arr[j] != 0) {
          x = pos[i][j]; y = arr[j];
          r = 1;
          goto END;
        }
      }
    }

  END:
    printf("%d\n%d %d\n", dis-r, x, y);
  }
  return 0;
}
