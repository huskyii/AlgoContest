/****************************************/
/*          author: jiang.zhu           */
/*    email: mail.jiang.cn@gmail.com    */
/*         created on 2014-09-10        */
/****************************************/
#include <cstdio>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int a[35];

inline void flip(int p, int n) {
  for(int i = 0; i < p-i; i++)
    swap(a[i], a[p-i]);
  printf("%d ", n-p);
}

int main(void){
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);

  string input;
  while(getline(cin, input)) {
    cout << input << endl;
    stringstream in(input);
    int n = 0;
    while(in >> a[n]) n++;

    for(int i = n-1; i > 0; i--) {
      int p = max_element(a, a+i+1) - a;
      if(p == i) continue;
      if(p > 0) flip(p, n);
      flip(i, n);
    }
    printf("0\n");
  }
  return 0;
}
