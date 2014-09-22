/*
ID: mail.ji1
PROG: dualpal
LANG: C++11
*/
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

char table[10] = {
  '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
};

int base;
string transform(int num) {
  vector<char> tmp;
  while(num) {
    tmp.push_back(table[num%base]);
    num = num / base;
  }
  reverse(tmp.begin(), tmp.end());
  string ans(tmp.begin(), tmp.end());
  return ans;
}

inline bool is_palindrome(const string &str) {
  int size = (int)str.size();
  for(int i = 0; i < size/2; ++i)
    if(str[i] != str[size-1-i]) return false;
  return true;
}

int main(void) {
  freopen("dualpal.in", "r", stdin);
  freopen("dualpal.out", "w", stdout);

  int n, s;
  while(scanf("%d %d", &n, &s) != EOF) {
    for(int i = 1; n > 0; ++i) {
      int cnt = 0;
      for(base = 2; base <= 10; ++base) {
        string str = transform(s+i);
        if(is_palindrome(str)) { ++cnt; if(cnt == 2) break;}
      }
      if(cnt == 2) { cout << s+i << endl; --n; }
    }
  }

  return 0;
}

