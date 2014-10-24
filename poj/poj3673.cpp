#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

char a[20], b[20];
int table[256];

int main(void){
  for(int i = '0'; i <= '9'; ++i)
    table[i] = i - '0';
  scanf("%s %s", a, b);
  int ans = 0;
  for(size_t i = 0; i < strlen(a); ++i)
    for(size_t j = 0; j < strlen(b); ++j)
      ans += table[a[i]] * table[b[j]];
  printf("%d\n", ans);
  return 0;
}
