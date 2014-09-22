/*
ID: mail.ji1
PROG: namenum
LANG: C++11
*/
#include <set>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

int size;
char num[13], str[13];
char table[8][3] = {
  {'A', 'B', 'C'},
  {'D', 'E', 'F'},
  {'G', 'H', 'I'},
  {'J', 'K', 'L'},
  {'M', 'N', 'O'},
  {'P', 'R', 'S'},
  {'T', 'U', 'V'},
  {'W', 'X', 'Y'}
};
set<string> dict;

vector<string> ans;
void solve(int i, int j) {
  str[i] = table[(size_t)num[i]-'2'][j];
  if(i == size-1) {
    string s(str, size);
    if(dict.find(s) != dict.end()) ans.push_back(s);
  } else {
    for(int k = 0; k < 3; ++k) solve(i+1, k);
  }
}

int main(void) {
  ios_base::sync_with_stdio(false);
  freopen("dict.txt", "r", stdin);
  string s;
  while(cin >> s) dict.insert(s);

  freopen("namenum.in", "r", stdin);
  freopen("namenum.out", "w", stdout);

  while(scanf("%s", num) != EOF) {
    ans.clear();
    size = strlen(num);

    for(int j = 0; j < 3; ++j) solve(0, j);

    if(ans.empty()) cout << "NONE" << endl;
    else for(auto it : ans) cout << it << endl;
  }

  return 0;
}
