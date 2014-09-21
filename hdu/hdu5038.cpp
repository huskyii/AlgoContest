// 水題，Mode 是众數，英語不好害死人啊。。。
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int s[101];
bool v[201];

int main(void){
  int T, n, x;
  scanf("%d", &T);
  for(int kase = 1; kase <= T; ++kase) {
    scanf("%d", &n);
    memset(v, 0, sizeof(v));
    memset(s, 0, sizeof(s));
    for(int i = 0; i < n; ++i) { scanf("%d", &x); v[x] = true; s[x > 100? 200-x: x]++; }

    int max_cnt = 0;
    vector<int> idx;
    for(int i = 1; i <= 100; ++i) {
      if(max_cnt < s[i]) { max_cnt = s[i]; idx.clear(); idx.push_back(i); }
      else if(max_cnt == s[i]) {idx.push_back(i); }
    }

    bool flag = true;
    if(idx.size() > 1 && n%max_cnt == 0 && n/max_cnt == (int)idx.size()) flag = false;

    printf("Case #%d:\n", kase);
    if(!flag) printf("Bad Mushroom\n");
    else {
      for(size_t i = 0; i < idx.size(); ++i) {
        if(i) printf(" ");
        printf("%d", 10000 - (100 - idx[i]) * (100 - idx[i]));
      }
      printf("\n");
    }
  }
  return 0;
}
