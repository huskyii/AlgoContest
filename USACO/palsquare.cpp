/*
ID: mail.ji1
PROG: palsquare
LANG: C++11
*/
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

char table[20] = {
  '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'
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
  ios_base::sync_with_stdio(false);
  freopen("palsquare.in", "r", stdin);
  freopen("palsquare.out", "w", stdout);

  string s;
  while(scanf("%d", &base) != EOF) {
    for(int i = 1; i <= 300; ++i) {
      s = transform(i*i);
      if(is_palindrome(s))
        cout << transform(i) << " " << s << endl;
    }
  }

  return 0;
}
