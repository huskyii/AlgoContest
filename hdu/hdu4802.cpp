#include <cstdio>
#include <map>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
  std::cin.tie(0);
  int n, c;
  string mark;
  map<string, double> table;
  table["A"] = 4.0;
  table["A-"] = 3.7;
  table["B+"] = 3.3;
  table["B"] = 3.0;
  table["B-"] = 2.7;
  table["C+"] = 2.3;
  table["C"] = 2.0;
  table["C-"] = 1.7;
  table["D"] = 1.3;
  table["D-"] = 1.0;
  table["F"] = 0;
  while(cin >> n) {
    double cs = 0;
    int cc = 0;
    for(int i = 0; i < n; ++i) {
      cin >> c >> mark;
      if(mark != "N" && mark != "P") {
        cc += c;
        cs += c*table[mark];
      }
    }
    double ans = cc == 0? 0: cs/cc;
    printf("%.2lf\n", ans);
  }
  return 0;
}
