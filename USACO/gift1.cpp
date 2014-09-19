/*
ID: mail.ji1
PROG: gift1
LANG: C++11
*/
#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main(void){
  freopen("gift1.in", "r", stdin);
  freopen("gift1.out", "w", stdout);
  int np, m, ng;
  vector<string> name;
  string s;
  map<string, int> ans;
  cin >> np;
  //cout << np << endl;
  for(int i = 0; i < np; ++i) {
    cin >> s;
    name.push_back(s);
    ans[s] = 0;
  }
  while(cin >> s) {
    cin >> m >> ng;
    //cout << m << " " << ng << endl;
    if(ng > 0) ans[s] = ans[s] - (m/ng) * ng;
    for(int i = 0; i < ng; ++i) {
      cin >> s; ans[s] = ans[s] + m/ng;
    }
  }
  for(auto i : name) {
    cout << i << " " << ans[i] << endl;
    //cout << "sep\n";
  }
  return 0;
}
