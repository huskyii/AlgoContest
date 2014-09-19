/*
ID: mail.ji1
PROG: friday
LANG: C++11
*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

inline bool is_leap(int year) {
  return (year%100 && !(year%4)) || !(year%400);
}

inline int day_of_Feb(int year) {
  if(is_leap(year)) return 29;
  else return 28;
}

int days[12] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int ans[7];

int main(void){
  int n;
  freopen("friday.in", "r", stdin);
  freopen("friday.out", "w", stdout);
  while(scanf("%d", &n) != EOF) {
    memset(ans, 0, sizeof(ans));

    int cur = 13;
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < 12; ++j) {
        //cout << "::1" << cur << endl;
        ++ans[cur%7];
        if(j != 1) cur = cur + days[j];
        else cur = cur + day_of_Feb(1900 + i);
      }
    }

    for(int i = 6; i < 13; ++i) {
      if(i-6) printf(" ");
      printf("%d", ans[i%7]);
    }
    printf("\n");
  }
  return 0;
}
