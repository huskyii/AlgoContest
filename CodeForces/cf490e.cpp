#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  string cur, pre;
  vector<string> ans;
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> cur;
    if(cur.size() > pre.size()) {
      if(cur[0] == '?') cur[0] = '1';
      for(size_t i = 1; i < cur.size(); ++i)
        if(cur[i] == '?') cur[i] = '0';
    }
    if(cur.size() == pre.size()) {
      int split = cur.size();
      for(size_t pos = 0; pos < cur.size(); ++pos) {
        if(cur[pos] != '?' && cur[pos] != pre[pos]) {
          split = pos; break;
        }
      }
      for(size_t i = split; i < cur.size(); ++i)
        if(cur[i] == '?') cur[i] = '0';
      if(cur[split] > pre[split]) {
        for(int i = 0; i < split; ++i)
          if(cur[i] == '?') cur[i] = pre[i];
      } else {
        bool flag = false;
        for(int i = split; i >= 0; --i)
          if(cur[i] == '?') {
            if(!flag) {
              if(pre[i] == '9') cur[i] = '0';
              else { cur[i] = pre[i]+1; flag = true; }
            } else { cur[i] = pre[i]; }
          }
      }
      if(cur <= pre) {
        cout << "NO" << endl;
        return 0;
      }
    }
    if(cur.size() < pre.size()) {
      cout << "NO" << endl;
      return 0;
    }
    ans.push_back(cur);
    pre = cur;
  }
  cout << "YES\n";
  for(auto elem: ans)
    cout << elem << endl;
  return 0;
}
