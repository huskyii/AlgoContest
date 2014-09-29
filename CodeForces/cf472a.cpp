#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000000 + 5;

bool v[MAXN];
int n;

void foo() {
  memset(v, 0, sizeof(v));
  int m = sqrt(n + 0.5);
  for(int i = 2; i <= m; ++i) if(!v[i])
    for(int j = i*i; j <= n; j += i) v[j] = true;
}

int main(void){
  scanf("%d", &n);
  foo();
  for(int i = 4; i <= n/2; ++i) {
    //printf("%d %d %d\n",i, v[i], v[n-i]);
    if(v[i] && v[n-i]) { printf("%d %d\n", i, n-i); break;}
  }
  return 0;
}
