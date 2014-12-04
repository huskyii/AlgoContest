#include <map>
#include <vector>
#include <cstdio>
#include <string>
#include <utility>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

struct outlaw {
  string name;
  int k;
  outlaw(string name, int k):name(name), k(k) {}
  bool operator<(const outlaw &o) const {
    if(k != o.k)
      return k > o.k;
    else
      return name < o.name;
  }
};

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int m, n, k;
  string name;
  while(cin >> n && n) {
    vector<outlaw> os;
    for(int i = 0; i < n; ++i) {
      cin >> name >> k;
      os.push_back(outlaw(name, k));
    }
    sort(os.begin(), os.end());
    map<string, pair<int, int> > table;
    int curk = 0, minor = 0;
    for(int i = 0; i < n; ++i) {
      cout << os[i].name << " " << os[i].k << endl;
      if(os[i].k == curk) minor++;
      else { curk = os[i].k; minor = 0; }
      table[os[i].name] = make_pair(i+1-minor, minor);
    }
    cin >> m;
    for(int i = 0; i < m; ++i) {
      cin >> name;
      cout << table[name].first;
      if(table[name].second)
        cout << " " << table[name].second + 1;
      cout << endl;
    }
  }
  return 0;
}
