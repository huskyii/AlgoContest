#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int table[] = { 16, 7, 8, 1, 1, 2, 3 };
bool v[7];
inline int power(char c) {
  v[c-'A'] = true;
  return table[c-'A'];
}
inline bool dec(void){
  if(v[1] && v[2])
    return false;
  return true;
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  char c;
  int T, n;
  cin >> T;
  while(T--) {
    int red = 0,  black = 0;
    memset(v, 0, sizeof(v));
    cin >> n;
    for(int i = 0; i < n; ++i) {
      cin >> c;
      red += power(c);
    }
    if(dec() && red > 1) red--;
    memset(v, 0, sizeof(v));
    cin >> n;
    for(int i = 0; i < n; ++i) {
      cin >> c;
      black += power(c);
    }
    if(dec() && black > 1) black--;
    if(red == black) cout << "tie\n";
    if(red > black) cout << "red\n";
    if(red < black) cout << "black\n";
  }
  return 0;
}
